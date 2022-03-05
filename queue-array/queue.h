#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct Queue {
    void *array;
    size_t data_type_size;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
};

void queue_print(struct Queue *queue);
struct Queue *queue_construct(size_t data_type_size, size_t capacity);
void queue_distroy(struct Queue *queue);
void queue_enqueue(struct Queue *queue, void *data);
void queue_dequeue(struct Queue *queue);

#endif
