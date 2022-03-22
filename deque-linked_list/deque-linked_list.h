#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DequeLinkedListNode {
    void *data;
    size_t data_type_size;
    DequeLinkedListNode *previous;
    DequeLinkedListNode *next;
} DequeLinkedListNode;

typedef struct DequeLinkedList {
    DequeLinkedListNode *front;
    DequeLinkedListNode *back;
    size_t size;
} DequeLinkedList;

DequeLinkedList deque_linked_list_construct();
void deque_linked_list_destruct(DequeLinkedList *D);

inline DequeLinkedListNode *deque_linked_list_front(DequeLinkedList *D);
inline DequeLinkedListNode *deque_linked_list_back(DequeLinkedList *D);
inline size_t deque_linked_list_size(DequeLinkedList *D);

bool deque_linked_list_push_front(DequeLinkedList *D, void *data, size_t data_type_size);
bool deque_linked_list_push_back(DequeLinkedList *D, void *data, size_t data_type_size);
bool deque_linked_list_pop_front(DequeLinkedList *D);
bool deque_linked_list_pop_back(DequeLinkedList *D);

#endif
