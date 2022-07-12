#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct StackLL StackLL;

StackLL* StackLL_create(size_t data_size);
void StackLL_destroy(StackLL* S);
size_t StackLL_size(StackLL* S);
bool StackLL_empty(StackLL* S);
void* StackLL_top(StackLL* S);
bool StackLL_push(StackLL* S, void* data);
void StackLL_pop(StackLL* S);
void StackLL_traverse(StackLL* S, void (*function)(void* data));

#endif
