#ifndef DEQUE_ARRAY_H
#define DEQUE_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DequeA DequeA;

DequeA* deque_array_create(size_t data_size, size_t capacity);
bool deque_array_change_capacity(DequeA* D, size_t capacity);
void deque_array_destroy(DequeA* D);

void* deque_array_front(DequeA* D);
void* deque_array_back(DequeA* D);
size_t deque_array_size(DequeA* D);

bool deque_array_push_front(DequeA* D, void* data);
bool deque_array_push_back(DequeA* D, void* data);
bool deque_array_pop_front(DequeA* D);
bool deque_array_pop_back(DequeA* D);

#endif
