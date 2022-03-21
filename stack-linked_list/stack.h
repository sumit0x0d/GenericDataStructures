#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    void *data;
    size_t data_type_size;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    StackNode *top;
    size_t size;
} Stack;

Stack stack_construct();
void stack_destruct(Stack *);

StackNode *stack_peek(Stack *S);
size_t stack_size(Stack *S);

bool stack_push(Stack *, void *, size_t);
bool stack_pop(Stack *);

#endif
