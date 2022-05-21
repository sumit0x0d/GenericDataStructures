#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdlib.h>
#include <string.h>

typedef struct CircularQueueNode {
    void* data;
} CircularQueueNode;

typedef struct CircularQueue {
    CircularQueueNode* array;
    size_t data_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
} CircularQueue;

CircularQueue* CircularQueue_create(size_t data_size, size_t capacity);
void CircularQueue_destroy(CircularQueue *CQ);

void CircularQueue_enqueue(CircularQueue* CQ, void* data);
void CircularQueue_dequeue(CircularQueue* CQ);

void* CircularQueue_front(CircularQueue* CQ);
void* CircularQueue_back(CircularQueue* CQ);

#endif
