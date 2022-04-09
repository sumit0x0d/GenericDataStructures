#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackArray {
    void *array;
    size_t data_size;
    size_t top;
    size_t capacity;
    size_t size;
} StackArray;

StackArray stack_array_create(size_t data_size, size_t capacity);
bool stack_array_change_capacity(StackArray *S, size_t capacity);
void stack_array_destroy(StackArray *S);

void *stack_array_peek(StackArray *S);
size_t stack_array_size(StackArray *S);

bool stack_array_push(StackArray *S, void *data);
bool stack_array_pop(StackArray *S);

#endif
