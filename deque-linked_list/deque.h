#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>
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
};

struct Deque deque_construct(size_t data_type_size);
void deque_destruct(struct Deque *D);
bool deque_push_front(struct Deque *D, void *data);
bool deque_push_back(struct Deque *D, void *data);
bool deque_pop_front(struct Deque *D);
bool deque_pop_back(struct Deque *D);

#endif
