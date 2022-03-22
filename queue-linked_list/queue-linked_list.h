#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueLinkedListNode {
    void *data;
    size_t data_type_size;
    struct QueueLinkedListNode *next;
} QueueLinkedListNode;

typedef struct QueueLinkedList {
    QueueLinkedListNode *front;
    QueueLinkedListNode *back;
    size_t size;
} QueueLinkedList;

QueueLinkedList queue_linked_list_construct();
void queue_linked_list_destruct(QueueLinkedList *Q);

QueueLinkedListNode *queue_linked_list_front(QueueLinkedList *Q);
QueueLinkedListNode *queue_linked_list_back(QueueLinkedList *Q);
size_t queue_linked_list_size(QueueLinkedList *Q);

bool queue_linked_list_enqueue(QueueLinkedList *Q, void *data, size_t data_type_size);
bool queue_linked_list_dequeue(QueueLinkedList *Q);

#endif
