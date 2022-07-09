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

DequeA* DequeA_create(size_t data_size, size_t capacity)
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

bool DequeA_change_capacity(DequeA* D, size_t capacity)
{
    void* array = realloc(D->array, D->data_size * capacity);
    if(!array) {
        return false;
    }
    D->array = array;
    D->capacity = capacity;
    return true;
}

void DequeA_destroy(DequeA* D)
{
    free(D->array);
    D->array = NULL;
    free(D);
    D = NULL;
}

size_t DequeA_size(DequeA* D)
{
    return D->size;
}

bool DequeA_empty(DequeA* D)
{
    if(D->size) {
        return false;
    }
    return true;
}

bool DequeA_full(DequeA* D)
{
    if(D->size != D->capacity) {
        return false;
    }
    return true;
}

static inline void* data_at(DequeA* D, size_t index)
{
    return (char*)D->array + (D->data_size * index);
}

void* DequeA_front(DequeA* D)
{
    return data_at(D, D->front);
}

void* DequeA_back(DequeA* D)
{
    return data_at(D, D->back - 1);
}

void DequeA_push_front(DequeA* D, void* data)
{
    if(D->front) {
        D->front = D->front - 1;
    }
    else {
        memmove(data_at(D, 1), data_at(D, D->front), D->data_size * D->size);
    }
    memcpy(data_at(D, D->front), data, D->data_size);
    D->size = D->size + 1;
}

void DequeA_push_back(DequeA* D, void* data)
{
    if(D->back == D->capacity) {
        memmove(data_at(D, 0), data_at(D, D->front), D->data_size * D->size);
        D->front = 0;
        D->back = D->size;
    }
    memcpy(data_at(D, D->back), data, D->data_size);
    D->back = D->back + 1;
    D->size = D->size + 1;
}

void DequeA_pop_front(DequeA* D)
{
    D->front = D->front + 1;
    D->size = D->size - 1;
}

void DequeA_pop_back(DequeA* D)
{
    D->back = D->back - 1;
    D->size = D->size - 1;
}
