#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DoublyLinkedListNode DoublyLinkedListNode;
typedef struct DoublyLinkedList DoublyLinkedList;

DoublyLinkedList* doubly_linked_list_create(size_t data_size,
    int (*compare)(void* data, void* node_data));
void doubly_linked_list_destroy(DoublyLinkedList* DLL);

void* doubly_linked_list_front(DoublyLinkedList* DLL);
void* doubly_linked_list_back(DoublyLinkedList* DLL);
size_t doubly_linked_list_size(DoublyLinkedList* DLL);

DoublyLinkedListNode* doubly_linked_list_search(DoublyLinkedList* DLL, void* data);
void* doubly_linked_list_at(DoublyLinkedList* DLL, size_t index);

bool doubly_linked_list_push_front(DoublyLinkedList* DLL, void* data);
bool doubly_linked_list_push_back(DoublyLinkedList* DLL, void* data);
bool doubly_linked_list_insert(DoublyLinkedList* DLL, size_t index, void* data);
bool doubly_linked_list_sorted_insert(DoublyLinkedList* DLL, void* data);
bool doubly_linked_list_pop_front(DoublyLinkedList* DLL);
bool doubly_linked_list_pop_back(DoublyLinkedList* DLL);
bool doubly_linked_list_remove(DoublyLinkedList* DLL, void* data);
bool doubly_linked_list_erase(DoublyLinkedList* DLL, size_t index);
bool doubly_linked_list_update(DoublyLinkedList* SLL, size_t index, void* data);
bool doubly_linked_list_linear(DoublyLinkedList* DLL);
bool doubly_linked_list_circular(DoublyLinkedList* DLL);

void* doubly_linked_list_node_data(DoublyLinkedListNode* node);
DoublyLinkedListNode* doubly_linked_list_node_next(DoublyLinkedListNode* node);
DoublyLinkedListNode* doubly_linked_list_node_previous(DoublyLinkedListNode* node);

#endif
