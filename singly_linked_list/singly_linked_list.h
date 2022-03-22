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
void singly_linked_list_distroy(SinglyLinkedList *SLL);

SinglyLinkedListNode *singly_linked_list_head(SinglyLinkedList *SLL);
SinglyLinkedListNode *singly_linked_list_tail(SinglyLinkedList *SLL);
size_t singly_linked_list_size(SinglyLinkedList *SLL);

SinglyLinkedListNode *singly_linked_list_search(SinglyLinkedList *SLL, void *data);
bool singly_linked_list_push_front(SinglyLinkedList *SLL, void *data, size_t data_type_size);
bool singly_linked_list_push_back(SinglyLinkedList *SLL, void *data, size_t data_type_size);
bool singly_linked_list_insert(SinglyLinkedList *SLL, size_t index, void *data, size_t data_type_size);
bool singly_linked_list_sorted_insert(SinglyLinkedList *SLL, void *data, size_t data_type_size);
bool singly_linked_list_pop_front(SinglyLinkedList *SLL);
bool singly_linked_list_pop_back(SinglyLinkedList *SLL);
bool singly_linked_list_remove(SinglyLinkedList *SLL, void *data, size_t data_type_size);
bool singly_linked_list_erase(SinglyLinkedList *SLL, size_t index);
bool singly_linked_list_linear(SinglyLinkedList *SLL);
bool singly_linked_list_circular(SinglyLinkedList *SLL);

#endif
