#include "stack.h"


struct Stack *stack_construct(size_t capacity)
{
    struct Stack *S = malloc(sizeof (struct Stack));
    assert(S);
    S->array = malloc(sizeof (sizeof (int) * capacity));
    assert(S->array);
    S->top = 0;
    S->size = 0;
    S->capacity = capacity;
    return S;
}

void stack_distroy(struct Stack *S)
{
    free(S->array);
    free(S);
}

void stack_push(struct Stack *S, int data)
{
    if(S->size < S->capacity) {
        S->array[S->top] = data;
        S->top = S->top + 1;
        S->size = S->size + 1;
    }
}

void stack_pop(struct Stack *S)
{
    if(S->size) {
        S->top = S->top - 1;
        S->size = S->size - 1;
    }
}
