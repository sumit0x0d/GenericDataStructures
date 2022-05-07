#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

typedef struct SinglyLinkedListNode {
    void* data;
    struct SinglyLinkedListNode* next;
} SinglyLinkedListNode;

typedef struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
    size_t data_size;
    size_t size;
    int (*compare)(void* data1, void* data2);
} SinglyLinkedList;

SinglyLinkedList* SinglyLinkedList_create(size_t data_size,
    int (*compare)(void* data1, void* data2));
void SinglyLinkedList_destroy(SinglyLinkedList* SLL);

int SinglyLinkedList_push_head(SinglyLinkedList* SLL, void* data);
int SinglyLinkedList_push_tail(SinglyLinkedList* SLL, void* data);
int SinglyLinkedList_insert(SinglyLinkedList* SLL, size_t index, void* data);
int SinglyLinkedList_sorted_insert(SinglyLinkedList* SLL, void* data);
int SinglyLinkedList_pop_head(SinglyLinkedList* SLL);
int SinglyLinkedList_pop_tail(SinglyLinkedList* SLL);
int SinglyLinkedList_remove(SinglyLinkedList* SLL, void* data);
int SinglyLinkedList_erase(SinglyLinkedList* SLL, size_t index);
int SinglyLinkedList_update(SinglyLinkedList* SLL, size_t index, void* data);

SinglyLinkedListNode* SinglyLinkedList_search(SinglyLinkedList* SLL, void* data);
SinglyLinkedListNode* SinglyLinkedList_at(SinglyLinkedList* SLL, size_t index);

void* SinglyLinkedList_head(SinglyLinkedList* SLL);
void* SinglyLinkedList_tail(SinglyLinkedList* SLL);

#endif
