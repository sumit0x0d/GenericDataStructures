#ifndef PRIORITY_QUEUE_BINARY_HEAP_H
#define PRIORITY_QUEUE_BINARY_HEAP_H

#include <stdlib.h>
#include <string.h>

typedef struct PriorityQueueBHNode {
    void* data;
    void* priority;
    struct PriorityQueueBHNode* left;
    struct PriorityQueueBHNode* right;
    struct PriorityQueueBHNode* parent;
} PriorityQueueBHNode;

typedef struct PriorityQueueBH {
    PriorityQueueBHNode* root;
    size_t data_size;
    size_t priority_size;
    size_t size;
    int (*compare)(void* priority1, void* priority2);
} PriorityQueueBH;

PriorityQueueBH* PriorityQueueBH_create(size_t data_size, size_t priority_size,
    int (*compare)(void* priority1, void* priority2));
void PriorityQueueBH_destroy(PriorityQueueBH* PQ);

void* PriorityQueueBH_root(PriorityQueueBH* PQ);

int PriorityQueueBH_enqueue(PriorityQueueBH* PQ, void* data, void* priority);
void PriorityQueueBH_dequeue(PriorityQueueBH* PQ);

#endif
