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
    struct SinglyLinkedListNode *(*search)(struct SinglyLinkedList *SLL, void *data);
    void (*push_front)(struct SinglyLinkedList *SLL, void *data);
    void (*push_back)(struct SinglyLinkedList *SLL, void *data);
    void (*insert)(struct SinglyLinkedList *SLL, size_t index, void *data);
    void (*sorted_insert)(struct SinglyLinkedList *SLL, void *data);
    void (*pop_front)(struct SinglyLinkedList *SLL);
    void (*pop_back)(struct SinglyLinkedList *SLL);
    void (*remove)(struct SinglyLinkedList *SLL, void *data);
    void (*erase)(struct SinglyLinkedList *SLL, size_t index);
    void (*linear)(struct SinglyLinkedList *SLL);
    void (*circular)(struct SinglyLinkedList *SLL);
};

struct SinglyLinkedList singly_linked_list_construct(size_t data_type_size);
void singly_linked_list_distroy(struct SinglyLinkedList *SLL);

#endif
