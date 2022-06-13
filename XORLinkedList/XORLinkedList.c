#include "XORLinkedList.h"

static XORLinkedListNode* node_create(size_t data_size);
static void node_destroy(XORLinkedListNode* node);

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

static XORLinkedListNode* node_create(size_t data_size)
{
    XORLinkedListNode* node = (XORLinkedListNode*)malloc(sizeof (XORLinkedListNode));
    if(!node) {
        return NULL;
    }
    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        return NULL;
    }
    return node;
}

static void node_destroy(XORLinkedListNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

XORLinkedListNode* XORLinkedList_search(XORLinkedList* XORLL, void* data)
{
    if(!XORLL->size) {
        return NULL;
    }
    XORLinkedListNode* node = XORLL->head;
    XORLinkedListNode* node_previous = NULL;
    while(node) {
        if(!XORLL->compare(data, node->data)) {
            return node;
        }
        node_previous = node;
        node = (XORLinkedListNode*)((size_t)node_previous ^ (size_t)node);
    }
    return NULL;
}

int XORLinkedList_push_head(XORLinkedList* XORLL, void* data)
{
    XORLinkedListNode* node = node_create(XORLL->data_size);
    if(!node) {
        return 0;
    }
    memcpy(node->data, data, XORLL->data_size);
    node->XOR = (XORLinkedListNode*)(0 ^ (size_t)XORLL->head);
    XORLL->head = node;
    if(!XORLL->size) {
        XORLL->tail = node;
    }
    XORLL->size = XORLL->size + 1;
    return 1;
}

int XORLinkedList_push_tail(XORLinkedList* XORLL, void* data)
{
    XORLinkedListNode* node = node_create(XORLL->data_size);
    if(!node) {
        return 0;
    }
    memcpy(node->data, data, XORLL->data_size);
    node->XOR = (XORLinkedListNode*)((size_t)XORLL->tail ^ 0);
    XORLL->tail = node;
    if(!XORLL->size) {
        XORLL->head = node;
    }
    XORLL->size = XORLL->size + 1;
    return 1;
}

// int XORLinkedList_insert(XORLinkedList* XORLL, size_t index, void* data)
// {

// }

// int XORLinkedList_sorted_insert(XORLinkedList* XORLL, void* data)
// {

// }

// int XORLinkedList_pop_head(XORLinkedList* XORLL)
// {

// }

// int XORLinkedList_pop_tail(XORLinkedList* XORLL)
// {

// }

// int XORLinkedList_erase(XORLinkedList* XORLL, size_t index)
// {

// }

// int XORLinkedList_remove(XORLinkedList* XORLL, void* data)
// {

// }

