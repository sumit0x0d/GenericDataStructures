#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct CircularQueue CircularQueue;

CircularQueue* CircularQueue_create(size_t data_size, size_t capacity);
void CircularQueue_destroy(CircularQueue *CQ);
bool CircularQueue_empty(CircularQueue *CQ);
bool CircularQueue_full(CircularQueue *CQ);
size_t CircularQueue_size(CircularQueue *CQ);

void* CircularQueue_front(CircularQueue* CQ);
void* CircularQueue_back(CircularQueue* CQ);

void CircularQueue_enqueue(CircularQueue* CQ, void* data);
void CircularQueue_dequeue(CircularQueue* CQ);

#endif
