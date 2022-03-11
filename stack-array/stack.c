#include "stack.h"


struct Stack *stack_construct(size_t capacity)
{
    struct Stack *stack = malloc(sizeof (struct Stack));
    assert(stack);
    stack->array = malloc(sizeof (sizeof (int) * capacity));
    assert(stack->array);
    stack->top = 0;
    stack->size = 0;
    stack->capacity = capacity;
    return stack;
}

void stack_distroy(struct Stack *stack)
{
    free(stack->array);
    free(stack);
}

void stack_push(struct Stack *stack, int data)
{
    if(stack->size < stack->capacity) {
        stack->array[stack->top] = data;
        stack->top = stack->top + 1;
        stack->size = stack->size + 1;
    }
}

void stack_pop(struct Stack *stack)
{
    if(stack->size) {
        stack->top = stack->top - 1;
        stack->size = stack->size - 1;
    }
}
