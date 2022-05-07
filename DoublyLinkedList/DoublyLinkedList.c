#include "DoublyLinkedList.h"

DoublyLinkedList* DoublyLinkedList_create(size_t data_size,
    int (*compare)(void* data1, void* data2));
void DoublyLinkedList_destroy(DoublyLinkedList* );

static DoublyLinkedListNode* doubly_linked_list_node_create(size_t data_size);
static void doubly_linked_list_node_destroy(DoublyLinkedListNode* node);

int DoublyLinkedList_push_head(DoublyLinkedList* DLL, void* data);
int DoublyLinkedList_push_tail(DoublyLinkedList* DLL, void* data);
int DoublyLinkedList_insert(DoublyLinkedList* DLL, size_t index, void* data);
int DoublyLinkedList_sorted_insert(DoublyLinkedList* DLL, void* data);
int DoublyLinkedList_pop_head(DoublyLinkedList* DLL);
int DoublyLinkedList_pop_tail(DoublyLinkedList* DLL);
int DoublyLinkedList_remove(DoublyLinkedList* DLL, void* data);
int DoublyLinkedList_erase(DoublyLinkedList* DLL, size_t index);
int DoublyLinkedList_update(DoublyLinkedList* DLL, size_t index, void* data);

DoublyLinkedListNode* DoublyLinkedList_search(DoublyLinkedList* DLL, void* data);
DoublyLinkedListNode* DoublyLinkedList_at(DoublyLinkedList* DLL, size_t index);

void* DoublyLinkedList_head(DoublyLinkedList* DLL);
void* DoublyLinkedList_tail(DoublyLinkedList* DLL);

DoublyLinkedList* DoublyLinkedList_create(size_t data_size, int (*compare)(void* data1, void* data2))
{
    DoublyLinkedList* DLL = malloc(sizeof (DoublyLinkedList));
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

static DoublyLinkedListNode* doubly_linked_list_node_create(size_t data_size)
{
    DoublyLinkedListNode* node = malloc(sizeof (DoublyLinkedListNode));
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

static void doubly_linked_list_node_destroy(DoublyLinkedListNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

DoublyLinkedListNode* DoublyLinkedList_search(DoublyLinkedList* DLL, void* data)
{
    if(!DLL->size) {
        return NULL;
    }
    DoublyLinkedListNode* node = malloc(sizeof (DoublyLinkedListNode));
    while(node) {
        if(!DLL->compare(data, node->data)) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

int DoublyLinkedList_push_head(DoublyLinkedList* DLL, void* data)
{
    DoublyLinkedListNode* node = doubly_linked_list_node_create(DLL->data_size);
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

int DoublyLinkedList_push_tail(DoublyLinkedList* DLL, void* data)
{
    DoublyLinkedListNode* node = doubly_linked_list_node_create(DLL->data_size);
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

int DoublyLinkedList_insert(DoublyLinkedList* DLL, size_t index, void* data)
{
    if(index > DLL->size) {
        return 0;
    }
    DoublyLinkedListNode* pointer = DLL->head;
    DoublyLinkedListNode* node = doubly_linked_list_node_create(DLL->data_size);
    if(!node) {
        return 0;
    }
    memcpy(node->data, data, DLL->data_size);
    if(!index) {
        DoublyLinkedList_push_head(DLL, data);
    }
    else if(index == DLL->size) {
        DoublyLinkedList_push_tail(DLL, data);
    }
    else {
        for(size_t i = 0; i < index-1; ++i) {
            pointer = pointer->next;
        }
        node->previous = pointer;
        node->next = pointer->next;
        pointer->next->previous = node;
        pointer->next = node;
    }
    DLL->size = DLL->size + 1;
    return 1;
}

// int DoublyLinkedList_sorted_insert(DoublyLinkedList* DLL, void* data)
// {

// }

int DoublyLinkedList_pop_head(DoublyLinkedList* DLL)
{
    if(!DLL->size) {
        return 0;
    }
    DoublyLinkedListNode* pointer = DLL->head;
    DLL->head = DLL->head->next;
    if(!DLL->head) {
        DLL->tail = NULL;
    }
    doubly_linked_list_node_destroy(pointer);
    DLL->size = DLL->size - 1;
    return 1;
}

int DoublyLinkedList_pop_tail(DoublyLinkedList* DLL)
{
    if(!DLL->size) {
        return 0;
    }
    DoublyLinkedListNode* pointer = DLL->tail;
    DLL->tail = DLL->tail->previous;
    if(DLL->tail) {
        DLL->tail->next = NULL;
    }
    doubly_linked_list_node_destroy(pointer);
    DLL->size = DLL->size - 1;
    return 1;
}

int DoublyLinkedList_erase(DoublyLinkedList* DLL, size_t index)
{
    if(index == 0 || index > DLL->size) {
        return 0;
    }
    if(index == 1) {
        DoublyLinkedList_pop_head(DLL);
    }
    DoublyLinkedListNode* pointer = DLL->head;
    for(size_t i = 0; i < index-1; ++i) {
        pointer->previous = pointer;
        pointer = pointer->next;
    }
    pointer->previous->next = pointer->next;
    free(pointer);
    return 1;
}

int DoublyLinkedList_remove(DoublyLinkedList* DLL, void* data)
{
    DoublyLinkedListNode* pointer = DLL->head;
    size_t count = 0;
    while(pointer) {
        if(!DLL->compare(data, pointer->data)) {
            break;
        }
        count++;
        pointer = pointer->next;
    }
    DoublyLinkedList_erase(DLL, count);
    return 1;
}

void* DoublyLinkedList_head(DoublyLinkedList* DLL)
{
    if(!DLL->head) {
        return NULL;
    }
    return DLL->head->data;
}

void* DoublyLinkedList_back(DoublyLinkedList* DLL)
{
    if(!DLL->tail) {
        return NULL;
    }
    return DLL->tail->data;
}
