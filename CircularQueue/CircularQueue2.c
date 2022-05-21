#include "CircularQueue2.h"

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
    CQ->array = malloc(sizeof (CircularQueueNode) * capacity);
    if(!CQ->array) {
        free(CQ);
        CQ = NULL;
        return NULL;
    }
    for(size_t i = 0; i < capacity; i++) {
        CQ->array[i].data = malloc(data_size);
        if(!CQ->array[i].data) {
            for(size_t j = i; j < i; j++) {
                free(CQ->array[j].data);
                CQ->array[j].data = NULL;
            }
            free(CQ->array);
            CQ->array = NULL;
            free(CQ);
            CQ = NULL;
            return NULL;
        }
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
    return CQ->array[CQ->front].data;
}

void* CircularQueue_back(CircularQueue* CQ)
{
    return CQ->array[CQ->back - 1].data;
}

void CircularQueue_enqueue(CircularQueue* CQ, void* data)
{
    memcpy(CQ->array[CQ->back].data, data, CQ->data_size);
    CQ->back = (CQ->back + 1) % CQ->capacity;
    CQ->size = CQ->size + 1;
}

void CircularQueue_dequeue(CircularQueue* CQ)
{
    CQ->front = (CQ->front + 1) % CQ->capacity;
    CQ->size = CQ->size - 1;
}
