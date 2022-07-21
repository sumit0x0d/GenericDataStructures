#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct CircularQueue CircularQueue;

CircularQueue* CircularQueue_Create(size_t data_size, size_t capacity);
void CircularQueue_Destroy(CircularQueue *CQ);
size_t CircularQueue_Size(CircularQueue *CQ);
bool CircularQueue_Empty(CircularQueue *CQ);
bool CircularQueue_Full(CircularQueue *CQ);
void* CircularQueue_Front(CircularQueue* CQ);
void* CircularQueue_Back(CircularQueue* CQ);
void CircularQueue_Enqueue(CircularQueue* CQ, void* data);
void CircularQueue_Dequeue(CircularQueue* CQ);

#endif
