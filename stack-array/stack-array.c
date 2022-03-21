#include "stack-array.h"


Stack *stack_construct(size_t capacity)
{
    Stack *S = malloc(sizeof (Stack));
    assert(S);
    S->array = malloc(sizeof (sizeof (int) * capacity));
    assert(S->array);
    S->top = 0;
    S->size = 0;
    S->capacity = capacity;
    return S;
}

void stack_distroy(Stack *S)
{
    free(S->array);
    free(S);
}

void stack_push(Stack *S, int data)
{
    if(S->size < S->capacity) {
        S->array[S->top] = data;
        S->top = S->top + 1;
        S->size = S->size + 1;
    }
}

void stack_pop(Stack *S)
{
    if(S->size) {
        S->top = S->top - 1;
        S->size = S->size - 1;
    }
}
