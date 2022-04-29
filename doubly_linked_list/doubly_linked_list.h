#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DoublyLinkedListNode {
    void* data;
    struct DoublyLinkedListNode* previous;
    struct DoublyLinkedListNode* next;
} DoublyLinkedListNode;

typedef struct DoublyLinkedList {
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;
    size_t data_size;
    size_t size;
    int (*compare)(void* data, void* node_data);
} DoublyLinkedList;

DoublyLinkedList* DoublyLinkedList_create(size_t data_size,
    int (*compare)(void* data, void* node_data));
void DoublyLinkedList_destroy(DoublyLinkedList* DLL);

bool DoublyLinkedList_push_front(DoublyLinkedList* DLL, void* data);
bool DoublyLinkedList_push_back(DoublyLinkedList* DLL, void* data);
bool DoublyLinkedList_insert(DoublyLinkedList* DLL, size_t index, void* data);
bool DoublyLinkedList_sorted_insert(DoublyLinkedList* DLL, void* data);
bool DoublyLinkedList_pop_front(DoublyLinkedList* DLL);
bool DoublyLinkedList_pop_back(DoublyLinkedList* DLL);
bool DoublyLinkedList_remove(DoublyLinkedList* DLL, void* data);
bool DoublyLinkedList_erase(DoublyLinkedList* DLL, size_t index);
bool DoublyLinkedList_update(DoublyLinkedList* SLL, size_t index, void* data);
bool DoublyLinkedList_linear(DoublyLinkedList* DLL);
bool DoublyLinkedList_circular(DoublyLinkedList* DLL);

DoublyLinkedListNode* DoublyLinkedList_search(DoublyLinkedList* DLL, void* data);
DoublyLinkedListNode* DoublyLinkedList_at(DoublyLinkedList* DLL, size_t index);

#endif
