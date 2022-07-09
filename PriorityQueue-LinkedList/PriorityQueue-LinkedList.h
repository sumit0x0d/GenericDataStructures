#ifndef PRIORITY_QUEUE_LINKED_LIST_H
#define PRIORITY_QUEUE_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct PriorityQueueLL PriorityQueueLL;

PriorityQueueLL* PriorityQueueLL_create(size_t data_size);
void PriorityQueueLL_destroy(PriorityQueueLL* PQ);
bool PriorityQueueLL_empty(PriorityQueueLL* PQ);
size_t PriorityQueueLL_size(PriorityQueueLL* PQ);

bool PriorityQueueLL_enqueue(PriorityQueueLL* PQ, void* data, void* priority);
void PriorityQueueLL_dequeue(PriorityQueueLL* PQ);

void* PriorityQueueLL_front(PriorityQueueLL* PQ);
void* PriorityQueueLL_back(PriorityQueueLL* PQ);

#endif
