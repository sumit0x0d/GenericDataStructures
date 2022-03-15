#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>
#include <string.h>

struct DequeNode {
    void *data;
    struct DequeNode *previous;
    struct DequeNode *next;
};

struct Deque {
    struct DequeNode *front;
    struct DequeNode *back;
    size_t data_type_size;
    size_t size;
    void (*push_front)(struct Deque *D, void *data);
    void (*push_back)(struct Deque *D, void *data);
    void (*pop_front)(struct Deque *D);
    void (*pop_back)(struct Deque *D);
};

struct Deque deque_construct(size_t data_type_size);
void deque_destruct(struct Deque *D);

#endif
