#include "circular_queue.h"

CircularQueue* CircularQueue_create(size_t data_size, size_t capacity);
void CircularQueue_destroy(CircularQueue *CQ);

bool CircularQueue_enqueue(CircularQueue* CQ, void* data);
bool CircularQueue_dequeue(CircularQueue* CQ);

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

bool CircularQueue_enqueue(CircularQueue* CQ, void* data)
{
    memcpy((char*)CQ->array + (CQ->data_size * CQ->back), data, CQ->data_size);
    CQ->back = (CQ->back + 1) % CQ->capacity;
    CQ->size = CQ->size + 1;
    return true;
}

bool CircularQueue_dequeue(CircularQueue* CQ)
{
    if(!CQ->size) {
        return false;
    }
    CQ->front = (CQ->front + 1) % CQ->capacity;
    CQ->size = CQ->size - 1;
    return true;
}
