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

PriorityQueueLL* PriorityQueueLL_Create(size_t data_size)
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

void PriorityQueueLL_Destroy(PriorityQueueLL* PQ)
{
    Node* node = PQ->front;
    while(node) {
        if(node->next) {
            PriorityQueueLL_Dequeue(PQ);
            node = PQ->front;   
        }
        else {
            PriorityQueueLL_Dequeue(PQ);
            break;
        }
    }
    free(PQ);
    PQ = NULL;
}

size_t PriorityQueueLL_Size(PriorityQueueLL* PQ)
{
    return PQ->size;
}

bool PriorityQueueLL_Empty(PriorityQueueLL* PQ)
{
    if(PQ->size) {
        return false;
    }
    return true;
}

void* PriorityQueueLL_Front(PriorityQueueLL* PQ)
{
    return PQ->front->data;
}

void* PriorityQueueLL_Back(PriorityQueueLL* PQ)
{
    return PQ->back->data;
}

bool PriorityQueueLL_Enqueue(PriorityQueueLL* PQ, void* data, void* priority)
{
    Node* node = Node_Create(PQ->data_size, PQ->priority_size);
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

void PriorityQueueLL_Dequeue(PriorityQueueLL* PQ)
{
    Node* node = PQ->front;
    PQ->front = PQ->front->next;
    if(!PQ->front) {
        PQ->back = NULL;
    }
    Node_Destroy(node);
    PQ->size = PQ->size - 1;
}
