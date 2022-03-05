#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>
#include <string.h>

struct DequeNode {
    void *data;
    size_t data_type_size;
    struct DequeNode *previous;
    struct DequeNode *next;
};

struct Deque {
    struct DequeNode *front;
    struct DequeNode *back;
    size_t size;
    void (*push_front)(struct Deque *deque, void *data, size_t data_type_size);
    void (*push_back)(struct Deque *deque, void *data, size_t data_type_size);
    void (*pop_front)(struct Deque *deque);
    void (*pop_back)(struct Deque *deque);
};

struct Deque *deque_construct();
void deque_distruct(struct Deque *deque);

#endif
