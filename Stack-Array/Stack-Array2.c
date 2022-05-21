#include "Stack-Array2.h"

StackA* StackA_create(size_t data_size, size_t capacity);
int StackA_change_capacity(StackA* S, size_t capacity);
void StackA_destroy(StackA* S);

void* StackA_top(StackA* S);

void StackA_push(StackA* S, void* data);
void StackA_pop(StackA* S);

StackA* StackA_create(size_t data_size, size_t capacity)
{
    StackA* S = malloc(sizeof (StackA));
    if(!S) {
        return NULL;
    }
    S->array = malloc(sizeof (StackANode) * capacity);
    if(!S->array) {
        free(S);
        S = NULL;
        return NULL;
    }
    for(size_t i = 0; i < capacity; i++) {
        S->array[i].data = malloc(data_size);
        if(!S->array[i].data) {
            for(size_t j = i; j < i; j++) {
                free(S->array[j].data);
                S->array[j].data = NULL;
            }
            free(S->array);
            S->array = NULL;
            free(S);
            S = NULL;
            return NULL;
        }
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

void* StackA_top(StackA* S)
{
    return S->array[S->size - 1].data;
}

void StackA_push(StackA* S, void* data)
{
    memcpy(S->array[S->size].data, data, S->data_size);
    S->size = S->size + 1;
}

void StackA_pop(StackA* S)
{
    S->size = S->size - 1;
}
