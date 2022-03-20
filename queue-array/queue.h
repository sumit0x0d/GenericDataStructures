#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    void *array;
    size_t data_type_size;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
} Queue;

Queue queue_construct(size_t data_type_size, size_t capacity);
void queue_distroy(Queue *queue);
bool queue_enqueue(Queue *Q, void *data);

#endif
