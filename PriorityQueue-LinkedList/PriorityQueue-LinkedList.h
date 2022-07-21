#ifndef PRIORITY_QUEUE_LINKED_LIST_H
#define PRIORITY_QUEUE_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct PriorityQueueLL PriorityQueueLL;

PriorityQueueLL* PriorityQueueLL_Create(size_t data_size);
void PriorityQueueLL_Destroy(PriorityQueueLL* PQ);
size_t PriorityQueueLL_Size(PriorityQueueLL* PQ);
bool PriorityQueueLL_Empty(PriorityQueueLL* PQ);
void* PriorityQueueLL_Front(PriorityQueueLL* PQ);
void* PriorityQueueLL_Back(PriorityQueueLL* PQ);
bool PriorityQueueLL_Enqueue(PriorityQueueLL* PQ, void* data, void* priority);
void PriorityQueueLL_Dequeue(PriorityQueueLL* PQ);

#endif
