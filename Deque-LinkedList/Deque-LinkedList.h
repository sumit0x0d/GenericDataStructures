#ifndef DEQUE_LINKED_LIST_H
#define DEQUE_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct DequeLL DequeLL;

DequeLL* DequeLLCreate(size_t data_size);
void DequeLLDestroy(DequeLL* D);
size_t DequeLLSize(DequeLL* D);
bool DequeLLEmpty(DequeLL* D);
void* DequeLLFront(DequeLL* Q);
void* DequeLLBack(DequeLL* Q);
bool DequeLLPushFront(DequeLL* D, void* data);
bool DequeLLPushBack(DequeLL* D, void* data);
void DequeLLPopFront(DequeLL* D);
void DequeLLPopBack(DequeLL* D);
void DequeLLTraverse(DequeLL* D, void (*function)(void* data));

#endif
