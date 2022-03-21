#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct DequeArray {
    int *array;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
} DequeArray;

DequeArray *deque_array_construct(size_t capacity);
void deque_array_distroy(DequeArray *D);

bool deque_array_push_front(DequeArray *D, int data);
bool deque_array_push_back(DequeArray *D, int data);
bool deque_array_pop_front(DequeArray *D);
bool deque_array_pop_back(DequeArray *D);


#endif
