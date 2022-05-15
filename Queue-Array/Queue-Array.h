#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdlib.h>
#include <string.h>

typedef struct QueueA {
    void* array;
    size_t data_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
} QueueA;

QueueA* QueueA_create(size_t data_size, size_t capacity);
int QueueA_change_capacity(QueueA* Q, size_t capacity);
void QueueA_destroy(QueueA* Q);

void* QueueA_front(QueueA* Q);
void* QueueA_back(QueueA* Q);

void QueueA_enqueue(QueueA* Q, void* data);
void QueueA_dequeue(QueueA* Q);

#endif
