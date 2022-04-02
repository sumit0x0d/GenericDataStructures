#ifndef DEQUE_LINKED_LIST_H
#define DEQUE_LINKED_LIST_H

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
    size_t size;
} DequeLinkedList;

DequeLinkedList deque_linked_list_create();
void deque_linked_list_destroy(DequeLinkedList *D);

DequeLinkedListNode *deque_linked_list_front(DequeLinkedList *D);
DequeLinkedListNode *deque_linked_list_back(DequeLinkedList *D);
size_t deque_linked_list_size(DequeLinkedList *D);

bool deque_linked_list_push_front(DequeLinkedList *D, void *data, size_t data_size);
bool deque_linked_list_push_back(DequeLinkedList *D, void *data, size_t data_size);
bool deque_linked_list_pop_front(DequeLinkedList *D);
bool deque_linked_list_pop_back(DequeLinkedList *D);

#endif
