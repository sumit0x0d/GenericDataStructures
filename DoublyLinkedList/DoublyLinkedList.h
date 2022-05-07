#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

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
    int (*compare)(void* data1, void* data2);
} DoublyLinkedList;

DoublyLinkedList* DoublyLinkedList_create(size_t data_size,
    int (*compare)(void* data1, void* data2));
void DoublyLinkedList_destroy(DoublyLinkedList* DLL);

int DoublyLinkedList_push_front(DoublyLinkedList* DLL, void* data);
int DoublyLinkedList_push_back(DoublyLinkedList* DLL, void* data);
int DoublyLinkedList_insert(DoublyLinkedList* DLL, size_t index, void* data);
int DoublyLinkedList_sorted_insert(DoublyLinkedList* DLL, void* data);
int DoublyLinkedList_pop_front(DoublyLinkedList* DLL);
int DoublyLinkedList_pop_back(DoublyLinkedList* DLL);
int DoublyLinkedList_remove(DoublyLinkedList* DLL, void* data);
int DoublyLinkedList_erase(DoublyLinkedList* DLL, size_t index);
int DoublyLinkedList_update(DoublyLinkedList* SLL, size_t index, void* data);

DoublyLinkedListNode* DoublyLinkedList_search(DoublyLinkedList* DLL, void* data);
DoublyLinkedListNode* DoublyLinkedList_at(DoublyLinkedList* DLL, size_t index);

void* DoublyLinkedList_head(DoublyLinkedList* DLL);
void* DoublyLinkedList_tail(DoublyLinkedList* DLL);

#endif
