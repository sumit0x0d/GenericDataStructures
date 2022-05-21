#include "DynamicArray2.h"

DynamicArray* DynamicArray_create(size_t data_size, size_t capacity, double growth_factor,
    int (*compare)(void* data1, void* data2));
void DynamicArray_destroy(DynamicArray* DA);

inline void* DynamicArray_front(DynamicArray* DA);
inline void* DynamicArray_back(DynamicArray* DA);
inline void* DynamicArray_at(DynamicArray* DA, size_t index);

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
    for(size_t i = 0; i < capacity; i++) {
        DA->array[i].data = malloc(data_size);
        if(!DA->array[i].data) {
            for(size_t j = i; j < i; j++) {
                free(DA->array[j].data);
                DA->array[j].data = NULL;
            }
            free(DA->array);
            DA->array = NULL;
            free(DA);
            DA = NULL;
            return NULL;
        }
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

inline void* DynamicArray_front(DynamicArray* DA)
{
    return (char*)DA->array + (DA->data_size * DA->front);
}

inline void* DynamicArray_back(DynamicArray* DA)
{
    return (char*)DA->array + (DA->data_size * (DA->size - 1));
}

inline void* DynamicArray_at(DynamicArray* DA, size_t index)
{
    return (char*)DA->array + (DA->data_size * (DA->front + index));
}

int DynamicArray_change_capacity(DynamicArray* DA, size_t capacity)
{
    void* array = realloc(DA->array, DA->data_size * DA->capacity);
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
            memmove((char*)DA->array + DA->data_size,
                (char*)DA->array + (DA->data_size * DA->front), DA->data_size * DA->size);
            DA->front = 0;
            DA->back = DA->size;
        }
        else {
            DA->front = DA->front - 1;
        }
    }
    else {
        memmove((char*)DA->array + DA->data_size, (char*)DA->array + (DA->data_size * DA->front),
            DA->data_size * DA->size);
    }
    memcpy(DynamicArray_front(DA), data, DA->data_size);
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
        memmove(DA->array, (char*)DA->array + (DA->data_size * DA->front),
            DA->data_size * DA->size);
        DA->front = 0;
        DA->back = DA->size;
    }
    memcpy((char*)DA->array + (DA->data_size * DA->size), data, DA->data_size);
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
    memmove((char*)DynamicArray_at(DA, index) + DA->data_size, DynamicArray_at(DA, index),
        DA->data_size * (DA->size - index - 1));
    memcpy(DynamicArray_at(DA, index), data, DA->data_size);
    DA->size = DA->size + 1;
    return 1;
}

int DynamicArray_sorted_insert(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity &&
        !DynamicArray_change_capacity(DA, DA->capacity * DA->growth_factor)) {
            return 0;
    }
    for(size_t i = 0; i < DA->size; i++) {
        if(DA->compare(data, DynamicArray_at(DA, i)) <= 0) {
            memmove((char*)DynamicArray_at(DA, i) + DA->data_size, DynamicArray_at(DA, i),
                DA->data_size * (DA->size - i - 1));
            memcpy(DynamicArray_at(DA, i), data, DA->data_size);
            DA->size = DA->size + 1;
            return 1;
        }
    }
    memcpy((char*)DynamicArray_back(DA) + DA->data_size, data, DA->data_size);
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
    memmove(DynamicArray_at(DA, index), (char*)DynamicArray_at(DA, index) + DA->data_size,
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
        if(!DA->compare(data, DynamicArray_at(DA, i))) {
            memmove(DynamicArray_at(DA, i), (char*)DynamicArray_at(DA, i) + DA->data_size,
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
