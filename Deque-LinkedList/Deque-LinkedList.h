#ifndef DEQUE_LINKED_LIST_H
#define DEQUE_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct DequeLL DequeLL;

DequeLL* DequeLL_create(size_t data_size);
void DequeLL_destroy(DequeLL* D);
size_t DequeLL_size(DequeLL* D);
bool DequeLL_empty(DequeLL* D);
void* DequeLL_front(DequeLL* Q);
void* DequeLL_back(DequeLL* Q);
bool DequeLL_push_front(DequeLL* D, void* data);
bool DequeLL_push_back(DequeLL* D, void* data);
void DequeLL_pop_front(DequeLL* D);
void DequeLL_pop_back(DequeLL* D);
void DequeLL_traverse(DequeLL* D, void (*function)(void* data));

#endif
