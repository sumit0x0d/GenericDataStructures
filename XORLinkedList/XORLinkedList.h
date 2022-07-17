#ifndef XOR_LINKED_LIST_H
#define XOR_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct XORLinkedList XORLinkedList;

XORLinkedList* XORLinkedListCreate(size_t data_size, int (*compare_function)(void* data1, void* data2));
void XORLinkedListDestroy(XORLinkedList* XORLL);
size_t XORLinkedListSize(XORLinkedList* XORLL);
bool XORLinkedListEmpty(XORLinkedList* XORLL);
void* XORLinkedListHead(XORLinkedList* XORLL);
void* XORLinkedListTail(XORLinkedList* XORLL);
void* XORLinkedListAt(XORLinkedList* XORLL, size_t index);
void* XORLinkedListSearch(XORLinkedList* XORLL, void* data);
bool XORLinkedListPushFront(XORLinkedList* XORLL, void* data);
bool XORLinkedListPushBack(XORLinkedList* XORLL, void* data);
bool XORLinkedListInsert(XORLinkedList* XORLL, size_t index, void* data);
bool XORLinkedListSortedInsert(XORLinkedList* XORLL, void* data);
bool XORLinkedListPopFront(XORLinkedList* XORLL);
bool XORLinkedListPopBack(XORLinkedList* XORLL);
bool XORLinkedListRemove(XORLinkedList* XORLL, void* data);
bool XORLinkedListErase(XORLinkedList* XORLL, size_t index);
bool XORLinkedListUpdate(XORLinkedList* SXORLL, size_t index, void* data);


#endif
