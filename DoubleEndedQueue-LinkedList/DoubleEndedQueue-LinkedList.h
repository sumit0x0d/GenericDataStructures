#ifndef DOUBLE_ENDED_QUEUE_LINKED_LIST_H
#define DOUBLE_ENDED_QUEUE_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct DoubleEndedQueueLL DoubleEndedQueueLL;

DoubleEndedQueueLL* DoubleEndedQueueLL_Create(size_t data_size);
void DoubleEndedQueueLL_Destroy(DoubleEndedQueueLL* DEQ);
size_t DoubleEndedQueueLL_Size(DoubleEndedQueueLL* DEQ);
bool DoubleEndedQueueLL_Empty(DoubleEndedQueueLL* DEQ);
void* DoubleEndedQueueLL_Front(DoubleEndedQueueLL* DEQ);
void* DoubleEndedQueueLL_Back(DoubleEndedQueueLL* DEQ);
bool DoubleEndedQueueLL_PushFront(DoubleEndedQueueLL* DEQ, void* data);
bool DoubleEndedQueueLL_PushBack(DoubleEndedQueueLL* DEQ, void* data);
void DoubleEndedQueueLL_PopFront(DoubleEndedQueueLL* DEQ);
void DoubleEndedQueueLL_PopBack(DoubleEndedQueueLL* DEQ);
void DoubleEndedQueueLL_Traverse(DoubleEndedQueueLL* DEQ, void (*function)(void* data));

#endif
