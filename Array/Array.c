#include "Array.h"

static inline void* data_at(Array* A, size_t index);

Array* Array_create(size_t data_size, size_t capacity, int (*compare)(void* data1, void* data2))
{
    Array* A = malloc(sizeof (Array));
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
    A->compare = compare;
    return A;
}

int Array_change_capacity(Array* A, size_t capacity)
{
    void* array = realloc(A->array, A->data_size * capacity);
    if(!array) {
        return 0;
    }
    A->array = array;
    A->capacity = capacity;
    return 1;
}

void Array_destroy(Array* A)
{
    free(A->array);
    A->array = NULL;
    free(A);
    A = NULL;
}

static inline void* data_at(Array* A, size_t index)
{
    return (char*)A->array + (A->data_size * index);
}

void* Array_front(Array* A)
{
    return data_at(A, 0);
}

void* Array_back(Array* A)
{
    return data_at(A, A->size - 1);
}

void* Array_at(Array* A, size_t index)
{
    return data_at(A, index);
}

void* Array_search(Array* A, void* data)
{
    size_t left = 0;
    size_t right = A->size;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare = A->compare(data, data_at(A, middle));
        if(!compare) {
            return data_at(A, middle);
        }
        else if(compare < 0) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return NULL;
}

void Array_push_front(Array* A, void* data)
{
    memmove(data_at(A, 1), data_at(A, 0), A->data_size * A->size);
    memcpy(data_at(A, 0), data, A->data_size);
    A->size = A->size + 1;
}

void Array_push_back(Array* A, void* data)
{
    memcpy(data_at(A, A->size), data, A->data_size);
    A->size = A->size + 1;
}

void Array_insert(Array* A, size_t index, void* data)
{
    memmove(data_at(A, index), data_at(A, index + 1), A->data_size * (A->size - index - 1));
    memcpy(data_at(A, index), data, A->data_size);
    A->size = A->size + 1;
}

void Array_sorted_insert(Array* A, void* data)
{
    if(!A->size) {
        memcpy(data_at(A, 0), data, A->data_size);
        A->size = A->size + 1;
        return;
    }
    if(A->compare(data, data_at(A, 0)) < 0) {
        memmove(data_at(A, 1), data_at(A, 0), A->data_size * A->size);
        memcpy(data_at(A, 0), data, A->data_size);
        A->size = A->size + 1;
        return;
    }
    if(A->compare(data, data_at(A, A->size - 1)) > 0) {
        memcpy(data_at(A, A->size), data, A->data_size);
        A->size = A->size + 1;
        return;
    }
    size_t left = 0;
    size_t right = A->size - 1;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare = A->compare(data, data_at(A, middle));
        if(!compare) {
            memmove(data_at(A, middle + 2), data_at(A, middle + 1),
                A->data_size * (A->size - middle - 1));
            memcpy(data_at(A, middle + 1), data, A->data_size);
            A->size = A->size + 1;
            return;
        }
        else if(compare < 0) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }   
    }
    memmove(data_at(A, left + 1), data_at(A, left), A->data_size * (A->size - left + 1));
    memcpy(data_at(A, left), data, A->data_size);
    A->size = A->size + 1;
}

void Array_pop_front(Array* A)
{
    memmove(data_at(A, 0), data_at(A, 1), A->data_size * (A->size - 1));
    A->size = A->size - 1;
}

void Array_pop_back(Array* A)
{
    A->size = A->size - 1;
}

void Array_remove(Array* A, void* data)
{
    size_t left = 0;
    size_t right = A->size;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare = A->compare(data, data_at(A, middle));
        if(!compare) {
            memmove(data_at(A, middle), data_at(A, middle + 1),
                A->data_size * (A->size - middle + 1));
            A->size = A->size - 1;
            break;
        }
        else if(compare < 0) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
}

void Array_erase(Array* A, size_t index)
{
    memmove(data_at(A, index), data_at(A, index + 1), A->data_size * (A->size - index + 1));
    A->size = A->size - 1;
}
