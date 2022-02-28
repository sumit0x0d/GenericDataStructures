#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdlib.h>

struct Stack {
    int *array;
    size_t top;
    size_t size;
    size_t capacity;
};

void stack_print(struct Stack *stack);
struct Stack *stack_construct(size_t capacity);
void stack_distroy(struct Stack *stack);
void stack_push(struct Stack *stack, int data);
void stack_pop(struct Stack *stack);

#endif
