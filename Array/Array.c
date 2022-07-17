#include "Array.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Array {
    void* array;
    size_t data_size;
    size_t capacity;
    size_t size;
    int (*compare_function)(void* data1, void* data2);
};

Array* ArrayCreate(size_t data_size, size_t capacity, int (*compare_function)(void* data1, void* data2))
{
    Array* A = (Array*)malloc(sizeof (Array));
    if(!A) {
        return NULL;
    }
    A->array = malloc(data_size * capacity);
    if(!A->array) {
        free(A);
        A = NULL;
        return NULL;
    }
    A->data_size = data_size;
    A->capacity = capacity;
    A->size = 0;
    A->compare_function = compare_function;
    return A;
}

bool ArrayChangeCapacity(Array* A, size_t capacity)
{
    void* array = realloc(A->array, A->data_size * capacity);
    if(!array) {
        return false;
    }
    A->array = array;
    A->capacity = capacity;
    return true;
}

void ArrayDestroy(Array* A)
{
    free(A->array);
    A->array = NULL;
    free(A);
    A = NULL;
}

size_t ArraySize(Array* A)
{
    return A->size;
}

bool ArrayEmpty(Array* A)
{
    if(A->size) {
        return false;
    }
    return true;
}

bool ArrayFull(Array* A)
{
    if(A->size != A->capacity) {
        return false;
    }
    return true;
}

static inline void* DataAt(Array* A, size_t index)
{
    return (char*)A->array + (A->data_size * index);
}

void* ArrayFront(Array* A)
{
    return DataAt(A, 0);
}

void* ArrayBack(Array* A)
{
    return DataAt(A, A->size - 1);
}

void* ArrayAt(Array* A, size_t index)
{
    return DataAt(A, index);
}

void* ArraySearch(Array* A, void* data)
{
    size_t left = 0;
    size_t right = A->size;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare_function = A->compare_function(data, DataAt(A, middle));
        if(!compare_function) {
            return DataAt(A, middle);
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

void ArrayPushFront(Array* A, void* data)
{
    memmove(DataAt(A, 1), DataAt(A, 0), A->data_size * A->size);
    memcpy(DataAt(A, 0), data, A->data_size);
    A->size = A->size + 1;
}

void ArrayPushBack(Array* A, void* data)
{
    memcpy(DataAt(A, A->size), data, A->data_size);
    A->size = A->size + 1;
}

void ArrayInsert(Array* A, size_t index, void* data)
{
    memmove(DataAt(A, index), DataAt(A, index + 1), A->data_size * (A->size - index - 1));
    memcpy(DataAt(A, index), data, A->data_size);
    A->size = A->size + 1;
}

void ArraySortedInsert(Array* A, void* data)
{
    if(!A->size) {
        memcpy(DataAt(A, 0), data, A->data_size);
        A->size = A->size + 1;
        return;
    }
    if(A->compare_function(data, DataAt(A, 0)) < 0) {
        memmove(DataAt(A, 1), DataAt(A, 0), A->data_size * A->size);
        memcpy(DataAt(A, 0), data, A->data_size);
        A->size = A->size + 1;
        return;
    }
    if(A->compare_function(data, DataAt(A, A->size - 1)) > 0) {
        memcpy(DataAt(A, A->size), data, A->data_size);
        A->size = A->size + 1;
        return;
    }
    size_t left = 0;
    size_t right = A->size - 1;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare_function = A->compare_function(data, DataAt(A, middle));
        if(!compare_function) {
            memmove(DataAt(A, middle + 2), DataAt(A, middle + 1),
                A->data_size * (A->size - middle - 1));
            memcpy(DataAt(A, middle + 1), data, A->data_size);
            A->size = A->size + 1;
            return;
        }
        else if(compare_function < 0) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }   
    }
    memmove(DataAt(A, left + 1), DataAt(A, left), A->data_size * (A->size - left + 1));
    memcpy(DataAt(A, left), data, A->data_size);
    A->size = A->size + 1;
}

void ArrayPopFront(Array* A)
{
    memmove(DataAt(A, 0), DataAt(A, 1), A->data_size * (A->size - 1));
    A->size = A->size - 1;
}

void ArrayPopBack(Array* A)
{
    A->size = A->size - 1;
}

void ArrayRemove(Array* A, void* data)
{
    size_t left = 0;
    size_t right = A->size;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare_function = A->compare_function(data, DataAt(A, middle));
        if(!compare_function) {
            memmove(DataAt(A, middle), DataAt(A, middle + 1),
                A->data_size * (A->size - middle + 1));
            A->size = A->size - 1;
            break;
        }
        else if(compare_function < 0) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
}

void ArrayErase(Array* A, size_t index)
{
    memmove(DataAt(A, index), DataAt(A, index + 1), A->data_size * (A->size - index + 1));
    A->size = A->size - 1;
}
