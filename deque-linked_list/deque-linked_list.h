#ifndef DEQUE_LINKED_LIST_H
#define DEQUE_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

struct LinkedListNode {
    void *data;
    size_t data_type_size;
    struct LinkedListNode *previous;
    struct LinkedListNode *next;
};

struct Deque {
    struct LinkedListNode *front;
    struct LinkedListNode *back;
    size_t size;
    void (*push_front)(struct Deque *deque, void *data, size_t data_type_size);
    void (*push_back)(struct Deque *deque, void *data, size_t data_type_size);
    void (*pop_front)(struct Deque *deque);
    void (*pop_back)(struct Deque *deque);
};

struct Deque *deque_construct();
void deque_distruct(struct Deque *deque);

#endif
