#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DoublyLinkedListNode {
    void *data;
    size_t data_type_size;
    struct DoublyLinkedListNode *previous;
    struct DoublyLinkedListNode *next;
} DoublyLinkedListNode;

typedef struct DoublyLinkedList {
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;
    size_t size;
} DoublyLinkedList;

DoublyLinkedList doubly_linked_list_construct();
void doubly_linked_list_destruct(DoublyLinkedList *DLL);

DoublyLinkedListNode *doubly_linked_list_front(DoublyLinkedList *DLL);
DoublyLinkedListNode *doubly_linked_list_back(DoublyLinkedList *DLL);
size_t doubly_linked_list_size(DoublyLinkedList *DLL);

DoublyLinkedListNode *doubly_linked_list_search(DoublyLinkedList *DLL, void *data, size_t data_type_size);
bool doubly_linked_list_push_front(DoublyLinkedList *DLL, void *data, size_t data_type_size);
bool doubly_linked_list_push_back(DoublyLinkedList *DLL, void *data, size_t data_type_size);
bool doubly_linked_list_insert(DoublyLinkedList *DLL, size_t index, void *data, size_t data_type_size);
bool doubly_linked_list_sorted_insert(DoublyLinkedList *DLL, void *data, size_t data_type_size);
bool doubly_linked_list_pop_front(DoublyLinkedList *DLL);
bool doubly_linked_list_pop_back(DoublyLinkedList *DLL);
bool doubly_linked_list_remove(DoublyLinkedList *DLL, void *data, size_t data_type_size);
bool doubly_linked_list_erase(DoublyLinkedList *DLL, size_t index);
bool doubly_linked_list_linear(DoublyLinkedList *DLL);
bool doubly_linked_list_circular(DoublyLinkedList *DLL);

#endif
