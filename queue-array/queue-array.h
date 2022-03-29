#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueArray {
    void *array;
    size_t element_size;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
} QueueArray;

QueueArray queue_array_create(size_t element_size, size_t capacity);
void queue_array_distroy(QueueArray *Q);

void *queue_array_front(QueueArray *Q);
void *queue_array_back(QueueArray *Q);
size_t queue_array_size(QueueArray *Q);

bool queue_array_enqueue(QueueArray *Q, void *data);
bool queue_array_dequeue(QueueArray *Q);

#endif
