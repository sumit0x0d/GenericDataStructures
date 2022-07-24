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
    int (*compare)(void* priority1, void* priority2);
};

PriorityQueueBH* PriorityQueueBH_Create(size_t data_size, size_t priority_size,
    int (*compare)(void* priority1, void* priority2))
{
    PriorityQueueBH* PQ = (PriorityQueueBH*)malloc(sizeof (PriorityQueueBH));
    if(!PQ) {
        return NULL;
    }
    PQ->root = NULL;
    PQ->data_size = data_size;
    PQ->priority_size = priority_size;
    PQ->size = 0;
    PQ->compare = compare;
    return PQ;
}

// void PriorityQueueBH_Destroy(PriorityQueueBH* PQ)
// {

// }

size_t PriorityQueueBH_Size(PriorityQueueBH* PQ)
{
    return PQ->size;
}

void* PriorityQueueBH_Root(PriorityQueueBH* PQ)
{
    return PQ->root->data;
}

bool PriorityQueueBH_Enqueue(PriorityQueueBH* PQ, void* data, void* priority)
{
    Node* node = Node_Create(PQ->data_size, PQ->priority_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, PQ->data_size);
    memcpy(node->priority, priority, PQ->priority_size);
    return true;
}

// void PriorityQueueBH_Dequeue(PriorityQueueBH* PQ)
// {

// }
