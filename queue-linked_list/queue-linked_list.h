#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#ifndef DATA_TYPE
#define DATA_TYPE

enum {
    BOOL,
    CHAR,
    UNSIGNED_CHAR,
    SHORT,
    UNSIGNED_SHORT,
    INT,
    UNSIGNED_INT,
    FLOAT,
    LONG,
    UNSIGNED_LONG,
    DOUBLE,
    LONG_LONG,
    UNSIGNED_LONG_LONG,
    LONG_DOUBLE,
    STRING,
    STRUCT
};

#endif

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
    int data_type;
    size_t data_type_size;
    size_t size;
} QueueLinkedList;

QueueLinkedList queue_linked_list_create(int data_type, size_t data_type_size);
void queue_linked_list_distroy(QueueLinkedList *Q);

QueueLinkedListNode *queue_linked_list_front(QueueLinkedList *Q);
QueueLinkedListNode *queue_linked_list_back(QueueLinkedList *Q);
size_t queue_linked_list_size(QueueLinkedList *Q);

bool queue_linked_list_enqueue(QueueLinkedList *Q, void *data);
bool queue_linked_list_dequeue(QueueLinkedList *Q);

#endif
