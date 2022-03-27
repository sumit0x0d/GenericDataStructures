#ifndef DEQUE_LINKED_LIST_H
#define DEQUE_LINKED_LIST_H

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

typedef struct DequeLinkedListNode {
    void *data;
    struct DequeLinkedListNode *previous;
    struct DequeLinkedListNode *next;
} DequeLinkedListNode;

typedef struct DequeLinkedList {
    DequeLinkedListNode *front;
    DequeLinkedListNode *back;
    int data_type;
    size_t data_type_size;
    size_t size;
} DequeLinkedList;

DequeLinkedList deque_linked_list_create(int data_type, size_t data_type_size);
void deque_linked_list_distroy(DequeLinkedList *D);

DequeLinkedListNode *deque_linked_list_front(DequeLinkedList *D);
DequeLinkedListNode *deque_linked_list_back(DequeLinkedList *D);
size_t deque_linked_list_size(DequeLinkedList *D);

bool deque_linked_list_push_front(DequeLinkedList *D, void *data);
bool deque_linked_list_push_back(DequeLinkedList *D, void *data);
bool deque_linked_list_pop_front(DequeLinkedList *D);
bool deque_linked_list_pop_back(DequeLinkedList *D);

#endif
