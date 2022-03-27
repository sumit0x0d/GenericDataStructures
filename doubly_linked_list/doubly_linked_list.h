#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#ifndef DATA_TYPE
#define DATA_TYPE

enum {
    BOOL,
    CHAR,
    UNSIGNED_CHAR,
    SHORT,
    UNSIGNED_SHORT,
    INT,
    UNSIGNED_INT,
    FLOAT,
    LONG,
    UNSIGNED_LONG,
    DOUBLE,
    LONG_LONG,
    UNSIGNED_LONG_LONG,
    LONG_DOUBLE,
    STRUCT,
    UNION,
    ARRAY,
    POINTER
};

#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DoublyLinkedListNode {
    void *data;
    struct DoublyLinkedListNode *previous;
    struct DoublyLinkedListNode *next;
} DoublyLinkedListNode;

typedef struct DoublyLinkedList {
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;
    int data_type;
    size_t data_type_size;
    size_t size;
} DoublyLinkedList;

DoublyLinkedList doubly_linked_list_create(int Data_type, size_t data_type_size);
void doubly_linked_list_distroy(DoublyLinkedList *DLL);

DoublyLinkedListNode *doubly_linked_list_front(DoublyLinkedList *DLL);
DoublyLinkedListNode *doubly_linked_list_back(DoublyLinkedList *DLL);
size_t doubly_linked_list_size(DoublyLinkedList *DLL);

DoublyLinkedListNode *doubly_linked_list_search(DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_push_front(DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_push_back(DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_insert(DoublyLinkedList *DLL, size_t index, void *data);
bool doubly_linked_list_sorted_insert(DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_pop_front(DoublyLinkedList *DLL);
bool doubly_linked_list_pop_back(DoublyLinkedList *DLL);
bool doubly_linked_list_remove(DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_erase(DoublyLinkedList *DLL, size_t index);
bool doubly_linked_list_linear(DoublyLinkedList *DLL);
bool doubly_linked_list_circular(DoublyLinkedList *DLL);

#endif
