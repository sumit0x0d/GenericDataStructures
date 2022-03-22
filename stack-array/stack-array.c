#include "stack-array.h"

StackArray stack_array_construct(size_t element_size, size_t capacity);
void stack_array_distroy(StackArray *S);

void *stack_array_peek(StackArray *S);
size_t stack_array_size(StackArray *S);

bool stack_array_push(StackArray *S, void *data);
bool stack_array_pop(StackArray *S);

StackArray stack_array_construct(size_t element_size, size_t capacity)
{
    StackArray S;

    S.array = NULL;
    S.element_size = element_size;
    S.top = 0;
    S.size = 0;
    S.capacity = capacity;

    return S;
}

void stack_array_distroy(StackArray *S)
{
    free(S->array);
    S->array = NULL;

    S->top = 0;
    S->size = 0;
}

void *stack_array_peek(StackArray *S)
{
    return (char *)S->array + (S->element_size * S->top);
}

size_t stack_array_size(StackArray *S)
{
    return S->size;
}

bool stack_array_push(StackArray *S, void *data)
{
    if(!S->array) {
        S->array = malloc(S->element_size * S->capacity);
        if(!S->array) return false;
    }

    if(S->top == S->capacity) return false;

    memcpy((char *)S->array + (S->element_size * S->top), data, S->element_size);

    S->top = S->top + 1;
    
    S->size = S->size + 1;

    return true;
}

bool stack_array_pop(StackArray *S)
{
    if(!S->size) return false;

    S->top = S->top - 1;

    S->size = S->size - 1;

    return true;
}
