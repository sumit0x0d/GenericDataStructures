#include "Deque-Array.h"

DequeA* DequeA_create(size_t data_size, size_t capacity);
int DequeA_change_capacity(DequeA* D, size_t capacity);
void DequeA_destroy(DequeA* D);

int DequeA_push_front(DequeA* D, void* data);
int DequeA_push_back(DequeA* D, void* data);
void DequeA_pop_front(DequeA* D);
void DequeA_pop_back(DequeA* D);

void* DequeA_front(DequeA* Q);
void* DequeA_back(DequeA* Q);

DequeA* DequeA_create(size_t data_size, size_t capacity)
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

int DequeA_change_capacity(DequeA* D, size_t capacity)
{
    void* array = realloc(D->array, D->data_size * capacity);
    if(!array) {
        return 0;
    }
    D->array = array;
    D->capacity = capacity;
    return 1;
}

void DequeA_destroy(DequeA* D)
{
    free(D->array);
    D->array = NULL;
    free(D);
    D = NULL;
}

int DequeA_push_front(DequeA* D, void* data)
{
    if(D->front) {
        D->front = D->front - 1;
    }
    else if(D->back == D->capacity) {
        return 0;
    }
    else {
        memmove((char* )D->array + D->data_size, (char* )D->array, D->size);
    }
    memcpy((char* )D->array + (D->data_size * D->front), data, D->data_size);
    D->size = D->size + 1;
    return 1;
}

int DequeA_push_back(DequeA* D, void* data)
{
    if(D->back == D->capacity) {
        if(D->front) {
            memmove(D->array, (char* )D->array + (D->data_size * D->front), D->size);
            D->front = 0;
            D->back = D->size;
        }
        else {
            return 0;
        }
    }
    memcpy((char* )D->array + (D->data_size * D->back), data, D->data_size);
    D->back = D->back + 1;
    D->size = D->size + 1;
    return 1;
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

void* DequeA_front(DequeA* Q)
{
    return (char*)Q->array + (Q->data_size * Q->front);
}

void* DequeA_back(DequeA* Q)
{
    return (char*)Q->array + (Q->data_size * (Q->back - 1));
}
