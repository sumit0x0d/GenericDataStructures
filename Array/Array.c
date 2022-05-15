#include "Array.h"

Array* Array_create(size_t data_size, size_t capacity,
    int (*compare)(void* data1, void* data2));
int Array_change_capacity(Array* A, size_t capacity);
void Array_destroy(Array* A);

void Array_push_front(Array* DA, void* data);
void Array_push_back(Array* DA, void* data);
int Array_insert(Array* DA, size_t index, void* data);
int Array_sorted_insert(Array* DA, void* data);
void Array_pop_front(Array* DA);
void Array_pop_back(Array* DA);
int Array_remove(Array* DA, void* data);
int Array_erase(Array* DA, size_t index);

size_t Array_search(Array* A, void* data);

Array* Array_create(size_t data_size, size_t capacity,
    int (*compare)(void* data1, void* data2))
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

void Array_push_front(Array* A, void* data)
{
    memmove((char*)A->array + A->data_size, A->array, A->data_size * A->size);
    memcpy(A->array, data, A->data_size);
    A->size = A->size + 1;
}

void Array_push_back(Array* A, void* data)
{
    memcpy((char*)A->array + (A->data_size * A->size), data, A->data_size);
    A->size = A->size + 1;
}

void Array_pop_front(Array* A)
{
    memmove(A->array, (char* )A->array + A->data_size, (A->size - 1) * A->data_size);
    A->size = A->size - 1;
}

void Array_pop_back(Array* A)
{
    A->size = A->size - 1;
}

int Array_remove(Array* A, void* data)
{

}

int Array_reverse(Array* A, void* data)
{

}

void* Array_front(Array* A)
{
    return A->array;
}

void* Array_back(Array* A)
{
    return (char*)A->array + (A->data_size * (A->size - 1));
}
