#include "DynamicArray.h"

DynamicArray* DynamicArray_create(size_t data_size, size_t capacity, double growth_factor,
    int (*compare)(void* data1, void* data2));
void DynamicArray_destroy(DynamicArray* DA);

void* DynamicArray_at(DynamicArray* DA, size_t index);
void* DynamicArray_front(DynamicArray* DA);
void* DynamicArray_back(DynamicArray* DA);

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

void* DynamicArray_at(DynamicArray* DA, size_t index)
{
    return (char*)DA->array + (DA->data_size * index);
}

void* DynamicArray_back(DynamicArray* DA)
{
    return (char*)DA->array + (DA->data_size * (DA->size - 1));
}

int DynamicArray_push_front(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void* array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return 0;
        }
        DA->array = array;
    }
    memmove((char*)DA->array + DA->data_size, DA->array, DA->data_size * DA->size);
    memcpy(DA->array, data, DA->data_size);
    DA->size = DA->size + 1;
    return 1;
}

int DynamicArray_push_back(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void* array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return 0;
        }
        DA->array = array;
    }
    memcpy((char*)DynamicArray_back(DA) + DA->data_size, data, DA->data_size);
    DA->size = DA->size + 1;
    return 1;
}

int DynamicArray_insert(DynamicArray* DA, size_t index, void* data)
{
    if(index > DA->size) {
        return 0;
    }
    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void* array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return 0;
        }
        DA->array = array;
    }
    memmove((char*)DynamicArray_at(DA, index) + DA->data_size,
        DynamicArray_at(DA, index), DA->data_size * DA->size);
    memcpy(DynamicArray_at(DA, index), data, DA->data_size);
    DA->size = DA->size + 1;
    return 1;
}

int DynamicArray_sorted_insert(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void* array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return 0;
        }
        DA->array = array;
    }
    for(size_t i = 0; i < DA->size; i++) {
        int compare = DA->compare(data, (char*)DA->array + i);
        if(compare <= 0) {
            memmove((char*)DA->array + (DA->data_size * (i + 1)),
                (char*)DA->array + (DA->data_size * i), DA->data_size * (DA->size - i - 1));
            memcpy((char*)DA->array + (DA->data_size * i), data, DA->data_size);
            DA->size = DA->size + 1;
            return 1;
        }
    }
    memcpy((char*)DA->array + (DA->data_size * DA->size), data, DA->data_size);
    DA->size = DA->size + 1;
    return 1;
}

int DynamicArray_pop_front(DynamicArray* DA)
{
    if(DA->size == (DA->capacity / DA->growth_factor)) {
        DA->capacity = DA->capacity / DA->growth_factor;
        void* array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return 0;
        }
        DA->array = array;
    }
    memmove(DA->array, (char*)DA->array + DA->data_size, (DA->size - 1) * DA->data_size);
    DA->size = DA->size - 1;
    return 1;
}

int DynamicArray_pop_back(DynamicArray* DA)
{
    if(DA->size == (DA->capacity / DA->growth_factor)) {
        DA->capacity = DA->capacity / DA->growth_factor;
        void* array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return 0;
        }
        DA->array = array;
    }
    DA->size = DA->size - 1;
    return 1;
}

int DynamicArray_erase(DynamicArray* DA, size_t index)
{
    if(index >= DA->size) {
        return 0;
    }
    if(DA->size == (DA->capacity / DA->growth_factor)) {
        DA->capacity = DA->capacity / DA->growth_factor;
        void* array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return 0;
        }
        DA->array = array;
    }
    memmove((char*)DA->array + (DA->data_size * index),
        (char*)DA->array + (DA->data_size * (index + 1)), DA->data_size * (DA->size - index + 1));
    DA->size = DA->size - 1;
    return 1;
}

int DynamicArray_remove(DynamicArray* DA, void* data)
{
    if(DA->size == (DA->capacity / DA->growth_factor)) {
        DA->capacity = DA->capacity / DA->growth_factor;
        void* array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return 0;
        }
        DA->array = array;
    }
    for(size_t i = 0; i < DA->size; i++) {
        if(!DA->compare(data, (char*)DA->array + i)) {
            memmove((char*)DA->array + (DA->data_size * i),
                (char*)DA->array + (DA->data_size * (i + 1)), DA->data_size * (DA->size - i + 1));
            DA->size = DA->size - 1;
            return 1;
        }
    }
    return 0;
}

// size_t DynamicArray_search(DynamicArray* DA, void* data)
// {

// }
