#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinglyLinkedListNode {
    void *data;
    size_t data_type_size;
    struct SinglyLinkedListNode *next;
} SinglyLinkedListNode;

typedef struct SinglyLinkedList {
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;
    size_t size;
} SinglyLinkedList;

SinglyLinkedList singly_linked_list_construct();
void singly_linked_list_distroy(SinglyLinkedList *);

SinglyLinkedListNode *singly_linked_list_head(SinglyLinkedList *);
SinglyLinkedListNode *singly_linked_list_tail(SinglyLinkedList *);
SinglyLinkedListNode *singly_linked_list_size(SinglyLinkedList *);

SinglyLinkedListNode *singly_linked_list_search(SinglyLinkedList *, void *);
bool singly_linked_list_push_front(SinglyLinkedList *, void *, size_t);
bool singly_linked_list_push_back(SinglyLinkedList *, void *, size_t);
bool singly_linked_list_insert(SinglyLinkedList *, size_t, void *,  size_t);
bool singly_linked_list_sorted_insert(SinglyLinkedList *, void *,  size_t);
bool singly_linked_list_pop_front(SinglyLinkedList *);
bool singly_linked_list_pop_back(SinglyLinkedList *);
bool singly_linked_list_remove(SinglyLinkedList *, void *);
bool singly_linked_list_erase(SinglyLinkedList *, size_t);
bool singly_linked_list_linear(SinglyLinkedList *);
bool singly_linked_list_circular(SinglyLinkedList *);

#endif
