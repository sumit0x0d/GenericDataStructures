#include "CircularQueue.h"

CircularQueue* CircularQueue_create(size_t data_size, size_t capacity);
void CircularQueue_destroy(CircularQueue *CQ);

void CircularQueue_enqueue(CircularQueue* CQ, void* data);
void CircularQueue_dequeue(CircularQueue* CQ);

void* CircularQueue_front(CircularQueue* CQ);
void* CircularQueue_back(CircularQueue* CQ);

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

void* CircularQueue_front(CircularQueue* CQ)
{
    return (char*)CQ->array + (CQ->data_size * CQ->front);
}

void* CircularQueue_back(CircularQueue* CQ)
{
    return (char*)CQ->array + (CQ->data_size * (CQ->back - 1));
}

void CircularQueue_enqueue(CircularQueue* CQ, void* data)
{
    memcpy((char*)CircularQueue_back(CQ) + CQ->data_size, data, CQ->data_size);
    CQ->back = (CQ->back + 1) % CQ->capacity;
    CQ->size = CQ->size + 1;
}

void CircularQueue_dequeue(CircularQueue* CQ)
{
    CQ->front = (CQ->front + 1) % CQ->capacity;
    CQ->size = CQ->size - 1;
}
