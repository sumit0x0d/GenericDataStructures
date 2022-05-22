#include "CircularQueue.h"

CircularQueue* CircularQueue_create(size_t data_size, size_t capacity);
void CircularQueue_destroy(CircularQueue *CQ);

static inline void* data_at(CircularQueue* CQ, size_t index);

void* CircularQueue_front(CircularQueue* CQ);
void* CircularQueue_back(CircularQueue* CQ);

void CircularQueue_enqueue(CircularQueue* CQ, void* data);
void CircularQueue_dequeue(CircularQueue* CQ);

CircularQueue* CircularQueue_create(size_t data_size, size_t capacity)
{
    CircularQueue* CQ = malloc(sizeof (CircularQueue));
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

void CircularQueue_destroy(CircularQueue *CQ)
{
    free(CQ->array);
    CQ->array = NULL;
    free(CQ);
    CQ = NULL;
}

static inline void* data_at(CircularQueue* CQ, size_t index)
{
    return (char*)CQ->array + (CQ->data_size * index);
}

void* CircularQueue_front(CircularQueue* CQ)
{
    return data_at(CQ, CQ->front);
}

void* CircularQueue_back(CircularQueue* CQ)
{
    return data_at(CQ, CQ->back - 1);
}

void CircularQueue_enqueue(CircularQueue* CQ, void* data)
{
    memcpy(data_at(CQ, CQ->back), data, CQ->data_size);
    CQ->back = (CQ->back + 1) % CQ->capacity;
    CQ->size = CQ->size + 1;
}

void CircularQueue_dequeue(CircularQueue* CQ)
{
    CQ->front = (CQ->front + 1) % CQ->capacity;
    CQ->size = CQ->size - 1;
}
