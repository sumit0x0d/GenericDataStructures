#include "LinkedList.h"

static LinkedListNode* node_create(size_t data_size);
static void node_destroy(LinkedListNode* node);

LinkedList* LinkedList_create(size_t data_size, int (*compare)(void* data1, void* data2))
{
    LinkedList* LL = (LinkedList*)malloc(sizeof (LinkedList));
    if(!LL) {
        return NULL;
    }
    LL->head = NULL;
    LL->tail = NULL;
    LL->data_size = data_size;
    LL->size = 0;
    LL->compare = compare;
    return LL;
}

void* LinkedList_head(LinkedList* LL)
{
    return LL->head->data;
}

void* LinkedList_back(LinkedList* LL)
{
    return LL->tail->data;
}

static LinkedListNode* node_create(size_t data_size)
{
    LinkedListNode* node = (LinkedListNode*)malloc(sizeof (LinkedListNode));
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

static void node_destroy(LinkedListNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

LinkedListNode* LinkedList_search(LinkedList* LL, void* data)
{
    if(!LL->size) {
        return NULL;
    }
    LinkedListNode* node = (LinkedListNode*)malloc(sizeof (LinkedListNode));
    while(node) {
        if(!LL->compare(data, node->data)) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

int LinkedList_push_head(LinkedList* LL, void* data)
{
    LinkedListNode* node = node_create(LL->data_size);
    if(!node) {
        return 0;
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
    return 1;
}

int LinkedList_push_tail(LinkedList* LL, void* data)
{
    LinkedListNode* node = node_create(LL->data_size);
    if(!node) {
        return 0;
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
    return 1;
}

int LinkedList_insert(LinkedList* LL, size_t index, void* data)
{
    if(index > LL->size) {
        return 0;
    }
    LinkedListNode* node = node_create(LL->data_size);
    LinkedListNode* node_previous = LL->head;
    if(!node) {
        return 0;
    }
    memcpy(node->data, data, LL->data_size);
    if(!index) {
        LinkedList_push_head(LL, data);
    }
    else if(index == LL->size) {
        LinkedList_push_tail(LL, data);
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
    return 1;
}

int LinkedList_sorted_insert(LinkedList* LL, void* data)
{
    if(LL->size || LL->compare(data, LL->head->data) < 0) {
        return LinkedList_push_head(LL, data);
    }
    if(LL->compare(data, LL->tail->data) > 0) {
        return LinkedList_push_tail(LL, data);
    }
    LinkedListNode* node_previous = LL->head;
    LinkedListNode* node = node_create(LL->data_size);
    if(!node) {
        return 0;
    }
    while(LL->compare(data, node_previous->data) < 0) {
        node_previous = node_previous->next;
    }
    node->next = node_previous->next;
    node_previous->next = node;
    node->previous = node_previous;
    if(node->next) {
        node->next->previous = node;
    }
    LL->size = LL->size + 1;
    return 1;
}

int LinkedList_pop_head(LinkedList* LL)
{
    if(!LL->size) {
        return 0;
    }
    LinkedListNode* node = LL->head;
    LL->head = LL->head->next;
    if(!LL->head) {
        LL->tail = NULL;
    }
    node_destroy(node);
    LL->size = LL->size - 1;
    return 1;
}

int LinkedList_pop_tail(LinkedList* LL)
{
    if(!LL->size) {
        return 0;
    }
    LinkedListNode* node = LL->tail;
    LL->tail = LL->tail->previous;
    if(LL->tail) {
        LL->tail->next = NULL;
    }
    node_destroy(node);
    LL->size = LL->size - 1;
    return 1;
}

int LinkedList_erase(LinkedList* LL, size_t index)
{
    if(index == 0 || index > LL->size) {
        return 0;
    }
    if(index == 1) {
        LinkedList_pop_head(LL);
    }
    LinkedListNode* node = LL->head;
    for(size_t i = 0; i < index-1; ++i) {
        node->previous = node;
        node = node->next;
    }
    node->previous->next = node->next;
    free(node);
    return 1;
}

int LinkedList_remove(LinkedList* LL, void* data)
{
    LinkedListNode* node = LL->head;
    size_t count = 0;
    while(node) {
        if(!LL->compare(data, node->data)) {
            break;
        }
        count = count + 1;
        node = node->next;
    }
    LinkedList_erase(LL, count);
    return 1;
}

