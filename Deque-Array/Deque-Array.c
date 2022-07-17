#include "Deque-Array.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct DequeA {
    void* array;
    size_t data_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
};

DequeA* DequeACreate(size_t data_size, size_t capacity)
{
    DequeA* D = (DequeA*)malloc(sizeof (DequeA));
    if(!D) {
        return NULL;
    }
    D->array = malloc(data_size * capacity);
    if(!D->array) {
        free(D);
        D = NULL;
        return NULL;
    }
    D->data_size = data_size;
    D->front = 0;
    D->back = 0;
    D->capacity = capacity;
    D->size = 0;
    return D;
}

bool DequeAChangeCapacity(DequeA* D, size_t capacity)
{
    void* array = realloc(D->array, D->data_size * capacity);
    if(!array) {
        return false;
    }
    D->array = array;
    D->capacity = capacity;
    return true;
}

void DequeADestroy(DequeA* D)
{
    free(D->array);
    D->array = NULL;
    free(D);
    D = NULL;
}

size_t DequeASize(DequeA* D)
{
    return D->size;
}

bool DequeAEmpty(DequeA* D)
{
    if(D->size) {
        return false;
    }
    return true;
}

bool DequeAFull(DequeA* D)
{
    if(D->size != D->capacity) {
        return false;
    }
    return true;
}

static inline void* DataAt(DequeA* D, size_t index)
{
    return (char*)D->array + (D->data_size * index);
}

void* DequeAFront(DequeA* D)
{
    return DataAt(D, D->front);
}

void* DequeABack(DequeA* D)
{
    return DataAt(D, D->back - 1);
}

void DequeAPushFront(DequeA* D, void* data)
{
    if(D->front) {
        D->front = D->front - 1;
    }
    else {
        memmove(DataAt(D, 1), DataAt(D, D->front), D->data_size * D->size);
    }
    memcpy(DataAt(D, D->front), data, D->data_size);
    D->size = D->size + 1;
}

void DequeAPushBack(DequeA* D, void* data)
{
    if(D->back == D->capacity) {
        memmove(DataAt(D, 0), DataAt(D, D->front), D->data_size * D->size);
        D->front = 0;
        D->back = D->size;
    }
    memcpy(DataAt(D, D->back), data, D->data_size);
    D->back = D->back + 1;
    D->size = D->size + 1;
}

void DequeAPopFront(DequeA* D)
{
    D->front = D->front + 1;
    D->size = D->size - 1;
}

void DequeAPopBack(DequeA* D)
{
    D->back = D->back - 1;
    D->size = D->size - 1;
}
