#ifndef XOR_LINKED_LIST_H
#define XOR_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct XORLinkedList XORLinkedList;

XORLinkedList* XORLinkedList_create(size_t data_size, int (*compare)(void* data1, void* data2));
void XORLinkedList_destroy(XORLinkedList* XORLL);
size_t XORLinkedList_size(XORLinkedList* XORLL);
bool XORLinkedList_empty(XORLinkedList* XORLL);
void* XORLinkedList_head(XORLinkedList* XORLL);
void* XORLinkedList_tail(XORLinkedList* XORLL);
void* XORLinkedList_at(XORLinkedList* XORLL, size_t index);
void* XORLinkedList_search(XORLinkedList* XORLL, void* data);
bool XORLinkedList_push_front(XORLinkedList* XORLL, void* data);
bool XORLinkedList_push_back(XORLinkedList* XORLL, void* data);
bool XORLinkedList_insert(XORLinkedList* XORLL, size_t index, void* data);
bool XORLinkedList_sorted_insert(XORLinkedList* XORLL, void* data);
bool XORLinkedList_pop_front(XORLinkedList* XORLL);
bool XORLinkedList_pop_back(XORLinkedList* XORLL);
bool XORLinkedList_remove(XORLinkedList* XORLL, void* data);
bool XORLinkedList_erase(XORLinkedList* XORLL, size_t index);
bool XORLinkedList_update(XORLinkedList* SXORLL, size_t index, void* data);


#endif
