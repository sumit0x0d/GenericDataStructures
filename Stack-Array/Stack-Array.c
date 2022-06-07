#include "Stack-Array.h"

static inline void* data_at(StackA* S, size_t index);

StackA* StackA_create(size_t data_size, size_t capacity)
{
    StackA* S = malloc(sizeof (StackA));
    if(!S) {
        return NULL;
    }
    S->array = malloc(data_size * capacity);
    if(!S->array) {
        free(S);
        return NULL;
    }
    S->data_size = data_size;
    S->capacity = capacity;
    S->size = 0;
    return S;
}

int StackA_change_capacity(StackA* S, size_t capacity)
{
    void* array = realloc(S->array, S->data_size * capacity);
    if(!array) {
        return 0;
    }
    S->array = array;
    S->capacity = capacity;
    if(S->capacity < S->size) {
        S->size = capacity;
    }
    return 1;
}

void StackA_destroy(StackA* S)
{
    free(S->array);
    S->array = NULL;
    free(S);
    S = NULL;
}

static inline void* data_at(StackA* S, size_t index)
{
    return (char*)S->array + (S->data_size * index);
}

void* StackA_top(StackA* S)
{
    return data_at(S, S->size - 1);
}

void StackA_push(StackA* S, void* data)
{
    memcpy(data_at(S, S->size), data, S->data_size);
    S->size = S->size + 1;
}

void StackA_pop(StackA* S)
{
    S->size = S->size - 1;
}
