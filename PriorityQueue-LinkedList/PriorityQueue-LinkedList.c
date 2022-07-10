#include "PriorityQueue-LinkedList.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct PriorityQueueLL {
    Node* front;
    Node* back;
    size_t data_size;
    size_t priority_size;
    size_t size;
};

PriorityQueueLL* PriorityQueueLL_create(size_t data_size)
{
    PriorityQueueLL* PQ = (PriorityQueueLL*)malloc(sizeof (PriorityQueueLL));
    if(!PQ) {
        return NULL;
    }
    PQ->front = NULL;
    PQ->back = NULL;
    PQ->data_size = data_size;
    PQ->size = 0;
    return PQ;
}

void PriorityQueueLL_destroy(PriorityQueueLL* PQ)
{
    Node* node = PQ->front;
    while(node) {
        if(node->next) {
            PriorityQueueLL_dequeue(PQ);
            node = PQ->front;   
        }
        else {
            PriorityQueueLL_dequeue(PQ);
            break;
        }
    }
    free(PQ);
    PQ = NULL;
}

size_t PriorityQueueLL_size(PriorityQueueLL* PQ)
{
    return PQ->size;
}

bool PriorityQueueLL_empty(PriorityQueueLL* PQ)
{
    if(PQ->size) {
        return false;
    }
    return true;
}

void* PriorityQueueLL_front(PriorityQueueLL* PQ)
{
    return PQ->front->data;
}

void* PriorityQueueLL_back(PriorityQueueLL* PQ)
{
    return PQ->back->data;
}

bool PriorityQueueLL_enqueue(PriorityQueueLL* PQ, void* data, void* priority)
{
    Node* node = Node_create(PQ->data_size, PQ->priority_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, PQ->data_size);
    memcpy(node->priority, priority, PQ->priority_size);
    node->next = NULL;
    if(PQ->front) {
        PQ->back->next = node;
    }
    else {
        PQ->front = node;
    }
    PQ->back = node;
    PQ->size = PQ->size + 1;
    return true;
}

void PriorityQueueLL_dequeue(PriorityQueueLL* PQ)
{
    Node* node = PQ->front;
    PQ->front = PQ->front->next;
    if(!PQ->front) {
        PQ->back = NULL;
    }
    Node_destroy(node);
    PQ->size = PQ->size - 1;
}
