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
    A->data = malloc(data_size);
    if(!A->data) {
        free(A->array);
        A->array = NULL;
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

void Array_pop_front(Array* A)
{
    memmove(data_at(A, 0), data_at(A, 1), A->data_size * (A->size - 1));
    A->size = A->size - 1;
}

void Array_pop_back(Array* A)
{
    A->size = A->size - 1;
}

// int Array_remove(Array* A, void* data)
// {

// }

void Array_reverse(Array* A)
{
    char* front = data_at(A, 0);
    char* back = data_at(A, A->size - 1);
    while(front < back) {
        memcpy(A->data, front, A->data_size);
        memcpy(front, back, A->data_size);
        memcpy(back, A->data, A->data_size);
        front = front + A->data_size;
        back = back - A->data_size;
    }
}
