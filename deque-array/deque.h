#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Deque {
    int *array;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
} Deque;

Deque *deque_array_construct(size_t capacity);
void deque_distroy(Deque *D);
void deque_push_front(Deque *D, int data);
void deque_push_back(Deque *D, int data);
void deque_pop_front(Deque *D);
void deque_pop_back(Deque *D);


#endif
