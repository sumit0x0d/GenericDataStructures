#ifndef DEQUE_H
#define DEQUE_H

#ifndef DATA_TYPE
#define DATA_TYPE

enum {
    BOOL,
    CHAR,
    UNSIGNED_CHAR,
    SHORT,
    UNSIGNED_SHORT,
    INT,
    UNSIGNED_INT,
    FLOAT,
    LONG,
    UNSIGNED_LONG,
    DOUBLE,
    LONG_LONG,
    UNSIGNED_LONG_LONG,
    LONG_DOUBLE,
    STRING,
    STRUCT
};

#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DequeArray {
    void *array;
    size_t element_size;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
} DequeArray;

DequeArray deque_array_construct(size_t element_size, size_t capacity);
void deque_array_distroy(DequeArray *D);

void *deque_array_front(DequeArray *D);
void *deque_array_back(DequeArray *D);
size_t deque_array_size(DequeArray *D);

bool deque_array_push_front(DequeArray *D, void *data);
bool deque_array_push_back(DequeArray *D, void *data);
bool deque_array_pop_front(DequeArray *D);
bool deque_array_pop_back(DequeArray *D);

#endif
