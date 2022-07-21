#include "XORLinkedList.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct XORLinkedList {
    struct Node* head;
    struct Node* tail;
    size_t data_size;
    size_t size;
    int (*compare_function)(void* data1, void* data2);
};

XORLinkedList* XORLinkedList_Create(size_t data_size, int (*compare_function)(void* data1, void* data2))
{
    XORLinkedList* XORLL = (XORLinkedList*)malloc(sizeof (XORLinkedList));
    if(!XORLL) {
        return NULL;
    }
    XORLL->head = NULL;
    XORLL->tail = NULL;
    XORLL->data_size = data_size;
    XORLL->size = 0;
    XORLL->compare_function = compare_function;
    return XORLL;
}

size_t XORLinkedList_Size(XORLinkedList* XORLL)
{
    return XORLL->size;
}

bool XORLinkedList_Empty(XORLinkedList* XORLL)
{
    if(XORLL->size) {
        return false;
    }
    return false;
}

void* XORLinkedList_Head(XORLinkedList* XORLL)
{
    return XORLL->head->data;
}

void* XORLinkedListBack(XORLinkedList* XORLL)
{
    return XORLL->tail->data;
}

void* XORLinkedList_Search(XORLinkedList* XORLL, void* data)
{
    if(!XORLL->size) {
        return NULL;
    }
    Node* node = XORLL->head;
    Node* node_previous = NULL;
    while(node) {
        if(!XORLL->compare_function(data, node->data)) {
            return node;
        }
        node_previous = node;
        node = (Node*)((size_t)node_previous ^ (size_t)node);
    }
    return NULL;
}

bool XORLinkedList_PushHead(XORLinkedList* XORLL, void* data)
{
    Node* node = Node_Create(XORLL->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, XORLL->data_size);
    node->XOR = (Node*)(0 ^ (size_t)XORLL->head);
    XORLL->head = node;
    if(!XORLL->size) {
        XORLL->tail = node;
    }
    XORLL->size = XORLL->size + 1;
    return true;
}

bool XORLinkedList_PushTail(XORLinkedList* XORLL, void* data)
{
    Node* node = Node_Create(XORLL->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, XORLL->data_size);
    node->XOR = (Node*)((size_t)XORLL->tail ^ 0);
    XORLL->tail = node;
    if(!XORLL->size) {
        XORLL->head = node;
    }
    XORLL->size = XORLL->size + 1;
    return true;
}

// bool XORLinkedList_Insert(XORLinkedList* XORLL, size_t index, void* data)
// {

// }

// bool XORLinkedList_SortedInsert(XORLinkedList* XORLL, void* data)
// {

// }

// bool XORLinkedListPop_Head(XORLinkedList* XORLL)
// {

// }

// bool XORLinkedListPop_Tail(XORLinkedList* XORLL)
// {

// }

// bool XORLinkedList_Erase(XORLinkedList* XORLL, size_t index)
// {

// }

// bool XORLinkedList_Remove(XORLinkedList* XORLL, void* data)
// {

// }

