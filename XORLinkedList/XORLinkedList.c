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
    int (*compare)(void* data1, void* data2);
};

XORLinkedList* XORLinkedList_create(size_t data_size, int (*compare)(void* data1, void* data2))
{
    XORLinkedList* XORLL = (XORLinkedList*)malloc(sizeof (XORLinkedList));
    if(!XORLL) {
        return NULL;
    }
    XORLL->head = NULL;
    XORLL->tail = NULL;
    XORLL->data_size = data_size;
    XORLL->size = 0;
    XORLL->compare = compare;
    return XORLL;
}

void* XORLinkedList_head(XORLinkedList* XORLL)
{
    return XORLL->head->data;
}

void* XORLinkedList_back(XORLinkedList* XORLL)
{
    return XORLL->tail->data;
}

void* XORLinkedList_search(XORLinkedList* XORLL, void* data)
{
    if(!XORLL->size) {
        return NULL;
    }
    Node* node = XORLL->head;
    Node* node_previous = NULL;
    while(node) {
        if(!XORLL->compare(data, node->data)) {
            return node;
        }
        node_previous = node;
        node = (Node*)((size_t)node_previous ^ (size_t)node);
    }
    return NULL;
}

bool XORLinkedList_push_head(XORLinkedList* XORLL, void* data)
{
    Node* node = Node_create(XORLL->data_size);
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

bool XORLinkedList_push_tail(XORLinkedList* XORLL, void* data)
{
    Node* node = Node_create(XORLL->data_size);
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

// bool XORLinkedList_insert(XORLinkedList* XORLL, size_t index, void* data)
// {

// }

// bool XORLinkedList_sorted_insert(XORLinkedList* XORLL, void* data)
// {

// }

// bool XORLinkedList_pop_head(XORLinkedList* XORLL)
// {

// }

// bool XORLinkedList_pop_tail(XORLinkedList* XORLL)
// {

// }

// bool XORLinkedList_erase(XORLinkedList* XORLL, size_t index)
// {

// }

// bool XORLinkedList_remove(XORLinkedList* XORLL, void* data)
// {

// }

