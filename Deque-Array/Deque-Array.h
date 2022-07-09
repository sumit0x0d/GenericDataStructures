#ifndef DEQUE_ARRAY_H
#define DEQUE_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct DequeA DequeA;

DequeA* DequeA_create(size_t data_size, size_t capacity);
bool DequeA_change_capacity(DequeA* D, size_t capacity);
void DequeA_destroy(DequeA* D);
size_t DequeA_size(DequeA* D);
bool DequeA_empty(DequeA* D);
bool DequeA_full(DequeA* D);
void* DequeA_front(DequeA* Q);
void* DequeA_back(DequeA* Q);
void DequeA_push_front(DequeA* D, void* data);
void DequeA_push_back(DequeA* D, void* data);
void DequeA_pop_front(DequeA* D);
void DequeA_pop_back(DequeA* D);

#endif
