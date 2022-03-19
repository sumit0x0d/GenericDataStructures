#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue {
    void *array;
    size_t data_type_size;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
};

struct Queue queue_construct(size_t data_type_size, size_t capacity);
void queue_distroy(struct Queue *queue);
bool queue_enqueue(struct Queue *Q, void *data);

#endif
