#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct QueueA QueueA;

QueueA* QueueA_Create(size_t data_size, size_t capacity);
bool QueueA_ChangeCapacity(QueueA* Q, size_t capacity);
void QueueA_Destroy(QueueA* Q);
size_t QueueA_Size(QueueA* Q);
void* QueueA_Front(QueueA* Q);
void* QueueA_Back(QueueA* Q);
bool QueueA_Empty(QueueA* Q);
bool QueueA_Full(QueueA* Q);
void QueueA_Enqueue(QueueA* Q, void* data);
void QueueA_Dequeue(QueueA* Q);

#endif
