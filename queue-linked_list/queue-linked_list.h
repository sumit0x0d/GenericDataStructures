#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueLinkedListNode {
    void *data;
    struct QueueLinkedListNode *next;
} QueueLinkedListNode;

typedef struct QueueLinkedList {
    QueueLinkedListNode *front;
    QueueLinkedListNode *back;
    size_t data_size;
    size_t size;
} QueueLinkedList;

QueueLinkedList queue_linked_list_create(size_t data_size);
void queue_linked_list_destroy(QueueLinkedList *Q);

void *queue_linked_list_front(QueueLinkedList *Q);
void *queue_linked_list_back(QueueLinkedList *Q);
size_t queue_linked_list_size(QueueLinkedList *Q);

bool queue_linked_list_enqueue(QueueLinkedList *Q, void *data);
bool queue_linked_list_dequeue(QueueLinkedList *Q);

#endif
