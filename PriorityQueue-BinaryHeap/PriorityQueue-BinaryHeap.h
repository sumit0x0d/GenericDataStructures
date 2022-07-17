#ifndef PRIORITY_QUEUE_BINARY_HEAP_H
#define PRIORITY_QUEUE_BINARY_HEAP_H

#include <stdbool.h>
#include <stddef.h>

typedef struct PriorityQueueBH PriorityQueueBH;

PriorityQueueBH* PriorityQueueBHCreate(size_t data_size, size_t priority_size,
    int (*compare_function)(void* priority1, void* priority2));
void PriorityQueueBHDestroy(PriorityQueueBH* PQ);
size_t PriorityQueueBHSize(PriorityQueueBH* PQ);
void* PriorityQueueBH_root(PriorityQueueBH* PQ);
bool PriorityQueueBHEnqueue(PriorityQueueBH* PQ, void* data, void* priority);
void PriorityQueueBHDequeue(PriorityQueueBH* PQ);

#endif
