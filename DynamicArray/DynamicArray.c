#include "DynamicArray.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct DynamicArray {
    void* array;
    size_t data_size;
    size_t capacity;
    double growth_factor;
    size_t size;
    int (*compare_function)(void* data1, void* data2);
};

DynamicArray* DynamicArrayCreate(size_t data_size, size_t capacity, double growth_factor,
    int (*compare_function)(void* data1, void* data2))
{
    if((size_t)(capacity * growth_factor) <= capacity) {
        return NULL;
    }
    DynamicArray* DA = (DynamicArray*)malloc(sizeof (DynamicArray));
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
    DA->compare_function = compare_function;
    DA->size = 0;
    return DA;
}

static bool DynamicArrayChangeCapacity(DynamicArray* DA, size_t capacity)
{
    void* array = realloc(DA->array, DA->data_size * DA->capacity);
    if(!array) {
        return false;
    }
    DA->array = array;
    DA->capacity = capacity;
    return true;
}

void DynamicArrayDestroy(DynamicArray* DA)
{
    free(DA->array);
    DA->array = NULL;
    DA->size = 0;
    free(DA);
    DA = NULL;
}

size_t DynamicArraySize(DynamicArray* DA)
{
    return DA->size;
}

bool DynamicArrayEmpty(DynamicArray* DA)
{
    if(DA->size) {
        return false;
    }
    return true;
}

static inline void* DataAt(DynamicArray* DA, size_t index)
{
    return (char*)DA->array + (DA->data_size * index);
}

void* DynamicArrayFront(DynamicArray* DA)
{
    return DataAt(DA, 0);
}

void* DynamicArrayBack(DynamicArray* DA)
{
    return DataAt(DA, DA->size - 1);
}

void* DynamicArrayAt(DynamicArray* DA, size_t index)
{
    return DataAt(DA, index);
}

void* DynamicArraySearch(DynamicArray* DA, void* data)
{
    size_t left = 0;
    size_t right = DA->size;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare_function = DA->compare_function(data, DataAt(DA, middle));
        if(!compare_function) {
            return DataAt(DA, middle);
        }
        else if(compare_function < 0) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return NULL;
}

bool DynamicArrayPushFront(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity) {
        if(!DynamicArrayChangeCapacity(DA, DA->capacity * DA->growth_factor)) {
            return false;
        }
    }
    memmove(DataAt(DA, 1), DataAt(DA, 0), DA->data_size * (DA->size - 1));
    memcpy(DataAt(DA, 0), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool DynamicArrayPushBack(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity) {
        if(!DynamicArrayChangeCapacity(DA, DA->capacity * DA->growth_factor)) {
            return false;
        }
    }
    memcpy(DataAt(DA, DA->size), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool DynamicArrayInsert(DynamicArray* DA, size_t index, void* data)
{
    if(DA->size == DA->capacity) {
        if(!DynamicArrayChangeCapacity(DA, DA->capacity * DA->growth_factor)) {
            return false;
        }
    }
    memmove(DataAt(DA, index + 1), DataAt(DA, index), DA->data_size * (DA->size - index - 1));
    memcpy(DataAt(DA, index), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool DynamicArraySortedInsert(DynamicArray* DA, void* data)
{
    if(!DA->size) {
        memcpy(DataAt(DA, 0), data, DA->data_size);
        DA->size = DA->size + 1;
        return true;
    }
    if(DA->size == DA->capacity) {
        if(!DynamicArrayChangeCapacity(DA, DA->capacity * DA->growth_factor)) {
            return false;
        }
    }
    if(DA->compare_function(data, DataAt(DA, 0)) < 0) {
        memmove(DataAt(DA, 1), DataAt(DA, 0), DA->data_size * DA->size);
        memcpy(DataAt(DA, 0), data, DA->data_size);
        DA->size = DA->size + 1;
        return true;
    }
    if(DA->compare_function(data, DataAt(DA, DA->size - 1)) > 0) {
        memcpy(DataAt(DA, DA->size), data, DA->data_size);
        DA->size = DA->size + 1;
        return true;
    }
    size_t left = 0;
    size_t right = DA->size - 1;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare_function = DA->compare_function(data, DataAt(DA, middle));
        if(!compare_function) {
            memmove(DataAt(DA, middle + 2), DataAt(DA, middle + 1),
                DA->data_size * (DA->size - middle - 1));
            memcpy(DataAt(DA, middle + 1), data, DA->data_size);
            DA->size = DA->size + 1;
            return true;
        }
        else if(compare_function < 0) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }   
    }
    memmove(DataAt(DA, left + 1), DataAt(DA, left), DA->data_size * (DA->size - left + 1));
    memcpy(DataAt(DA, left), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool DynamicArrayPopFront(DynamicArray* DA)
{
    if(DA->size == DA->capacity / DA->growth_factor) {
        if(!DynamicArrayChangeCapacity(DA, DA->capacity / DA->growth_factor)) {
            return false;
        }
    }
    memmove(DataAt(DA, 0), DataAt(DA, 1), DA->data_size * (DA->size - 1));
    DA->size = DA->size - 1;
    return true;
}

bool DynamicArrayPopBack(DynamicArray* DA)
{
    if(DA->size == DA->capacity / DA->growth_factor) {
        if(!DynamicArrayChangeCapacity(DA, DA->capacity / DA->growth_factor)) {
            return false;
        }
    }
    DA->size = DA->size - 1;
    return true;
}

bool DynamicArrayRemove(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity / DA->growth_factor) {
        if(!DynamicArrayChangeCapacity(DA, DA->capacity / DA->growth_factor)) {
            return false;
        }
    }
    size_t left = 0;
    size_t right = DA->size;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare_function = DA->compare_function(data, DataAt(DA, middle));
        if(!compare_function) {
            memmove(DataAt(DA, middle), DataAt(DA, middle + 1),
                DA->data_size * (DA->size - middle + 1));
            DA->size = DA->size - 1;
            break;
        }
        else if(compare_function < 0) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return true;
}

bool DynamicArrayErase(DynamicArray* DA, size_t index)
{
    if(DA->size == DA->capacity / DA->growth_factor) {
        if(!DynamicArrayChangeCapacity(DA, DA->capacity / DA->growth_factor)) {
            return false;
        }
    }
    memmove(DataAt(DA, index), DataAt(DA, index + 1), DA->data_size * (DA->size - index + 1));
    DA->size = DA->size - 1;
    return true;
}
