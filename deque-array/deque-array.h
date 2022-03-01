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
    void (*push_front)(struct Deque *deque, int data);
    void (*push_back)(struct Deque *deque, int data);
    void (*pop_front)(struct Deque *deque);
    void (*pop_back)(struct Deque *deque);
};

struct Deque *deque_array_construct(size_t capacity);
void deque_distroy(struct Deque *deque);


#endif
