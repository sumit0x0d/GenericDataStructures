#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueNode {
    void *data;
    size_t data_type_size;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *back;
    size_t size;
} Queue;

Queue queue_construct();
void queue_destruct(Queue *);

QueueNode *queue_front(Queue *);
QueueNode *queue_back(Queue *);
size_t queue_size(Queue *);

bool queue_enqueue(Queue *, void *, size_t);
bool queue_dequeue(Queue *);

#endif
