#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

struct LinkedListNode {
    void *data;
    size_t data_type_size;
    struct LinkedListNode *next;
};

struct LinkedList {
    struct LinkedListNode *head;
    struct LinkedListNode *tail;  
    size_t size;
    struct LinkedListNode *(*search)(struct LinkedList *linked_list, void *data, size_t data_type_size);
    void (*push_front)(struct LinkedList *linked_list, void *data, size_t data_type_size);
    void (*push_back)(struct LinkedList *linked_list, void *data, size_t data_type_size);
    void (*insert)(struct LinkedList *linked_list, size_t index, void *data, size_t data_type_size);
    void (*sorted_insert)(struct LinkedList *linked_list, void *data, size_t data_type_size);
    void (*pop_front)(struct LinkedList *linked_list);
    void (*pop_back)(struct LinkedList *linked_list);
    void (*remove)(struct LinkedList *linked_list, void *data, size_t data_type_size);
    void (*erase)(struct LinkedList *linked_list, size_t index);
    void (*linear)(struct LinkedList *linked_list);
    void (*circular)(struct LinkedList *linked_list);
};

struct LinkedList linked_list_construct();
void linked_list_distroy(struct LinkedList *linked_list);

#endif
