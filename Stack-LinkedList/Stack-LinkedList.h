#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

typedef struct StackLLNode {
    void* data;
    struct StackLLNode* next;
} StackLLNode;

typedef struct StackLL {
    StackLLNode* top;
    size_t data_size;
    size_t size;
} StackLL;

StackLL* StackLL_create(size_t data_size);
void StackLL_destroy(StackLL* S);

int StackLL_push(StackLL* S, void* data);
void StackLL_pop(StackLL* S);

void* StackLL_top(StackLL* S);

#endif
