#ifndef PRIORITY_QUEUE_LINKED_LIST_H
#define PRIORITY_QUEUE_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct PriorityQueueLL PriorityQueueLL;

PriorityQueueLL* PriorityQueueLLCreate(size_t data_size);
void PriorityQueueLLDestroy(PriorityQueueLL* PQ);
size_t PriorityQueueLLSize(PriorityQueueLL* PQ);
bool PriorityQueueLLEmpty(PriorityQueueLL* PQ);
void* PriorityQueueLLFront(PriorityQueueLL* PQ);
void* PriorityQueueLLBack(PriorityQueueLL* PQ);
bool PriorityQueueLLEnqueue(PriorityQueueLL* PQ, void* data, void* priority);
void PriorityQueueLLDequeue(PriorityQueueLL* PQ);

#endif
