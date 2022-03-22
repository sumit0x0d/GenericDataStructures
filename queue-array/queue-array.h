#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    void *array;
    size_t element_size;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
} Queue;

Queue queue_array_construct(size_t element_size, size_t capacity);
void queue_array_distroy(Queue *Q);

void *queue_array_front(Queue *Q);
void *queue_array_back(Queue *Q);
size_t queue_array_size(Queue *Q);

bool queue_array_enqueue(Queue *Q, void *data);
bool queue_array_dequeue(Queue *Q);

#endif
