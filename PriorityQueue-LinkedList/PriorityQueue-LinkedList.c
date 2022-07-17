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

PriorityQueueLL* PriorityQueueLLCreate(size_t data_size)
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

void PriorityQueueLLDestroy(PriorityQueueLL* PQ)
{
    Node* node = PQ->front;
    while(node) {
        if(node->next) {
            PriorityQueueLLDequeue(PQ);
            node = PQ->front;   
        }
        else {
            PriorityQueueLLDequeue(PQ);
            break;
        }
    }
    free(PQ);
    PQ = NULL;
}

size_t PriorityQueueLLSize(PriorityQueueLL* PQ)
{
    return PQ->size;
}

bool PriorityQueueLLEmpty(PriorityQueueLL* PQ)
{
    if(PQ->size) {
        return false;
    }
    return true;
}

void* PriorityQueueLLFront(PriorityQueueLL* PQ)
{
    return PQ->front->data;
}

void* PriorityQueueLLBack(PriorityQueueLL* PQ)
{
    return PQ->back->data;
}

bool PriorityQueueLLEnqueue(PriorityQueueLL* PQ, void* data, void* priority)
{
    Node* node = NodeCreate(PQ->data_size, PQ->priority_size);
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

void PriorityQueueLLDequeue(PriorityQueueLL* PQ)
{
    Node* node = PQ->front;
    PQ->front = PQ->front->next;
    if(!PQ->front) {
        PQ->back = NULL;
    }
    NodeDestroy(node);
    PQ->size = PQ->size - 1;
}
