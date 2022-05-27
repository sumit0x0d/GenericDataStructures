#include "DynamicArray.h"

static inline void* data_at(DynamicArray* DA, size_t index);

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
    return data_at(DA, 0);
}

void* DynamicArray_back(DynamicArray* DA)
{
    return data_at(DA, DA->size - 1);
}

void* DynamicArray_at(DynamicArray* DA, size_t index)
{
    return data_at(DA, index);
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
    memmove(data_at(DA, 1), data_at(DA, 0), DA->data_size * (DA->size - 1));
    memcpy(data_at(DA, 0), data, DA->data_size);
    DA->size = DA->size + 1;
    return 1;
}

int DynamicArray_push_back(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity &&
        !DynamicArray_change_capacity(DA, DA->capacity * DA->growth_factor)) {
            return 0;
    }
    memcpy(data_at(DA, DA->size), data, DA->data_size);
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
    memmove(data_at(DA, index + 1), data_at(DA, index), DA->data_size * (DA->size - index - 1));
    memcpy(data_at(DA, index), data, DA->data_size);
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
        if(DA->compare(data, data_at(DA, i)) <= 0) {
            memmove(data_at(DA, i + 1), data_at(DA, i), DA->data_size * (DA->size - i - 1));
            memcpy(data_at(DA, i), data, DA->data_size);
            DA->size = DA->size + 1;
            return 1;
        }
    }
    memcpy(data_at(DA, i + 1), data, DA->data_size);
    DA->size = DA->size + 1;
    return 1;
}

int DynamicArray_pop_front(DynamicArray* DA)
{
    if(DA->size == DA->capacity / DA->growth_factor &&
        !DynamicArray_change_capacity(DA, DA->capacity / DA->growth_factor)) {
            return 0;
    }
    memmove(data_at(DA, 0), data_at(DA, 1), DA->data_size * (DA->size - 1));
    DA->size = DA->size - 1;
    return 1;
}

int DynamicArray_pop_back(DynamicArray* DA)
{
    if(DA->size == DA->capacity / DA->growth_factor &&
        !DynamicArray_change_capacity(DA, DA->capacity / DA->growth_factor)) {
            return 0;
    }
    DA->size = DA->size - 1;
    return 1;
}

int DynamicArray_erase(DynamicArray* DA, size_t index)
{
    if(DA->size == DA->capacity / DA->growth_factor &&
        !DynamicArray_change_capacity(DA, DA->capacity / DA->growth_factor)) {
            return 0;
    }
    memmove(data_at(DA, index), data_at(DA, index + 1), DA->data_size * (DA->size - index + 1));
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
        if(!DA->compare(data, data_at(DA, i))) {
            memmove(data_at(DA, i), data_at(DA, i + 1), DA->data_size * (DA->size - i + 1));
            DA->size = DA->size - 1;
            return 1;
        }
    }
    return 0;
}

// size_t DynamicArray_search(DynamicArray* DA, void* data)
// {

// }
