#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

struct StackNode {
    void *data;
    size_t data_type_size;
    struct StackNode *next;
};

struct Stack {
    struct StackNode *top;
    size_t size;
    void (*push)(struct Stack *stack, void *data, size_t data_type_size);
    void (*pop)(struct Stack *stack);
};

struct Stack stack_construct();
void stack_distruct(struct Stack *stack);

#endif
