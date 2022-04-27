#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueA QueueA;

QueueA* queue_array_create(size_t data_size, size_t capacity);
bool queue_array_change_capacity(QueueA* Q, size_t capacity);
void queue_array_destroy(QueueA* Q);

void* queue_array_front(QueueA* Q);
void* queue_array_back(QueueA* Q);
size_t queue_array_size(QueueA* Q);

bool queue_array_enqueue(QueueA* Q, void* data);
bool queue_array_dequeue(QueueA* Q);

#endif
