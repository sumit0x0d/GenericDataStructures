#ifndef PRIORITY_QUEUE_LINKED_LIST_H
#define PRIORITY_QUEUE_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct PriorityQueueLL {
    struct Node* front;
    struct Node* back;
    size_t data_size;
    size_t priority_size;
    size_t size;
} PriorityQueueLL;

PriorityQueueLL* PriorityQueueLL_create(size_t data_size);
void PriorityQueueLL_destroy(PriorityQueueLL* Q);

bool PriorityQueueLL_enqueue(PriorityQueueLL* Q, void* data, void* priority);
void PriorityQueueLL_dequeue(PriorityQueueLL* Q);

void* PriorityQueueLL_front(PriorityQueueLL* Q);
void* PriorityQueueLL_back(PriorityQueueLL* Q);

#endif
