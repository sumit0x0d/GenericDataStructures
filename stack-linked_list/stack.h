#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    void *data;
    StackNode *next;
} StackNode;

typedef struct Stack {
    StackNode *top;
    size_t data_type_size;
    size_t size;
} Stack;

Stack stack_construct(size_t data_type_size);
void stack_destruct(Stack *S);
bool stack_push(Stack *S, void *data);
bool stack_pop(Stack *S);

#endif
