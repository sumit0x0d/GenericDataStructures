#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

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
    struct DoublyLinkedListNode *(*search)(struct DoublyLinkedList *DLL, void *data);
    void (*push_front)(struct DoublyLinkedList *DLL, void *data);
    void (*push_back)(struct DoublyLinkedList *DLL, void *data);
    void (*insert)(struct DoublyLinkedList *DLL, size_t index, void *data);
    void (*sorted_insert)(struct DoublyLinkedList *DLL, void *data);
    void (*pop_front)(struct DoublyLinkedList *DLL);
    void (*pop_back)(struct DoublyLinkedList *DLL);
    void (*remove)(struct DoublyLinkedList *DLL, void *data);
    void (*erase)(struct DoublyLinkedList *DLL, size_t index);
    void (*linear)(struct DoublyLinkedList *DLL);
    void (*circular)(struct DoublyLinkedList *DLL);
};

struct DoublyLinkedList doubly_linked_list_construct(size_t data_type_size);
void doubly_linked_list_destruct(struct DoublyLinkedList *DLL);

#endif
