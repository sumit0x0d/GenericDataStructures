#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

struct SinglyLinkedListNode {
    void *data;
    struct SinglyLinkedListNode *next;
};

struct SinglyLinkedList {
    struct SinglyLinkedListNode *head;
    struct SinglyLinkedListNode *tail;
    size_t data_type_size;
    size_t size;
    struct SinglyLinkedListNode *(*search)(struct SinglyLinkedList *sll, void *data);
    void (*push_front)(struct SinglyLinkedList *sll, void *data);
    void (*push_back)(struct SinglyLinkedList *sll, void *data);
    void (*insert)(struct SinglyLinkedList *sll, size_t index, void *data);
    void (*sorted_insert)(struct SinglyLinkedList *sll, void *data);
    void (*pop_front)(struct SinglyLinkedList *sll);
    void (*pop_back)(struct SinglyLinkedList *sll);
    void (*remove)(struct SinglyLinkedList *sll, void *data);
    void (*erase)(struct SinglyLinkedList *sll, size_t index);
    void (*linear)(struct SinglyLinkedList *sll);
    void (*circular)(struct SinglyLinkedList *sll);
};

struct SinglyLinkedList singly_linked_list_construct(size_t data_type_size);
void singly_linked_list_distroy(struct SinglyLinkedList *sll);

#endif
