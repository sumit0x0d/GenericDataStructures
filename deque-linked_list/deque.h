#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DequeNode {
    void *data;
    DequeNode *previous;
    DequeNode *next;
} DequeNode;

typedef struct Deque {
    DequeNode *front;
    DequeNode *back;
    size_t data_type_size;
    size_t size;
} Deque;

Deque deque_construct(size_t data_type_size);
void deque_destruct(Deque *D);
bool deque_push_front(Deque *D, void *data);
bool deque_push_back(Deque *D, void *data);
bool deque_pop_front(Deque *D);
bool deque_pop_back(Deque *D);

#endif
