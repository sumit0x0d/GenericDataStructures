#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QueueNode {
    void *data;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front;
    struct QueueNode *back;
    size_t data_type_size;
    size_t size;
    void (*enqueue)(struct Queue *stack, void *data);
    void (*dequeue)(struct Queue *stack);
};

struct Queue queue_construct(size_t data_type_size);
void queue_destruct(struct Queue *queue);

#endif
