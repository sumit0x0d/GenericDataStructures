#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackArray {
    void *array;
    size_t element_size;
    size_t top;
    size_t size;
    size_t capacity;
} StackArray;

StackArray stack_array_construct(size_t element_size, size_t capacity);
void stack_array_distroy(StackArray *S);
bool stack_array_push(StackArray *S, void *data);
bool stack_array_pop(StackArray *S);

#endif
