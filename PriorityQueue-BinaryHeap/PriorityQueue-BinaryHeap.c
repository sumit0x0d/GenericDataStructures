#include "PriorityQueue-BinaryHeap.h"

PriorityQueueBH* PriorityQueueBH_create(size_t data_size, size_t priority_size,
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

// void PriorityQueueBH_destroy(PriorityQueueBH* PQ)
// {

// }

void* PriorityQueueBH_root(PriorityQueueBH* PQ)
{
    return PQ->root->data;
}

static PriorityQueueBHNode* node_create(size_t data_size, size_t priority_size)
{
    PriorityQueueBHNode* node = (PriorityQueueBHNode*)malloc(sizeof (PriorityQueueBHNode));
    if(!node) {
        return NULL;
    }
    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        return NULL;
    }
    node->priority = malloc(priority_size);
    if(!node->priority) {
        free(node->data);
        free(node);
        return NULL;
    }
    node->left = NULL;
    node->right = NULL;
    return node;
}

// static void node_destroy(PriorityQueueBHNode* node)
// {
    
// }

bool PriorityQueueBH_enqueue(PriorityQueueBH* PQ, void* data, void* priority)
{
    PriorityQueueBHNode* node = node_create(PQ->data_size, PQ->priority_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, PQ->data_size);
    memcpy(node->priority, priority, PQ->priority_size);
    return true;
}

// void PriorityQueueBH_dequeue(PriorityQueueBH* PQ)
// {

// }
