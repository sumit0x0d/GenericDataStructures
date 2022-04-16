#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

SinglyLinkedList* singly_linked_list_create(size_t data_size,
    int (*compare)(void* data, void* node_data));
void singly_linked_list_destroy(SinglyLinkedList* SLL);

void* singly_linked_list_head(SinglyLinkedList* SLL);
void* singly_linked_list_tail(SinglyLinkedList* SLL);
size_t singly_linked_list_size(SinglyLinkedList* SLL);

SinglyLinkedListNode* singly_linked_list_search(SinglyLinkedList* SLL, void* data);
void* singly_linked_list_at(SinglyLinkedList* SLL, size_t index);

bool singly_linked_list_push_head(SinglyLinkedList* SLL, void* data);
bool singly_linked_list_push_tail(SinglyLinkedList* SLL, void* data);
bool singly_linked_list_insert(SinglyLinkedList* SLL, size_t index, void* data);
bool singly_linked_list_sorted_insert(SinglyLinkedList* SLL, void* data);
bool singly_linked_list_pop_head(SinglyLinkedList* SLL);
bool singly_linked_list_pop_tail(SinglyLinkedList* SLL);
bool singly_linked_list_remove(SinglyLinkedList* SLL, void* data);
bool singly_linked_list_erase(SinglyLinkedList* SLL, size_t index);
bool singly_linked_list_update(SinglyLinkedList* SLL, size_t index, void* data);
bool singly_linked_list_linear(SinglyLinkedList* SLL);
bool singly_linked_list_circular(SinglyLinkedList* SLL);

SinglyLinkedListNode* singly_linked_list_begin(SinglyLinkedList* SLL);
SinglyLinkedListNode* singly_linked_list_end(SinglyLinkedList* SLL);

void* singly_linked_list_node_data(SinglyLinkedListNode* node);
SinglyLinkedListNode* singly_linked_list_node_next(SinglyLinkedListNode* node);

#endif
