#include "LinkedList.h"

LinkedList* LinkedList_create(size_t data_size,
    int (*compare)(void* data1, void* data2));
void LinkedList_destroy(LinkedList* );

void* LinkedList_head(LinkedList* DLL);
void* LinkedList_tail(LinkedList* DLL);

static LinkedListNode* LinkedListNode_create(size_t data_size);
static void LinkedListNode_destroy(LinkedListNode* node);

int LinkedList_push_head(LinkedList* DLL, void* data);
int LinkedList_push_tail(LinkedList* DLL, void* data);
int LinkedList_insert(LinkedList* DLL, size_t index, void* data);
int LinkedList_sorted_insert(LinkedList* DLL, void* data);
int LinkedList_pop_head(LinkedList* DLL);
int LinkedList_pop_tail(LinkedList* DLL);
int LinkedList_remove(LinkedList* DLL, void* data);
int LinkedList_erase(LinkedList* DLL, size_t index);
int LinkedList_update(LinkedList* DLL, size_t index, void* data);

LinkedListNode* LinkedList_search(LinkedList* DLL, void* data);
LinkedListNode* LinkedList_at(LinkedList* DLL, size_t index);

LinkedList* LinkedList_create(size_t data_size, int (*compare)(void* data1, void* data2))
{
    LinkedList* DLL = malloc(sizeof (LinkedList));
    if(!DLL) {
        return NULL;
    }
    DLL->head = NULL;
    DLL->tail = NULL;
    DLL->data_size = data_size;
    DLL->size = 0;
    DLL->compare = compare;
    return DLL;
}

static LinkedListNode* LinkedListNode_create(size_t data_size)
{
    LinkedListNode* node = malloc(sizeof (LinkedListNode));
    if(!node) {
        return NULL;
    }
    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        node = NULL;  
        return NULL;
    }
    return node;
}

static void LinkedListNode_destroy(LinkedListNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

void* LinkedList_head(LinkedList* DLL)
{
    return DLL->head->data;
}

void* LinkedList_back(LinkedList* DLL)
{
    return DLL->tail->data;
}

LinkedListNode* LinkedList_search(LinkedList* DLL, void* data)
{
    if(!DLL->size) {
        return NULL;
    }
    LinkedListNode* node = malloc(sizeof (LinkedListNode));
    while(node) {
        if(!DLL->compare(data, node->data)) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

int LinkedList_push_head(LinkedList* DLL, void* data)
{
    LinkedListNode* node = LinkedListNode_create(DLL->data_size);
    if(!node) {
        return 0;
    }
    memcpy(node->data, data, DLL->data_size);
    node->previous = NULL;
    if(DLL->size) {
        DLL->head->previous = node;
        node->next = DLL->head;
    }
    else {
        DLL->tail = node;
        node->next = NULL;
    }
    DLL->head = node;
    DLL->size = DLL->size + 1;
    return 1;
}

int LinkedList_push_tail(LinkedList* DLL, void* data)
{
    LinkedListNode* node = LinkedListNode_create(DLL->data_size);
    if(!node) {
        return 0;
    }
    memcpy(node->data, data, DLL->data_size);
    node->next = NULL;
    if(DLL->size) {
        DLL->tail->next = node;
        node->previous = DLL->tail;
    }
    else {
        DLL->head = node;
        node->previous = NULL;
    }
    DLL->tail = node;
    DLL->size = DLL->size + 1;
    return 1;
}

int LinkedList_insert(LinkedList* DLL, size_t index, void* data)
{
    if(index > DLL->size) {
        return 0;
    }
    LinkedListNode* node = LinkedListNode_create(DLL->data_size);
    LinkedListNode* node_previous = DLL->head;
    if(!node) {
        return 0;
    }
    memcpy(node->data, data, DLL->data_size);
    if(!index) {
        LinkedList_push_head(DLL, data);
    }
    else if(index == DLL->size) {
        LinkedList_push_tail(DLL, data);
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
    DLL->size = DLL->size + 1;
    return 1;
}

// int LinkedList_sorted_insert(LinkedList* DLL, void* data)
// {

// }

int LinkedList_pop_head(LinkedList* DLL)
{
    if(!DLL->size) {
        return 0;
    }
    LinkedListNode* node = DLL->head;
    DLL->head = DLL->head->next;
    if(!DLL->head) {
        DLL->tail = NULL;
    }
    LinkedListNode_destroy(node);
    DLL->size = DLL->size - 1;
    return 1;
}

int LinkedList_pop_tail(LinkedList* DLL)
{
    if(!DLL->size) {
        return 0;
    }
    LinkedListNode* node = DLL->tail;
    DLL->tail = DLL->tail->previous;
    if(DLL->tail) {
        DLL->tail->next = NULL;
    }
    LinkedListNode_destroy(node);
    DLL->size = DLL->size - 1;
    return 1;
}

int LinkedList_erase(LinkedList* DLL, size_t index)
{
    if(index == 0 || index > DLL->size) {
        return 0;
    }
    if(index == 1) {
        LinkedList_pop_head(DLL);
    }
    LinkedListNode* node = DLL->head;
    for(size_t i = 0; i < index-1; ++i) {
        node->previous = node;
        node = node->next;
    }
    node->previous->next = node->next;
    free(node);
    return 1;
}

int LinkedList_remove(LinkedList* DLL, void* data)
{
    LinkedListNode* node = DLL->head;
    size_t count = 0;
    while(node) {
        if(!DLL->compare(data, node->data)) {
            break;
        }
        count++;
        node = node->next;
    }
    LinkedList_erase(DLL, count);
    return 1;
}

