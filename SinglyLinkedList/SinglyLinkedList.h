#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdbool.h>
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
    int (*compare)(void* data, void* node_data);
} SinglyLinkedList;

SinglyLinkedList* SinglyLinkedList_create(size_t data_size,
    int (*compare)(void* data, void* node_data));
void SinglyLinkedList_destroy(SinglyLinkedList* SLL);

bool SinglyLinkedList_push_head(SinglyLinkedList* SLL, void* data);
bool SinglyLinkedList_push_tail(SinglyLinkedList* SLL, void* data);
bool SinglyLinkedList_insert(SinglyLinkedList* SLL, size_t index, void* data);
bool SinglyLinkedList_sorted_insert(SinglyLinkedList* SLL, void* data);
bool SinglyLinkedList_pop_head(SinglyLinkedList* SLL);
bool SinglyLinkedList_pop_tail(SinglyLinkedList* SLL);
bool SinglyLinkedList_remove(SinglyLinkedList* SLL, void* data);
bool SinglyLinkedList_erase(SinglyLinkedList* SLL, size_t index);
bool SinglyLinkedList_update(SinglyLinkedList* SLL, size_t index, void* data);

SinglyLinkedListNode* SinglyLinkedList_search(SinglyLinkedList* SLL, void* data);
SinglyLinkedListNode* SinglyLinkedList_at(SinglyLinkedList* SLL, size_t index);

#endif
