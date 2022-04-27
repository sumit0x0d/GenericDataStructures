#include "deque-array.h"

struct DequeA {
    void* array;
    size_t data_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
};

DequeA* deque_array_create(size_t data_size, size_t capacity);
bool deque_array_change_capacity(DequeA* D, size_t capacity);
void deque_array_destroy(DequeA* D);

void* deque_array_front(DequeA* D);
void* deque_array_back(DequeA* D);
size_t deque_array_size(DequeA* D);

bool deque_array_push_front(DequeA* D, void* data);
bool deque_array_push_back(DequeA* D, void* data);
bool deque_array_pop_front(DequeA* D);
bool deque_array_pop_back(DequeA* D);

DequeA* deque_array_create(size_t data_size, size_t capacity)
{
    DequeA* D = malloc(sizeof (DequeA));
    if(!D) {
        return NULL;
    }
    D->array = malloc(data_size * capacity);
    if(!D->array) {
        return NULL;
    }
    D->data_size = data_size;
    D->front = 0;
    D->back = 0;
    D->capacity = capacity;
    D->size = 0;
    return D;
}

bool deque_array_change_capacity(DequeA* D, size_t capacity)
{
    if(!capacity) {
        return false;
    }
    void* array = realloc(D->array, D->data_size * capacity);
    if(!array) {
        return false;
    }
    D->array = array;
    D->capacity = capacity;
    return true;
}

void deque_array_destroy(DequeA* D)
{
    free(D->array);
    D->array = NULL;
    free(D);
    D = NULL;
}

void* deque_array_front(DequeA* D)
{
    return (char* )D->array + (D->data_size * D->front);
}

void* deque_array_back(DequeA* D)
{
    return (char* )D->array + (D->data_size * D->back);
}

size_t deque_array_size(DequeA* D)
{
    return D->size;
}

bool deque_array_push_front(DequeA* D, void* data)
{
    if(D->front) {
        D->front = D->front - 1;
    }
    else if(D->back == D->capacity) {
        return false;
    }
    else {
        memmove((char* )D->array + D->data_size, (char* )D->array, D->size);
    }
    memcpy((char* )D->array + (D->data_size * D->front), data, D->data_size);
    D->size = D->size + 1;
    return true;
}

bool deque_array_push_back(DequeA* D, void* data)
{
    if(D->back == D->capacity) {
        if(D->front) {
            memmove(D->array, (char* )D->array + (D->data_size * D->front), D->size);
            D->front = 0;
            D->back = D->size;
        }
        else {
            return false;
        }
    }
    memcpy((char* )D->array + (D->data_size * D->back), data, D->data_size);
    D->back = D->back + 1;
    D->size = D->size + 1;
    return true;
}

bool deque_array_pop_front(DequeA* D)
{
    if(!D->size) {
        return false;
    }
    D->front = D->front + 1;
    D->size = D->size - 1;
    return true;
}

bool deque_array_pop_back(DequeA* D)
{
    if(!D->size) {
        return false;
    }
    D->back = D->back - 1;
    D->size = D->size - 1;
    return true;
}
