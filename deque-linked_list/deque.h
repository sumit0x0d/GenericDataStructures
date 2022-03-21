#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DequeNode {
    void *data;
    size_t data_type_size;
    DequeNode *previous;
    DequeNode *next;
} DequeNode;

typedef struct Deque {
    DequeNode *front;
    DequeNode *back;
    size_t size;
} Deque;

Deque deque_construct();
void deque_destruct(Deque *);

bool deque_push_front(Deque *, void *, size_t);
bool deque_push_back(Deque *, void *, size_t);
bool deque_pop_front(Deque *);
bool deque_pop_back(Deque *);

#endif
