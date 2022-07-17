#include "LinkedList.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct LinkedList {
    Node* head;
    Node* tail;
    size_t data_size;
    size_t size;
    int (*compare_function)(void* data1, void* data2);
};

LinkedList* LinkedListCreate(size_t data_size, int (*compare_function)(void* data1, void* data2))
{
    LinkedList* LL = (LinkedList*)malloc(sizeof (LinkedList));
    if(!LL) {
        return NULL;
    }
    LL->head = NULL;
    LL->tail = NULL;
    LL->data_size = data_size;
    LL->size = 0;
    LL->compare_function = compare_function;
    return LL;
}

bool LinkedListEmpty(LinkedList* LL)
{
    if(LL->size) {
        return false;
    }
    return true;
}

size_t LinkedListSize(LinkedList* LL)
{
    return LL->size;
}

void* LinkedListHead(LinkedList* LL)
{
    return LL->head->data;
}

void* LinkedListBack(LinkedList* LL)
{
    return LL->tail->data;
}

void* LinkedListSearch(LinkedList* LL, void* data)
{
    Node* node = (Node*)malloc(sizeof (Node));
    while(node) {
        if(!LL->compare_function(data, node->data)) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

bool LinkedListPushHead(LinkedList* LL, void* data)
{
    Node* node = NodeCreate(LL->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, LL->data_size);
    node->previous = NULL;
    if(LL->size) {
        LL->head->previous = node;
        node->next = LL->head;
    }
    else {
        LL->tail = node;
        node->next = NULL;
    }
    LL->head = node;
    LL->size = LL->size + 1;
    return true;
}

bool LinkedListPushTail(LinkedList* LL, void* data)
{
    Node* node = NodeCreate(LL->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, LL->data_size);
    node->next = NULL;
    if(LL->size) {
        LL->tail->next = node;
        node->previous = LL->tail;
    }
    else {
        LL->head = node;
        node->previous = NULL;
    }
    LL->tail = node;
    LL->size = LL->size + 1;
    return true;
}

bool LinkedListInsert(LinkedList* LL, size_t index, void* data)
{
    Node* node = NodeCreate(LL->data_size);
    Node* node_previous = LL->head;
    if(!node) {
        return false;
    }
    memcpy(node->data, data, LL->data_size);
    if(!index) {
        LinkedListPushHead(LL, data);
    }
    else if(index == LL->size) {
        LinkedListPushTail(LL, data);
    }
    else {
        for(size_t i = 0; i < index-1; ++i) {
            node_previous = node_previous->next;
        }
        node->previous = node_previous;
        node->next = node_previous->next;
        node->next->previous = node;
        node_previous->next = node;
    }
    LL->size = LL->size + 1;
    return true;
}

bool LinkedListSortedInsert(LinkedList* LL, void* data)
{
    if(LL->size || LL->compare_function(data, LL->head->data) < 0) {
        return LinkedListPushHead(LL, data);
    }
    if(LL->compare_function(data, LL->tail->data) > 0) {
        return LinkedListPushTail(LL, data);
    }
    Node* node_previous = LL->head;
    Node* node = NodeCreate(LL->data_size);
    if(!node) {
        return false;
    }
    while(LL->compare_function(data, node_previous->data) < 0) {
        node_previous = node_previous->next;
    }
    node->next = node_previous->next;
    node_previous->next = node;
    node->previous = node_previous;
    if(node->next) {
        node->next->previous = node;
    }
    LL->size = LL->size + 1;
    return true;
}

void LinkedListPopHead(LinkedList* LL)
{
    Node* node = LL->head;
    LL->head = LL->head->next;
    if(!LL->head) {
        LL->tail = NULL;
    }
    NodeDestroy(node);
    LL->size = LL->size - 1;
}

bool LinkedListPopTail(LinkedList* LL)
{
    Node* node = LL->tail;
    LL->tail = LL->tail->previous;
    if(LL->tail) {
        LL->tail->next = NULL;
    }
    NodeDestroy(node);
    LL->size = LL->size - 1;
}

void LinkedListErase(LinkedList* LL, size_t index)
{
    if(index == 1) {
        LinkedListPopHead(LL);
    }
    Node* node = LL->head;
    for(size_t i = 0; i < index-1; i++) {
        node->previous = node;
        node = node->next;
    }
    node->previous->next = node->next;
    free(node);
}

void LinkedListRemove(LinkedList* LL, void* data)
{
    Node* node = LL->head;
    size_t count = 0;
    while(node) {
        if(!LL->compare_function(data, node->data)) {
            break;
        }
        count = count + 1;
        node = node->next;
    }
    LinkedListErase(LL, count);
}

void LinkedListTraverse(LinkedList* LL, void (*function)(void *))
{
    Node* node = LL->head;
    while(node) {
        function(node->data);
        node = node->next;
    }
}