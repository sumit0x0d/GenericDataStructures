#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>

struct DoublyLinkedListNode {
    void *data;
    struct DoublyLinkedListNode *previous;
    struct DoublyLinkedListNode *next;
};

struct DoublyLinkedList {
    struct DoublyLinkedListNode *head;
    struct DoublyLinkedListNode *tail;
    size_t data_type_size;
    size_t size;
};

struct DoublyLinkedList doubly_linked_list_construct(size_t data_type_size);
void doubly_linked_list_destruct(struct DoublyLinkedList *DLL);
struct DoublyLinkedListNode *doubly_linked_list_search(struct DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_push_front(struct DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_push_back(struct DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_insert(struct DoublyLinkedList *DLL, size_t index, void *data);
bool doubly_linked_list_sorted_insert(struct DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_pop_front(struct DoublyLinkedList *DLL);
bool doubly_linked_list_pop_back(struct DoublyLinkedList *DLL);
bool doubly_linked_list_remove(struct DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_erase(struct DoublyLinkedList *DLL, size_t index);
bool doubly_linked_list_linear(struct DoublyLinkedList *DLL);
bool doubly_linked_list_circular(struct DoublyLinkedList *DLL);

#endif
