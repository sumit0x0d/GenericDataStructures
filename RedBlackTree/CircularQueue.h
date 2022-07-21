#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "Node.h"

#include <stdlib.h>
#include <string.h>

typedef struct CircularQueue {
    Node* array;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
} CircularQueue;

static CircularQueue* CircularQueue_Create(size_t capacity)
{
    CircularQueue* CQ = (CircularQueue*)malloc(sizeof (CircularQueue));
    if(!CQ) {
        return NULL;
    }
    CQ->array = (Node*)malloc(sizeof (Node) * capacity);
    if(!CQ->array) {
        free(CQ);
        return NULL;
    }
    CQ->front = 0;
    CQ->back = 0;
    CQ->capacity = capacity;
    CQ->size = 0;
    return CQ;
}

static void CircularQueue_Destroy(CircularQueue* CQ)
{
    free(CQ->array);
    CQ->array = NULL;
    free(CQ);
    CQ = NULL;
}

static Node* CircularQueueFront(CircularQueue* CQ)
{
    return CQ->array + CQ->front;
}

static void CircularQueue_Enqueue(CircularQueue* CQ, Node* data)
{
    memcpy(CQ->array + CQ->back, data, sizeof (Node));
    CQ->back = (CQ->back + 1) % CQ->capacity;
    CQ->size = CQ->size + 1;
}

static void CircularQueue_Dequeue(CircularQueue* CQ)
{
    CQ->front = (CQ->front + 1) % CQ->capacity;
    CQ->size = CQ->size - 1;
}

#endif
