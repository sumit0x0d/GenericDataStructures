#ifndef PRIORITY_QUEUE_ARRAY_H
#define PRIORITY_QUEUE_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct PriorityQueueA PriorityQueueA;

PriorityQueueA* PriorityQueueA_Create(size_t data_size, size_t priority_size, size_t capacity,
    int (*compare_function)(void* priority1, void* priority2));
bool PriorityQueueA_ChangeCapacity(PriorityQueueA* PQ, size_t capacity);
void PriorityQueueA_Destroy(PriorityQueueA* PQ);
size_t PriorityQueueA_Size(PriorityQueueA* PQ);
bool PriorityQueueA_Empty(PriorityQueueA* PQ);
bool PriorityQueueA_Full(PriorityQueueA *PQ);
void* PriorityQueueA_Front(PriorityQueueA* PQ);
void* PriorityQueueA_Back(PriorityQueueA* PQ);
void PriorityQueueA_Enqueue(PriorityQueueA* PQ, void* data, void* priority);
void PriorityQueueA_Dequeue(PriorityQueueA* PQ);

#endif
