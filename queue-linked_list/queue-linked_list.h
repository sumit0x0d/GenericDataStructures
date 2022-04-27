#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueLLNode QueueLLNode;
typedef struct QueueLL QueueLL;

QueueLL* queue_linked_list_create(size_t data_size);
void queue_linked_list_destroy(QueueLL* Q);

void* queue_linked_list_front(QueueLL* Q);
void* queue_linked_list_back(QueueLL* Q);
size_t queue_linked_list_size(QueueLL* Q);

bool queue_linked_list_enqueue(QueueLL* Q, void* data);
bool queue_linked_list_dequeue(QueueLL* Q);

#endif
