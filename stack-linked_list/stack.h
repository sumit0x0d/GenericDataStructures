#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>

struct StackNode {
    void *data;
    struct StackNode *next;
};

struct Stack {
    struct StackNode *top;
    size_t data_type_size;
    size_t size;
};

struct Stack stack_construct(size_t data_type_size);
void stack_destruct(struct Stack *S);
bool stack_push(struct Stack *S, void *data);
bool stack_pop(struct Stack *S);

#endif
