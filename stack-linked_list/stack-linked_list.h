#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackLLNode StackLLNode;
typedef struct StackLL StackLL;

StackLL* stack_linked_list_create(size_t data_size);
void stack_linked_list_destroy(StackLL* S);

void* stack_linked_list_peek(StackLL* S);
size_t stack_linked_list_size(StackLL* S);

bool stack_linked_list_push(StackLL* S, void* data);
bool stack_linked_list_pop(StackLL* S);

#endif
