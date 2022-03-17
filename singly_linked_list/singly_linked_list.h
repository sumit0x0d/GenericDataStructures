#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct SinglyLinkedListNode {
    void *data;
    struct SinglyLinkedListNode *next;
};

struct SinglyLinkedList {
    struct SinglyLinkedListNode *head;
    struct SinglyLinkedListNode *tail;
    size_t data_type_size;
    size_t size;
};

struct SinglyLinkedList singly_linked_list_construct(size_t data_type_size);
void singly_linked_list_distroy(struct SinglyLinkedList *SLL);
struct SinglyLinkedListNode *singly_linked_list_search(struct SinglyLinkedList *SLL, void *data);
bool singly_linked_list_push_front(struct SinglyLinkedList *SLL, void *data);
bool singly_linked_list_push_back(struct SinglyLinkedList *SLL, void *data);
bool singly_linked_list_insert(struct SinglyLinkedList *SLL, size_t index, void *data);
bool singly_linked_list_sorted_insert(struct SinglyLinkedList *SLL, void *data);
bool singly_linked_list_pop_front(struct SinglyLinkedList *SLL);
bool singly_linked_list_pop_back(struct SinglyLinkedList *SLL);
bool singly_linked_list_remove(struct SinglyLinkedList *SLL, void *data);
bool singly_linked_list_erase(struct SinglyLinkedList *SLL, size_t index);
bool singly_linked_list_linear(struct SinglyLinkedList *SLL);
bool singly_linked_list_circular(struct SinglyLinkedList *SLL);

#endif
