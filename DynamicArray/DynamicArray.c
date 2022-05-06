#include "DynamicArray.h"

DynamicArray* DynamicArray_create(size_t data_size, size_t capacity, double growth_factor,
    int (*compare)(void* data1, void* data2));
void DynamicArray_destroy(DynamicArray* DA);

bool DynamicArray_push_front(DynamicArray* DA, void* data);
bool DynamicArray_push_back(DynamicArray* DA, void* data);
bool DynamicArray_insert(DynamicArray* DA, size_t index, void* data);
bool DynamicArray_sorted_insert(DynamicArray* DA, void* data);
bool DynamicArray_pop_front(DynamicArray* DA);
bool DynamicArray_pop_back(DynamicArray* DA);
bool DynamicArray_remove(DynamicArray* DA, void* data);
bool DynamicArray_erase(DynamicArray* DA, size_t index);

size_t DynamicArray_search(DynamicArray* DA, void* data);
void* DynamicArray_at(DynamicArray* DA, size_t index);

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

bool DynamicArray_push_front(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void* array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return false;
        }
        DA->array = array;
    }
    memmove((char* )DA->array + DA->data_size, DA->array, DA->data_size * DA->size);
    memcpy(DA->array, data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool DynamicArray_push_back(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void* array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return false;
        }
        DA->array = array;
    }
    memcpy((char* )DA->array + (DA->data_size * DA->size), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool DynamicArray_insert(DynamicArray* DA, size_t index, void* data)
{
    if(index > DA->size) {
        return false;
    }
    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void* array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return false;
        }
        DA->array = array;
    }
    memmove((char* )DA->array + (DA->data_size * index) + DA->data_size, (char* )DA->array + (DA->data_size * index), DA->data_size * DA->size);
    memcpy((char* )DA->array + (DA->data_size * index), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool DynamicArray_sorted_insert(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void* array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return false;
        }
        DA->array = array;
    }
    for(size_t i = 0; i < DA->size; i++) {
        int compare = DA->compare(data, (char* )DA->array + i);
        if(compare <= 0) {
            memmove((char* )DA->array + (DA->data_size * (i + 1)), (char* )DA->array + (DA->data_size * i), DA->data_size * (DA->size - i - 1));
            memcpy((char* )DA->array + (DA->data_size * i), data, DA->data_size);
            DA->size = DA->size + 1;
            return true;
        }
    }
    memcpy((char* )DA->array + (DA->data_size * DA->size), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool DynamicArray_pop_front(DynamicArray* DA)
{
    if(!DA->size) {
        return false;
    }
    memmove(DA->array, (char* )DA->array + DA->data_size, (DA->size - 1) * DA->data_size);
    DA->size = DA->size - 1;
    return true;
}

bool DynamicArray_pop_back(DynamicArray* DA)
{
    if(!DA->size) {
        return false;
    }
    DA->size = DA->size - 1;
    return true;
}

bool DynamicArray_erase(DynamicArray* DA, size_t index)
{
    if(!DA->size) {
        return false;
    }
    if(index >= DA->data_size) {
        return false;
    }
    memmove((char* )DA->array + (DA->data_size * index), (char* )DA->array + (DA->data_size * (index + 1)), DA->data_size * (DA->size - index + 1));
    DA->size = DA->size - 1;
    return true;
}

bool DynamicArray_remove(DynamicArray* DA, void* data)
{
    if(!DA->size) {
        return false;
    }
    for(size_t i = 0; i < DA->size; i++) {
        if(!DA->compare(data, (char* )DA->array + i)) {
            memmove((char* )DA->array + (DA->data_size * i), (char* )DA->array + (DA->data_size * (i + 1)), DA->data_size * (DA->size - i + 1));
            DA->size = DA->size - 1;
            return true;
        }
    }
    return false;
}

// size_t DynamicArray_search(DynamicArray* DA, void* data)
// {

// }

void* DynamicArray_at(DynamicArray* DA, size_t index)
{
    if(!DA->size) {
        return NULL;
    }
    if(index >= DA->size) {
        return NULL;
    }
    return (char* )DA->array + (DA->data_size * index);
}
