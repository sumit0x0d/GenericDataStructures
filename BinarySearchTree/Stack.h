#ifndef STACK_H
#define STACK_H

#include "Node.h"

#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    Node* array;
    size_t capacity;
    size_t size;
} Stack;

static Stack* StackCreate(size_t capacity)
{
    Stack* S = (Stack*)malloc(sizeof (Stack));
    if(!S) {
        return NULL;
    }
    S->array = (Node*)malloc(sizeof (Node) * capacity);
    if(!S->array) {
        free(S);
        return NULL;
    }
    S->capacity = capacity;
    S->size = 0;
    return S;
}

static void StackDestroy(Stack* S)
{
    free(S->array);
    S->array = NULL;
    free(S);
    S = NULL;
}

static Node* Stack_top(Stack* S)
{
    return S->array + S->size;
}

static void StackPush(Stack* S, Node* data)
{
    memcpy(S->array + S->size, data, sizeof (Node));
    S->size = S->size + 1;
}

static void StackPop(Stack* S)
{
    S->size = S->size - 1;
}

#endif
