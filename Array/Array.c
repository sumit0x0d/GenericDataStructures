#include "Array.h"

Array* Array_create(size_t data_size, size_t capacity,
    int (*compare)(void* data1, void* data2));
void Array_change_capacity(Array* A, size_t capacity);
void Array_destroy(Array* A);

int Array_push_front(Array* DA, void* data);
int Array_push_back(Array* DA, void* data);
int Array_insert(Array* DA, size_t index, void* data);
int Array_sorted_insert(Array* DA, void* data);
int Array_pop_front(Array* DA);
int Array_pop_back(Array* DA);
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

void Array_change_capacity(Array* A, size_t capacity)
{
    if(!capacity) {
        return 0;
    }
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

int Array_push_front(Array* A, void* data)
{
    if(A->size == A->capacity) {
        return 0;
    }
    memmove((char*)A->array + A->data_size, A->array, A->data_size * A->size);
    memcpy(A->array, data, A->data_size);
    A->size = A->size + 1;
    return 1;
}

int Array_push_back(Array* A, void* data)
{
    if(A->size == A->capacity) {
        return 0;
    }
    memcpy((char*)A->array + (A->data_size * A->size), data, A->data_size);
    A->size = A->size + 1;
    return 1;
}

int Array_pop_front(Array* A)
{
    if(!A->size) {
        return 0;
    }
    memmove(A->array, (char* )A->array + A->data_size, (A->size - 1) * A->data_size);
    A->size = A->size - 1;
    return 1;
}

int Array_pop_back(Array* A)
{
    if(!A->size) {
        return 0;
    }
    A->size = A->size - 1;
    return 1;
}

int Array_remove(Array* A, void* data)
{

}

int Array_reverse(Array* A, void* data)
{

}
