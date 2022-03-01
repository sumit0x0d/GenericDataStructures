#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdlib.h>

struct DoublyLinkedListNode {
    void *data;
    size_t data_type_size;
    struct DoublyLinkedListNode *previous;
    struct DoublyLinkedListNode *next;
};

struct DoublyLinkedList {
    struct DoublyLinkedListNode *head;
    struct DoublyLinkedListNode *tail;   
    size_t size;
    struct DoublyLinkedListNode *(*list_search)(struct DoublyLinkedList *linked_list, void *data, size_t data_type_size);
    void (*push_front)(struct DoublyLinkedList *linked_list, void *data, size_t data_type_size);
    void (*push_back)(struct DoublyLinkedList *linked_list, void *data, size_t data_type_size);
    void (*insert)(struct DoublyLinkedList *linked_list, size_t index, void *data, size_t data_type_size);
    void (*sorted_insert)(struct DoublyLinkedList *linked_list, void *data, size_t data_type_size);
    void (*pop_front)(struct DoublyLinkedList *linked_listlinked_list);
    void (*pop_back)(struct DoublyLinkedList *linked_list);
    void (*remove)(struct DoublyLinkedList *linked_list, void *data, size_t data_type_size);
    void (*erase)(struct DoublyLinkedList *linked_list, size_t index);
    void (*linear)(struct DoublyLinkedList *linked_list);
    void (*circular)(struct DoublyLinkedList *linked_list);
};

struct DoublyLinkedList *linked_list_construct();
void linked_list_distroy(struct DoublyLinkedList *linked_list);

#endif
