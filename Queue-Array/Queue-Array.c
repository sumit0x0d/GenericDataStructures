#include "Queue-Array.h"

QueueA* QueueA_create(size_t data_size, size_t capacity);
bool QueueA_change_capacity(QueueA* Q, size_t capacity);
void QueueA_destroy(QueueA* Q);

bool QueueA_enqueue(QueueA* Q, void* data);
bool QueueA_dequeue(QueueA* Q);

void* QueueA_front(QueueA* Q);
void* QueueA_back(QueueA* Q);

QueueA* QueueA_create(size_t data_size, size_t capacity)
{
    QueueA* Q = malloc(sizeof (QueueA));
    if(!Q) {
        return NULL;
    }
    Q->array = malloc(data_size * capacity);
    if(!Q->array) {
        return NULL;
    }
    Q->data_size = data_size;
    Q->front = 0;
    Q->back = 0;
    Q->capacity = capacity;
    Q->size = 0;
    return Q;
}

bool QueueA_change_capacity(QueueA* Q, size_t capacity)
{
    if(!capacity) {
        return false;
    }
    void* array = realloc(Q->array, Q->data_size * capacity);
    if(!array) {
        return false;
    }
    Q->array = array;
    Q->capacity = capacity;
    return true;
}

void QueueA_destroy(QueueA* Q)
{
    free(Q->array);
    Q->array = NULL;
    free(Q);
    Q = NULL;
}

bool QueueA_enqueue(QueueA* Q, void* data)
{
    if(Q->back == Q->capacity) {
        if(Q->front) {
            memmove(Q->array, (char*)Q->array + (Q->data_size * Q->front), Q->size);
            Q->front = 0;
            Q->back = Q->size;
        }
        else {
            return false;
        }
    }
    memcpy((char*)Q->array + (Q->data_size * Q->back), data, Q->data_size);
    Q->back = Q->back + 1;
    Q->size = Q->size + 1;
    return true;
}

bool QueueA_dequeue(QueueA* Q)
{
    if(!Q->size) {
        return false;
    }
    Q->front = Q->front + 1;
    Q->size = Q->size - 1;
    return true;
}

void* QueueA_front(QueueA* Q)
{
    if(!Q->size) {
        return NULL;
    }
    return (char*)Q->array + (Q->data_size * Q->front);
}

void* QueueA_back(QueueA* Q)
{
    if(!Q->size) {
        return NULL;
    }
    return (char*)Q->array + (Q->data_size * (Q->back - 1));
}
