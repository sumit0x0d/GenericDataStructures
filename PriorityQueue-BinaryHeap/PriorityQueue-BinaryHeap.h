#ifndef PRIORITY_QUEUE_BINARY_HEAP_H
#define PRIORITY_QUEUE_BINARY_HEAP_H

#include <stdbool.h>
#include <stddef.h>

typedef struct PriorityQueueBH PriorityQueueBH;

PriorityQueueBH* PriorityQueueBH_Create(size_t data_size, size_t priority_size,
    int (*compare)(void* priority1, void* priority2));
void PriorityQueueBH_Destroy(PriorityQueueBH* PQ);
size_t PriorityQueueBH_Size(PriorityQueueBH* PQ);
void* PriorityQueueBH_Root(PriorityQueueBH* PQ);
bool PriorityQueueBH_Enqueue(PriorityQueueBH* PQ, void* data, void* priority);
void PriorityQueueBH_Dequeue(PriorityQueueBH* PQ);

#endif
