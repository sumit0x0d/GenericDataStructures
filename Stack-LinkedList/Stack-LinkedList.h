#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct StackLL StackLL;

StackLL* StackLL_Create(size_t data_size);
void StackLL_Destroy(StackLL* S);
size_t StackLL_Size(StackLL* S);
bool StackLL_Empty(StackLL* S);
void* StackLL_Top(StackLL* S);
bool StackLL_Push(StackLL* S, void* data);
void StackLLPop(StackLL* S);
void StackLL_Traverse(StackLL* S, void (*function)(void* data));

#endif
