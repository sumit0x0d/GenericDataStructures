#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct QueueA QueueA;

QueueA* QueueA_create(size_t data_size, size_t capacity);
bool QueueA_change_capacity(QueueA* Q, size_t capacity);
void QueueA_destroy(QueueA* Q);
size_t QueueA_size(QueueA* Q);
void* QueueA_front(QueueA* Q);
void* QueueA_back(QueueA* Q);
bool QueueA_empty(QueueA* Q);
bool QueueA_full(QueueA* Q);
void QueueA_enqueue(QueueA* Q, void* data);
void QueueA_dequeue(QueueA* Q);

#endif
