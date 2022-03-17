#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdlib.h>

struct Stack {
    int *array;
    size_t top;
    size_t size;
    size_t capacity;
};

struct Stack *stack_construct(size_t capacity);
void stack_distroy(struct Stack *S);
bool stack_push(struct Stack *S, int data);
bool stack_pop(struct Stack *S);

#endif
