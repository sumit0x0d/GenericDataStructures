#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct DoublyLinkedListNode {
    void *;
    size_t _type_size;
    struct DoublyLinkedListNode *previous;
    struct DoublyLinkedListNode *next;
} DoublyLinkedListNode;

typedef struct DoublyLinkedList {
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;
    size_t size;
} DoublyLinkedList;

DoublyLinkedList doubly_linked_list_construct();
void doubly_linked_list_destruct(DoublyLinkedList *);

DoublyLinkedListNode *doubly_linked_list_search(DoublyLinkedList *, void *);
bool doubly_linked_list_push_front(DoublyLinkedList *, void *);
bool doubly_linked_list_push_back(DoublyLinkedList *, void *);
bool doubly_linked_list_insert(DoublyLinkedList *, size_t, void *);
bool doubly_linked_list_sorted_insert(DoublyLinkedList *, void *);
bool doubly_linked_list_pop_front(DoublyLinkedList *);
bool doubly_linked_list_pop_back(DoublyLinkedList *);
bool doubly_linked_list_remove(DoublyLinkedList *, void *);
bool doubly_linked_list_erase(DoublyLinkedList *, size_t);
bool doubly_linked_list_linear(DoublyLinkedList *);
bool doubly_linked_list_circular(DoublyLinkedList *);

#endif
