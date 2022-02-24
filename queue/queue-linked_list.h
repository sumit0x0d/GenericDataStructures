#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H


#include <stdio.h>
#include <stdlib.h>

struct LinkedListNode {
    void *data;
    size_t data_type_size;
    struct LinkedListNode *next;
};

struct Queue {
    struct LinkedListNode *front;
    struct LinkedListNode *back;
    size_t size;
    void (*print)(struct Queue *stack);
    void (*enqueue)(struct Queue *stack, void *data, size_t data_type_size);
    void (*dequeue)(struct Queue *stack);
};

struct Queue queue_construct();
void queue_distruct(struct Queue *queue);

#endif
