#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct LinkedList LinkedList;

LinkedList* LinkedListCreate(size_t data_size, int (*compare_function)(void* data1, void* data2));
void LinkedListDestroy(LinkedList* LL);
size_t LinkedListSize(LinkedList* LL);
bool LinkedListEmpty(LinkedList* LL);
void* LinkedListHead(LinkedList* LL);
void* LinkedListTail(LinkedList* LL);
void* LinkedListAt(LinkedList* LL, size_t index);
void* LinkedListSearch(LinkedList* LL, void* data);
bool LinkedListPushFront(LinkedList* LL, void* data);
bool LinkedListPushBack(LinkedList* LL, void* data);
bool LinkedListInsert(LinkedList* LL, size_t index, void* data);
bool LinkedListSortedInsert(LinkedList* LL, void* data);
void LinkedListPopFront(LinkedList* LL);
void LinkedListPopBack(LinkedList* LL);
void LinkedListRemove(LinkedList* LL, void* data);
void LinkedListErase(LinkedList* LL, size_t index);
bool LinkedListUpdate(LinkedList* LL, size_t index, void* data);
void LinkedListTraverse(LinkedList* LL, void (*function)(void *));

#endif
