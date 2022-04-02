#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueArray {
    void *array;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
} QueueArray;

QueueArray queue_array_create(size_t capacity);
void queue_array_destroy(QueueArray *Q);

void *queue_array_front(QueueArray *Q, size_t data_size);
void *queue_array_back(QueueArray *Q, size_t data_size);
size_t queue_array_size(QueueArray *Q);

bool queue_array_enqueue(QueueArray *Q, void *data, size_t data_size);
bool queue_array_dequeue(QueueArray *Q);

#endif
