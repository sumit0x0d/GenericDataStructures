#ifndef DEQUE_ARRAY_H
#define DEQUE_ARRAY_H


#include <stdio.h>
#include <stdlib.h>

struct Deque {
    int *array;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
};

void deque_print(struct Deque *deque);
struct Deque *deque_array_construct(size_t capacity);
void deque_distroy(struct Deque *deque);
void deque_push_front(struct Deque *deque, int data);
void deque_push_back(struct Deque *deque, int data);
void deque_pop_front(struct Deque *deque);
void deque_pop_back(struct Deque *deque);

#endif
