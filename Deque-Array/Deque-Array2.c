#include "Deque-Array2.h"

DequeA* DequeA_create(size_t data_size, size_t capacity);
int DequeA_change_capacity(DequeA* D, size_t capacity);
void DequeA_destroy(DequeA* D);

void* DequeA_front(DequeA* Q);
void* DequeA_back(DequeA* Q);

void DequeA_push_front(DequeA* D, void* data);
void DequeA_push_back(DequeA* D, void* data);
void DequeA_pop_front(DequeA* D);
void DequeA_pop_back(DequeA* D);

DequeA* DequeA_create(size_t data_size, size_t capacity)
{
    DequeA* D = malloc(sizeof (DequeA));
    if(!D) {
        return NULL;
    }
    D->array = malloc(sizeof (DequeANode) * capacity);
    if(!D->array) {
        free(D);
        D = NULL;
        return NULL;
    }
    for(size_t i = 0; i < capacity; i++) {
        D->array[i].data = malloc(data_size);
        if(!D->array[i].data) {
            for(size_t j = i; j < i; j++) {
                free(D->array[j].data);
                D->array[j].data = NULL;
            }
            free(D->array);
            D->array = NULL;
            free(D);
            D = NULL;
            return NULL;
        }
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

void* DequeA_front(DequeA* D)
{
    return D->array[D->front].data;
}

void* DequeA_back(DequeA* D)
{
    return D->array[D->back - 1].data;
}

void DequeA_push_front(DequeA* D, void* data)
{
    if(D->front) {
        D->front = D->front - 1;
    }
    else {
        memmove(D->array[D->front + 1].data, D->array[D->front].data, D->data_size * D->size);
    }
    memcpy(D->array[D->front].data, data, D->data_size);
    D->size = D->size + 1;
}

void DequeA_push_back(DequeA* D, void* data)
{
    if(D->back == D->capacity) {
        memmove(D->array, D->array[D->front].data, D->data_size * D->size);
        D->front = 0;
        D->back = D->size;
    }
    memcpy(D->array[D->back].data, data, D->data_size);
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
