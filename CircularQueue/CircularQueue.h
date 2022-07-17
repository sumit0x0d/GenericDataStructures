#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct CircularQueue CircularQueue;

CircularQueue* CircularQueueCreate(size_t data_size, size_t capacity);
void CircularQueueDestroy(CircularQueue *CQ);
size_t CircularQueueSize(CircularQueue *CQ);
bool CircularQueueEmpty(CircularQueue *CQ);
bool CircularQueueFull(CircularQueue *CQ);
void* CircularQueueFront(CircularQueue* CQ);
void* CircularQueueBack(CircularQueue* CQ);
void CircularQueueEnqueue(CircularQueue* CQ, void* data);
void CircularQueueDequeue(CircularQueue* CQ);

#endif
