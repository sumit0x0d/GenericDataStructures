#ifndef XOR_LINKED_LIST_H
#define XOR_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

typedef struct XORLinkedListNode {
    void* data;
    struct XORLinkedListNode* XOR;
} XORLinkedListNode;

typedef struct XORLinkedList {
    XORLinkedListNode* head;
    XORLinkedListNode* tail;
    size_t data_size;
    size_t size;
    int (*compare)(void* data1, void* data2);
} XORLinkedList;

XORLinkedList* XORLinkedList_create(size_t data_size, int (*compare)(void* data1, void* data2));
void XORLinkedList_destroy(XORLinkedList* XORLL);

void* XORLinkedList_head(XORLinkedList* XORLL);
void* XORLinkedList_tail(XORLinkedList* XORLL);

int XORLinkedList_push_front(XORLinkedList* XORLL, void* data);
int XORLinkedList_push_back(XORLinkedList* XORLL, void* data);
int XORLinkedList_insert(XORLinkedList* XORLL, size_t index, void* data);
int XORLinkedList_sorted_insert(XORLinkedList* XORLL, void* data);
int XORLinkedList_pop_front(XORLinkedList* XORLL);
int XORLinkedList_pop_back(XORLinkedList* XORLL);
int XORLinkedList_remove(XORLinkedList* XORLL, void* data);
int XORLinkedList_erase(XORLinkedList* XORLL, size_t index);
int XORLinkedList_update(XORLinkedList* SXORLL, size_t index, void* data);

XORLinkedListNode* XORLinkedList_search(XORLinkedList* XORLL, void* data);
XORLinkedListNode* XORLinkedList_at(XORLinkedList* XORLL, size_t index);

#endif
