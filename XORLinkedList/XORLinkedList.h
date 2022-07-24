#ifndef XOR_LINKED_LIST_H
#define XOR_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct XORLinkedList XORLinkedList;

XORLinkedList* XORLinkedList_Create(size_t data_size, int (*compare)(void* data1, void* data2));
void XORLinkedList_Destroy(XORLinkedList* XORLL);
size_t XORLinkedList_Size(XORLinkedList* XORLL);
bool XORLinkedList_Empty(XORLinkedList* XORLL);
void* XORLinkedList_Head(XORLinkedList* XORLL);
void* XORLinkedList_Tail(XORLinkedList* XORLL);
void* XORLinkedList_At(XORLinkedList* XORLL, size_t index);
void* XORLinkedList_Search(XORLinkedList* XORLL, void* data);
bool XORLinkedList_PushFront(XORLinkedList* XORLL, void* data);
bool XORLinkedList_PushBack(XORLinkedList* XORLL, void* data);
bool XORLinkedList_Insert(XORLinkedList* XORLL, size_t index, void* data);
bool XORLinkedList_SortedInsert(XORLinkedList* XORLL, void* data);
bool XORLinkedList_PopFront(XORLinkedList* XORLL);
bool XORLinkedList_PopBack(XORLinkedList* XORLL);
bool XORLinkedList_Remove(XORLinkedList* XORLL, void* data);
bool XORLinkedList_Erase(XORLinkedList* XORLL, size_t index);
bool XORLinkedList_Update(XORLinkedList* SXORLL, size_t index, void* data);


#endif
