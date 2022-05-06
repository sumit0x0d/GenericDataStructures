#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct CircularQueue {
    void* array;
    size_t data_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
} CircularQueue;

CircularQueue* CircularQueue_create(size_t data_size, size_t capacity);
void CircularQueue_destroy(CircularQueue *CQ);

bool CircularQueue_enqueue(CircularQueue* CQ, void* data);
bool CircularQueue_dequeue(CircularQueue* CQ);

void* CircularQueue_front(CircularQueue* CQ);
void* CircularQueue_back(CircularQueue* CQ);

#endif
