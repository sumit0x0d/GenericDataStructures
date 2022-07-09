#ifndef PRIORITY_QUEUE_ARRAY_H
#define PRIORITY_QUEUE_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct PriorityQueueA PriorityQueueA;

PriorityQueueA* PriorityQueueA_create(size_t data_size, size_t priority_size, size_t capacity,
    int (*compare)(void* priority1, void* priority2));
bool PriorityQueueA_change_capacity(PriorityQueueA* PQ, size_t capacity);
void PriorityQueueA_destroy(PriorityQueueA* PQ);
size_t PriorityQueueA_size(PriorityQueueA* PQ);
bool PriorityQueueA_empty(PriorityQueueA* PQ);
void* PriorityQueueA_front(PriorityQueueA* PQ);
void* PriorityQueueA_back(PriorityQueueA* PQ);
void PriorityQueueA_enqueue(PriorityQueueA* PQ, void* data, void* priority);
void PriorityQueueA_dequeue(PriorityQueueA* PQ);

#endif
