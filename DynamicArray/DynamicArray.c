#include "DynamicArray.h"

DynamicArray* DynamicArray_create(size_t data_size, size_t capacity, double growth_factor,
    int (*compare)(void* data1, void* data2));
void DynamicArray_destroy(DynamicArray* DA);

static inline void* data_at(DynamicArray* DA, size_t index);

void* DynamicArray_front(DynamicArray* DA);
void* DynamicArray_back(DynamicArray* DA);
void* DynamicArray_at(DynamicArray* DA, size_t index);

int DynamicArray_push_front(DynamicArray* DA, void* data);
int DynamicArray_push_back(DynamicArray* DA, void* data);
int DynamicArray_insert(DynamicArray* DA, size_t index, void* data);
int DynamicArray_sorted_insert(DynamicArray* DA, void* data);
int DynamicArray_pop_front(DynamicArray* DA);
int DynamicArray_pop_back(DynamicArray* DA);
int DynamicArray_remove(DynamicArray* DA, void* data);
int DynamicArray_erase(DynamicArray* DA, size_t index);

size_t DynamicArray_search(DynamicArray* DA, void* data);

DynamicArray* DynamicArray_create(size_t data_size, size_t capacity, double growth_factor,
    int (*compare)(void* data1, void* data2))
{
    if((size_t)(capacity * growth_factor) <= capacity) {
        return NULL;
    }
    DynamicArray* DA = malloc(sizeof (DynamicArray));
    if(!DA) {
        return NULL;
    }
    DA->array = malloc(data_size * capacity);
    if(!DA->array) {
        free(DA);
        DA = NULL;
        return NULL;
    }
    DA->data_size = data_size;
    DA->front = 0;
    DA->back = 0;
    DA->capacity = capacity;
    DA->growth_factor = growth_factor;
    DA->compare = compare;
    DA->size = 0;
    return DA;
}

void DynamicArray_destroy(DynamicArray* DA)
{
    free(DA->array);
    DA->array = NULL;
    DA->size = 0;
    free(DA);
    DA = NULL;
}

static inline void* data_at(DynamicArray* DA, size_t index)
{
    return (char*)DA->array + (DA->data_size * index);
}

void* DynamicArray_front(DynamicArray* DA)
{
    return data_at(DA, DA->front);
}

void* DynamicArray_back(DynamicArray* DA)
{
    return data_at(DA, DA->back - 1);
}

void* DynamicArray_at(DynamicArray* DA, size_t index)
{
    return data_at(DA, DA->front + index);
}

int DynamicArray_change_capacity(DynamicArray* DA, size_t capacity)
{
    char* array = realloc(DA->array, DA->data_size * DA->capacity);
    if(!array) {
        return 0;
    }
    DA->array = array;
    DA->capacity = capacity;
    return 1;
}

int DynamicArray_push_front(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity &&
        !DynamicArray_change_capacity(DA, DA->capacity * DA->growth_factor)) {
            return 0;
    }
    if(DA->front) {
        if(DA->back == DA->capacity) {
            memmove(data_at(DA, 1), data_at(DA, DA->front),
                DA->data_size * DA->size);
            DA->front = 0;
            DA->back = DA->size;
        }
        else {
            DA->front = DA->front - 1;
        }
    }
    else {
        memmove(data_at(DA, 1), data_at(DA, DA->front),
            DA->data_size * DA->size);
    }
    memcpy(data_at(DA, DA->front), data, DA->data_size);
    DA->size = DA->size + 1;
    return 1;
}

int DynamicArray_push_back(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity &&
        !DynamicArray_change_capacity(DA, DA->capacity * DA->growth_factor)) {
            return 0;
    }
    if(DA->back == DA->capacity) {
        memmove(data_at(DA, 0), data_at(DA, DA->front),
            DA->data_size * DA->size);
        DA->front = 0;
        DA->back = DA->size;
    }
    memcpy(data_at(DA, DA->back), data, DA->data_size);
    DA->back = DA->back + 1;
    DA->size = DA->size + 1;
    return 1;
}

int DynamicArray_insert(DynamicArray* DA, size_t index, void* data)
{
    if(index > DA->size) {
        return 0;
    }
    if(DA->size == DA->capacity &&
        !DynamicArray_change_capacity(DA, DA->capacity * DA->growth_factor)) {
            return 0;
    }
    memmove(data_at(DA, DA->front + index + 1), data_at(DA, DA->front + index),
        DA->data_size * (DA->size - index - 1));
    memcpy(data_at(DA, DA->front + index), data, DA->data_size);
    DA->size = DA->size + 1;
    return 1;
}

int DynamicArray_sorted_insert(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity &&
        !DynamicArray_change_capacity(DA, DA->capacity * DA->growth_factor)) {
            return 0;
    }
    size_t i;
    for(i = 0; i < DA->size; i++) {
        if(DA->compare(data, data_at(DA, DA->front + i)) <= 0) {
            memmove(data_at(DA, DA->front + i + 1), data_at(DA, DA->front + i),
                DA->data_size * (DA->size - i - 1));
            memcpy(data_at(DA, DA->front + i), data, DA->data_size);
            DA->size = DA->size + 1;
            return 1;
        }
    }
    memcpy(data_at(DA, DA->front + i + 1), data, DA->data_size);
    DA->size = DA->size + 1;
    return 1;
}

int DynamicArray_pop_front(DynamicArray* DA)
{
    if(DA->size == DA->capacity / DA->growth_factor &&
        !DynamicArray_change_capacity(DA, DA->capacity / DA->growth_factor)) {
            return 0;
    }
    DA->front = DA->front + 1;
    DA->size = DA->size - 1;
    return 1;
}

int DynamicArray_pop_back(DynamicArray* DA)
{
    if(DA->size == DA->capacity / DA->growth_factor &&
        !DynamicArray_change_capacity(DA, DA->capacity / DA->growth_factor)) {
            return 0;
    }
    DA->back = DA->back - 1;
    DA->size = DA->size - 1;
    return 1;
}

int DynamicArray_erase(DynamicArray* DA, size_t index)
{
    if(index >= DA->size) {
        return 0;
    }
    if(DA->size == DA->capacity / DA->growth_factor &&
        !DynamicArray_change_capacity(DA, DA->capacity / DA->growth_factor)) {
            return 0;
    }
    memmove(data_at(DA, DA->front + index),
        data_at(DA, DA->front + index + 1),
        DA->data_size * (DA->size - index + 1));
    DA->back = DA->back - 1;
    DA->size = DA->size - 1;
    return 1;
}

int DynamicArray_remove(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity / DA->growth_factor &&
        !DynamicArray_change_capacity(DA, DA->capacity / DA->growth_factor)) {
            return 0;
    }
    for(size_t i = 0; i < DA->size; i++) {
        if(!DA->compare(data, data_at(DA, DA->front + i))) {
            memmove(data_at(DA, DA->front + i), data_at(DA, DA->front + i + 1),
                DA->data_size * (DA->size - i + 1));
            DA->size = DA->size - 1;
            return 1;
        }
    }
    return 0;
}

// size_t DynamicArray_search(DynamicArray* DA, void* data)
// {

// }
