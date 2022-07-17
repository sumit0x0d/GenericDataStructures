#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct QueueA QueueA;

QueueA* QueueACreate(size_t data_size, size_t capacity);
bool QueueAChangeCapacity(QueueA* Q, size_t capacity);
void QueueADestroy(QueueA* Q);
size_t QueueASize(QueueA* Q);
void* QueueAFront(QueueA* Q);
void* QueueABack(QueueA* Q);
bool QueueAEmpty(QueueA* Q);
bool QueueAFull(QueueA* Q);
void QueueAEnqueue(QueueA* Q, void* data);
void QueueADequeue(QueueA* Q);

#endif
