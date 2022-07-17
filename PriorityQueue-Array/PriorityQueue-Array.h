#ifndef PRIORITY_QUEUE_ARRAY_H
#define PRIORITY_QUEUE_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct PriorityQueueA PriorityQueueA;

PriorityQueueA* PriorityQueueACreate(size_t data_size, size_t priority_size, size_t capacity,
    int (*compare_function)(void* priority1, void* priority2));
bool PriorityQueueAChangeCapacity(PriorityQueueA* PQ, size_t capacity);
void PriorityQueueADestroy(PriorityQueueA* PQ);
size_t PriorityQueueASize(PriorityQueueA* PQ);
bool PriorityQueueAEmpty(PriorityQueueA* PQ);
bool PriorityQueueAFull(PriorityQueueA *PQ);
void* PriorityQueueAFront(PriorityQueueA* PQ);
void* PriorityQueueABack(PriorityQueueA* PQ);
void PriorityQueueAEnqueue(PriorityQueueA* PQ, void* data, void* priority);
void PriorityQueueADequeue(PriorityQueueA* PQ);

#endif
