#include "Queue-Array.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct QueueA {
    void* array;
    size_t data_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
};

QueueA* QueueACreate(size_t data_size, size_t capacity)
{
    QueueA* Q = (QueueA*)malloc(sizeof (QueueA));
    if(!Q) {
        return NULL;
    }
    Q->array = malloc(data_size * capacity);
    if(!Q->array) {
        free(Q);
        return NULL;
    }
    Q->data_size = data_size;
    Q->front = 0;
    Q->back = 0;
    Q->capacity = capacity;
    Q->size = 0;
    return Q;
}

bool QueueAChangeCapacity(QueueA* Q, size_t capacity)
{
    void* array = realloc(Q->array, Q->data_size * capacity);
    if(!array) {
        return false;
    }
    Q->array = array;
    Q->capacity = capacity;
    if(Q->capacity < Q->size) {
        Q->back = Q->capacity;
        Q->size = Q->capacity;
    }
    return true;
}

void QueueADestroy(QueueA* Q)
{
    free(Q->array);
    Q->array = NULL;
    free(Q);
    Q = NULL;
}

size_t QueueASize(QueueA* Q)
{
    return Q->size;
}

bool QueueAEmpty(QueueA* Q)
{
    if(Q->size) {
        return false;
    }
    return true;
}

bool QueueAFull(QueueA* Q)
{
    if(Q->size != Q->capacity) {
        return false;
    }
    return true;
}

static inline void* DataAt(QueueA* Q, size_t index)
{
    return (char*)Q->array + (Q->data_size * index);
}

void* QueueAFront(QueueA* Q)
{
    return DataAt(Q, Q->front);
}

void* QueueABack(QueueA* Q)
{
    return DataAt(Q, Q->back - 1);
}

void QueueAEnqueue(QueueA* Q, void* data)
{
    if(Q->back == Q->capacity) {
        memmove(DataAt(Q, 0), DataAt(Q, Q->front), Q->size);
        Q->front = 0;
        Q->back = Q->size;
    }
    memcpy(DataAt(Q, Q->back), data, Q->data_size);
    Q->back = Q->back + 1;
    Q->size = Q->size + 1;
}

void QueueADequeue(QueueA* Q)
{
    Q->front = Q->front + 1;
    Q->size = Q->size - 1;
}
