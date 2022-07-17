#include "Stack-Array.h"

#include <stdlib.h>
#include <string.h>

struct StackA {
    void* array;
    size_t data_size;
    size_t capacity;
    size_t size;
};

StackA* StackACreate(size_t data_size, size_t capacity)
{
    StackA* S = (StackA*)malloc(sizeof (StackA));
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

bool StackAChangeCapacity(StackA* S, size_t capacity)
{
    void* array = realloc(S->array, S->data_size * capacity);
    if(!array) {
        return false;
    }
    S->array = array;
    S->capacity = capacity;
    if(S->capacity < S->size) {
        S->size = capacity;
    }
    return true;
}

void StackADestroy(StackA* S)
{
    free(S->array);
    S->array = NULL;
    free(S);
    S = NULL;
}

size_t StackASize(StackA* S)
{
    return S->size;
}

bool StackAEmpty(StackA* S)
{
    if(S->size) {
        return false;
    }
    return true;
}

bool StackAFull(StackA* S)
{
    if(S->size != S->capacity) {
        return false;
    }
    return true;
}

static inline void* DataAt(StackA* S, size_t index)
{
    return (char*)S->array + (S->data_size * index);
}

void* StackATop(StackA* S)
{
    return DataAt(S, S->size - 1);
}

void StackAPush(StackA* S, void* data)
{
    memcpy(DataAt(S, S->size), data, S->data_size);
    S->size = S->size + 1;
}

void StackAPop(StackA* S)
{
    S->size = S->size - 1;
}
