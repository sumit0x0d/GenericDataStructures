#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

struct SinglyLinkedListNode {
    void *data;
    size_t data_type_size;
    struct SinglyLinkedListNode *next;
};

struct SinglyLinkedList {
    struct SinglyLinkedListNode *head;
    struct SinglyLinkedListNode *tail;  
    size_t size;
    struct SinglyLinkedListNode *(*search)(struct SinglyLinkedList *linked_list, void *data, size_t data_type_size);
    void (*push_front)(struct SinglyLinkedList *linked_list, void *data, size_t data_type_size);
    void (*push_back)(struct SinglyLinkedList *linked_list, void *data, size_t data_type_size);
    void (*insert)(struct SinglyLinkedList *linked_list, size_t index, void *data, size_t data_type_size);
    void (*sorted_insert)(struct SinglyLinkedList *linked_list, void *data, size_t data_type_size);
    void (*pop_front)(struct SinglyLinkedList *linked_list);
    void (*pop_back)(struct SinglyLinkedList *linked_list);
    void (*remove)(struct SinglyLinkedList *linked_list, void *data, size_t data_type_size);
    void (*erase)(struct SinglyLinkedList *linked_list, size_t index);
    void (*linear)(struct SinglyLinkedList *linked_list);
    void (*circular)(struct SinglyLinkedList *linked_list);
};

struct SinglyLinkedList singly_linked_list_construct();
void singly_linked_list_distroy(struct SinglyLinkedList *linked_list);

#endif
