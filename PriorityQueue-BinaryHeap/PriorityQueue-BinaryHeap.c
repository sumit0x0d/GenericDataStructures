#include "PriorityQueue-BinaryHeap.h"
#include "Node.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct PriorityQueueBH {
    Node* root;
    size_t data_size;
    size_t priority_size;
    size_t size;
    int (*compare_function)(void* priority1, void* priority2);
};

PriorityQueueBH* PriorityQueueBHCreate(size_t data_size, size_t priority_size,
    int (*compare_function)(void* priority1, void* priority2))
{
    PriorityQueueBH* PQ = (PriorityQueueBH*)malloc(sizeof (PriorityQueueBH));
    if(!PQ) {
        return NULL;
    }
    PQ->root = NULL;
    PQ->data_size = data_size;
    PQ->priority_size = priority_size;
    PQ->size = 0;
    PQ->compare_function = compare_function;
    return PQ;
}

// void PriorityQueueBHDestroy(PriorityQueueBH* PQ)
// {

// }

size_t PriorityQueueBHSize(PriorityQueueBH* PQ)
{
    return PQ->size;
}

void* PriorityQueueBH_root(PriorityQueueBH* PQ)
{
    return PQ->root->data;
}

bool PriorityQueueBHEnqueue(PriorityQueueBH* PQ, void* data, void* priority)
{
    Node* node = NodeCreate(PQ->data_size, PQ->priority_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, PQ->data_size);
    memcpy(node->priority, priority, PQ->priority_size);
    return true;
}

// void PriorityQueueBHDequeue(PriorityQueueBH* PQ)
// {

// }
