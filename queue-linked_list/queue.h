#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinglyLinkedListNode {
    void *data;
    size_t data_type_size;
    struct SinglyLinkedListNode *next;
};

struct Queue {
    struct SinglyLinkedListNode *front;
    struct SinglyLinkedListNode *back;
    size_t size;
    void (*enqueue)(struct Queue *stack, void *data, size_t data_type_size);
    void (*dequeue)(struct Queue *stack);
};

struct Queue queue_construct();
void queue_distruct(struct Queue *queue);

#endif
