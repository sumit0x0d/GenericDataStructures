#ifndef DEQUE_LINKED_LIST_H
#define DEQUE_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DequeLL {
    struct Node* front;
    struct Node* back;
    size_t data_size;
    size_t size;
} DequeLL;

DequeLL* DequeLL_create(size_t data_size);
void DequeLL_destroy(DequeLL* D);

bool DequeLL_push_front(DequeLL* D, void* data);
bool DequeLL_push_back(DequeLL* D, void* data);
void DequeLL_pop_front(DequeLL* D);
void DequeLL_pop_back(DequeLL* D);

void* DequeLL_front(DequeLL* Q);
void* DequeLL_back(DequeLL* Q);

#endif
