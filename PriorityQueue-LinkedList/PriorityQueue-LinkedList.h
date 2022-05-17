#ifndef PRIORITY_QUEUE_LINKED_LIST_H
#define PRIORITY_QUEUE_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

typedef struct PriorityQueueLLNode {
    void* data;
    void* priority;
    struct PriorityQueueLLNode* next;
} PriorityQueueLLNode;

typedef struct PriorityQueueLL {
    PriorityQueueLLNode* front;
    PriorityQueueLLNode* back;
    size_t data_size;
    size_t priority_size;
    size_t size;
} PriorityQueueLL;

PriorityQueueLL* PriorityQueueLL_create(size_t data_size);
void PriorityQueueLL_destroy(PriorityQueueLL* Q);

int PriorityQueueLL_enqueue(PriorityQueueLL* Q, void* data, void* priority);
void PriorityQueueLL_dequeue(PriorityQueueLL* Q);

void* PriorityQueueLL_front(PriorityQueueLL* Q);
void* PriorityQueueLL_back(PriorityQueueLL* Q);

#endif
