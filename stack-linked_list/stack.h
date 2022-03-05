#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

struct SinglyLinkedListNode {
    void *data;
    size_t data_type_size;
    struct SinglyLinkedListNode *next;
};

struct Stack {
    struct SinglyLinkedListNode *top;
    size_t size;
    void (*push)(struct Stack *stack, void *data, size_t data_type_size);
    void (*pop)(struct Stack *stack);
};

struct Stack stack_construct();
void stack_distruct(struct Stack *stack);

#endif
