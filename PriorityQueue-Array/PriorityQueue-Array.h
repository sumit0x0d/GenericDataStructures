#ifndef PRIORITY_QUEUE_ARRAY_H
#define PRIORITY_QUEUE_ARRAY_H

#include <stdlib.h>
#include <string.h>

typedef struct PriorityQueueA {
    void* array;
    size_t data_size;
    size_t priority_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
    int (*compare)(void* priority1, void* priority2);
} PriorityQueueA;

PriorityQueueA* PriorityQueueA_create(size_t data_size, size_t priority_size, size_t capacity,
    int (*compare)(void* priority1, void* priority2));
int PriorityQueueA_change_capacity(PriorityQueueA* PQ, size_t capacity);
void PriorityQueueA_destroy(PriorityQueueA* PQ);

void* PriorityQueueA_front(PriorityQueueA* PQ);
void* PriorityQueueA_back(PriorityQueueA* PQ);

void PriorityQueueA_enqueue(PriorityQueueA* PQ, void* data, void* priority);
void PriorityQueueA_dequeue(PriorityQueueA* PQ);

#endif
