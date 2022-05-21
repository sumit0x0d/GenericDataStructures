#include "Queue-Array.h"

QueueA* QueueA_create(size_t data_size, size_t capacity);
int QueueA_change_capacity(QueueA* Q, size_t capacity);
void QueueA_destroy(QueueA* Q);

inline void* QueueA_front(QueueA* Q);
inline void* QueueA_back(QueueA* Q);

void QueueA_enqueue(QueueA* Q, void* data);
void QueueA_dequeue(QueueA* Q);

QueueA* QueueA_create(size_t data_size, size_t capacity)
{
    QueueA* Q = malloc(sizeof (QueueA));
    if(!Q) {
        return NULL;
    }
    Q->array = malloc(sizeof (QueueANode) * capacity);
    if(!Q->array) {
        free(Q);
        Q = NULL;
        return NULL;
    }
    for(size_t i = 0; i < capacity; i++) {
        Q->array[i].data = malloc(data_size);
        if(!Q->array[i].data) {
            for(size_t j = i; j < i; j++) {
                free(Q->array[j].data);
                Q->array[j].data = NULL;
            }
            free(Q->array);
            Q->array = NULL;
            free(Q);
            Q = NULL;
            return NULL;
        }
    }
    Q->data_size = data_size;
    Q->front = 0;
    Q->back = 0;
    Q->capacity = capacity;
    Q->size = 0;
    return Q;
}

int QueueA_change_capacity(QueueA* Q, size_t capacity)
{
    void* array = realloc(Q->array, Q->data_size * capacity);
    if(!array) {
        return 0;
    }
    Q->array = array;
    Q->capacity = capacity;
    if(Q->capacity < Q->size) {
        Q->back = Q->capacity;
        Q->size = Q->capacity;
    }
    return 1;
}

void QueueA_destroy(QueueA* Q)
{
    free(Q->array);
    Q->array = NULL;
    free(Q);
    Q = NULL;
}

inline void* QueueA_front(QueueA* Q)
{
    return Q->array[Q->front].data;
}

inline void* QueueA_back(QueueA* Q)
{
    return Q->array[Q->back - 1].data;
}

void QueueA_enqueue(QueueA* Q, void* data)
{
    if(Q->back == Q->capacity) {
        memmove(Q->array, Q->array[Q->front].data, Q->size);
        Q->front = 0;
        Q->back = Q->size;
    }
    memcpy(Q->array[Q->back].data, data, Q->data_size);
    Q->back = Q->back + 1;
    Q->size = Q->size + 1;
}

void QueueA_dequeue(QueueA* Q)
{
    Q->front = Q->front + 1;
    Q->size = Q->size - 1;
}
