#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueNode {
    void *data;
    QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *back;
    size_t data_type_size;
    size_t size;
} Queue;

Queue queue_construct(size_t data_type_size);
void queue_destruct(Queue *Q);
bool queue_enqueue(Queue *Q, void *data);
bool queue_dequeue(Queue *Q);

#endif
