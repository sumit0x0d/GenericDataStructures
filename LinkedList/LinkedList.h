#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

typedef struct LinkedListNode {
    void* data;
    struct LinkedListNode* previous;
    struct LinkedListNode* next;
} LinkedListNode;

typedef struct LinkedList {
    LinkedListNode* head;
    LinkedListNode* tail;
    size_t data_size;
    size_t size;
    int (*compare)(void* data1, void* data2);
} LinkedList;

LinkedList* LinkedList_create(size_t data_size, int (*compare)(void* data1, void* data2));
void LinkedList_destroy(LinkedList* LL);

void* LinkedList_head(LinkedList* LL);
void* LinkedList_tail(LinkedList* LL);

int LinkedList_push_front(LinkedList* LL, void* data);
int LinkedList_push_back(LinkedList* LL, void* data);
int LinkedList_insert(LinkedList* LL, size_t index, void* data);
int LinkedList_sorted_insert(LinkedList* LL, void* data);
int LinkedList_pop_front(LinkedList* LL);
int LinkedList_pop_back(LinkedList* LL);
int LinkedList_remove(LinkedList* LL, void* data);
int LinkedList_erase(LinkedList* LL, size_t index);
int LinkedList_update(LinkedList* SLL, size_t index, void* data);

LinkedListNode* LinkedList_search(LinkedList* LL, void* data);
LinkedListNode* LinkedList_at(LinkedList* LL, size_t index);

#endif
