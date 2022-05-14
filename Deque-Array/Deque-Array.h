#ifndef DEQUE_ARRAY_H
#define DEQUE_ARRAY_H

#include <stdlib.h>
#include <string.h>

typedef struct DequeA {
    void* array;
    size_t data_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
} DequeA;

DequeA* DequeA_create(size_t data_size, size_t capacity);
int DequeA_change_capacity(DequeA* D, size_t capacity);
void DequeA_destroy(DequeA* D);

void DequeA_push_front(DequeA* D, void* data);
void DequeA_push_back(DequeA* D, void* data);
void DequeA_pop_front(DequeA* D);
void DequeA_pop_back(DequeA* D);

void* DequeA_front(DequeA* Q);
void* DequeA_back(DequeA* Q);

#endif
