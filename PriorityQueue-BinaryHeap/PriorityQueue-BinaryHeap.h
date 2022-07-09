#ifndef PRIORITY_QUEUE_BINARY_HEAP_H
#define PRIORITY_QUEUE_BINARY_HEAP_H

#include <stdbool.h>
#include <stddef.h>

typedef struct PriorityQueueBH PriorityQueueBH;

PriorityQueueBH* PriorityQueueBH_create(size_t data_size, size_t priority_size,
    int (*compare)(void* priority1, void* priority2));
void PriorityQueueBH_destroy(PriorityQueueBH* PQ);

void* PriorityQueueBH_root(PriorityQueueBH* PQ);

bool PriorityQueueBH_enqueue(PriorityQueueBH* PQ, void* data, void* priority);
void PriorityQueueBH_dequeue(PriorityQueueBH* PQ);

#endif
