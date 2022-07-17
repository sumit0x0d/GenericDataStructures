#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct StackLL StackLL;

StackLL* StackLLCreate(size_t data_size);
void StackLLDestroy(StackLL* S);
size_t StackLLSize(StackLL* S);
bool StackLLEmpty(StackLL* S);
void* StackLLTop(StackLL* S);
bool StackLLPush(StackLL* S, void* data);
void StackLLPop(StackLL* S);
void StackLLTraverse(StackLL* S, void (*function)(void* data));

#endif
