#include "CircularQueue.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct CircularQueue {
    void* array;
    size_t data_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
};

CircularQueue* CircularQueueCreate(size_t data_size, size_t capacity)
{
    CircularQueue* CQ = (CircularQueue*)malloc(sizeof (CircularQueue));
    if(!CQ) {
        return NULL;
    }
    CQ->array = malloc(data_size * capacity);
    if(!CQ->array) {
        free(CQ);
        CQ = NULL;
        return NULL;
    }
    CQ->data_size = data_size;
    CQ->front = 0;
    CQ->back = 0;
    CQ->capacity = capacity;
    CQ->size = 0;
    return CQ;
}

void CircularQueueDestroy(CircularQueue *CQ)
{
    free(CQ->array);
    CQ->array = NULL;
    free(CQ);
    CQ = NULL;
}

size_t CircularQueueSize(CircularQueue *CQ)
{
    return CQ->size;
}

bool CircularQueueEmpty(CircularQueue *CQ)
{
    if(CQ->size) {
        return false;
    }
    return true;
}

bool CircularQueueFull(CircularQueue *CQ)
{
    if(CQ->size != CQ->capacity) {
        return false;
    }
    return true;
}

static inline void* DataAt(CircularQueue* CQ, size_t index)
{
    return (char*)CQ->array + (CQ->data_size * index);
}

void* CircularQueueFront(CircularQueue* CQ)
{
    return DataAt(CQ, CQ->front);
}

void* CircularQueueBack(CircularQueue* CQ)
{
    return DataAt(CQ, CQ->back - 1);
}

void CircularQueueEnqueue(CircularQueue* CQ, void* data)
{
    memcpy(DataAt(CQ, CQ->back), data, CQ->data_size);
    CQ->back = (CQ->back + 1) % CQ->capacity;
    CQ->size = CQ->size + 1;
}

void CircularQueueDequeue(CircularQueue* CQ)
{
    CQ->front = (CQ->front + 1) % CQ->capacity;
    CQ->size = CQ->size - 1;
}
