#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>

struct Deque {
    int *array;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
    void (*push_front)(struct Deque *D, int data);
    void (*push_back)(struct Deque *D, int data);
    void (*pop_front)(struct Deque *D);
    void (*pop_back)(struct Deque *D);
};

struct Deque *deque_array_construct(size_t capacity);
void deque_distroy(struct Deque *D);


#endif
