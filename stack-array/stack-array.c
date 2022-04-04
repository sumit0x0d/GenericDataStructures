#include "stack-array.h"

StackArray stack_array_create(size_t data_size, size_t capacity);
void stack_array_destroy(StackArray *S);

void *stack_array_peek(StackArray *S);
size_t stack_array_size(StackArray *S);

bool stack_array_push(StackArray *S, void *data);
bool stack_array_pop(StackArray *S);

StackArray stack_array_create(size_t data_size, size_t capacity)
{
    StackArray S;

    S.array = NULL;
    S.data_size = data_size;
    S.top = 0;
    S.capacity = capacity;
    S.size = 0;

    return S;
}

void stack_array_destroy(StackArray *S)
{
    free(S->array);
    S->array = NULL;

    S->top = 0;
    S->size = 0;
}

void *stack_array_peek(StackArray *S)
{
    if(!S->array) return NULL;

    return (char *)S->array + (S->data_size * S->top);
}

size_t stack_array_size(StackArray *S)
{
    return S->size;
}

bool stack_array_push(StackArray *S, void *data)
{
    if(!S->array) {
        if(!S->data_size || !S->capacity) return false;

        S->array = malloc(S->data_size * S->capacity);
        if(!S->array) return false;
    }

    if(S->top == S->capacity) return false;

    memcpy((char *)S->array + (S->data_size * S->top), data, S->data_size);

    S->top = S->top + 1;

    S->size = S->size + 1;

    return true;
}

bool stack_array_pop(StackArray *S)
{
    if(!S->top) return false;

    S->top = S->top - 1;

    S->size = S->size - 1;

    return true;
}
