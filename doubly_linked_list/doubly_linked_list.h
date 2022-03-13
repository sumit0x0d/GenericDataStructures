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
    struct DoublyLinkedListNode *(*search)(struct DoublyLinkedList *dll, void *data);
    void (*push_front)(struct DoublyLinkedList *dll, void *data);
    void (*push_back)(struct DoublyLinkedList *dll, void *data);
    void (*insert)(struct DoublyLinkedList *dll, size_t index, void *data);
    void (*sorted_insert)(struct DoublyLinkedList *dll, void *data);
    void (*pop_front)(struct DoublyLinkedList *dll);
    void (*pop_back)(struct DoublyLinkedList *dll);
    void (*remove)(struct DoublyLinkedList *dll, void *data);
    void (*erase)(struct DoublyLinkedList *dll, size_t index);
    void (*linear)(struct DoublyLinkedList *dll);
    void (*circular)(struct DoublyLinkedList *dll);
};

struct DoublyLinkedList doubly_linked_list_construct(size_t data_type_size);
void doubly_linked_list_distruct(struct DoublyLinkedList *dll);

#endif
