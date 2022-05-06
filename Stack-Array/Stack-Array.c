#include "Stack-Array.h"

StackA* StackA_create(size_t data_size, size_t capacity);
bool StackA_change_capacity(StackA* S, size_t capacity);
void StackA_destroy(StackA* S);

bool StackA_push(StackA* S, void* data);
bool StackA_pop(StackA* S);

void* StackA_peek(StackA* S);

StackA* StackA_create(size_t data_size, size_t capacity)
{
    StackA* S = malloc(sizeof (StackA));
    if(!S) {
        return NULL;
    }
    S->array = malloc(data_size * capacity);
    if(!S->array) {
        return NULL;
    }
    S->data_size = data_size;
    S->capacity = capacity;
    S->size = 0;
    return S;
}

bool StackA_change_capacity(StackA* S, size_t capacity)
{
    if(!capacity) {
        return false;
    }
    void* array = realloc(S->array, S->data_size * capacity);
    if(!array) {
        return false;
    }
    S->array = array;
    S->capacity = capacity;
    return true;
}

void StackA_destroy(StackA* S)
{
    free(S->array);
    S->array = NULL;
    free(S);
    S = NULL;
}

bool StackA_push(StackA* S, void* data)
{
    if(S->size == S->capacity) {
        return false;
    }
    memcpy((char* )S->array + (S->data_size * S->size), data, S->data_size);
    S->size = S->size + 1;
    return true;
}

bool StackA_pop(StackA* S)
{
    if(!S->size){
        return false;
    }
    S->size = S->size - 1;
    return true;
}

void* StackA_peek(StackA* S)
{
    if(!S->size) {
        return NULL;
    }
    return (char*)S->array + (S->size - 1);
}
