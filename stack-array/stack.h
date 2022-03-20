#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack {
    int *array;
    size_t top;
    size_t size;
    size_t capacity;
} Stack;

Stack *stack_construct(size_t capacity);
void stack_distroy(Stack *S);
bool stack_push(Stack *S, int data);
bool stack_pop(Stack *S);

#endif
