#include "doubly_linked_list.h"

DoublyLinkedList* DoublyLinkedList_create(size_t data_size,
    int (*compare)(void* data, void* node_data));
void DoublyLinkedList_destroy(DoublyLinkedList* );

static DoublyLinkedListNode* doubly_linked_list_node_create(size_t data_size);
static void doubly_linked_list_node_destroy(DoublyLinkedListNode* node);

bool DoublyLinkedList_push_head(DoublyLinkedList* DLL, void* data);
bool DoublyLinkedList_push_tail(DoublyLinkedList* DLL, void* data);
bool DoublyLinkedList_insert(DoublyLinkedList* DLL, size_t index, void* data);
bool DoublyLinkedList_sorted_insert(DoublyLinkedList* DLL, void* data);
bool DoublyLinkedList_pop_head(DoublyLinkedList* DLL);
bool DoublyLinkedList_pop_tail(DoublyLinkedList* DLL);
bool DoublyLinkedList_remove(DoublyLinkedList* DLL, void* data);
bool DoublyLinkedList_erase(DoublyLinkedList* DLL, size_t index);
bool DoublyLinkedList_update(DoublyLinkedList* DLL, size_t index, void* data);

DoublyLinkedListNode* DoublyLinkedList_search(DoublyLinkedList* DLL, void* data);
DoublyLinkedListNode* DoublyLinkedList_at(DoublyLinkedList* DLL, size_t index);

DoublyLinkedList* DoublyLinkedList_create(size_t data_size, int (*compare)(void* data, void* node_data))
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

bool DoublyLinkedList_push_head(DoublyLinkedList* DLL, void* data)
{
    DoublyLinkedListNode* node = doubly_linked_list_node_create(DLL->data_size);
    if(!node) {
        return false;
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
    return true;
}

bool DoublyLinkedList_push_tail(DoublyLinkedList* DLL, void* data)
{
    DoublyLinkedListNode* node = doubly_linked_list_node_create(DLL->data_size);
    if(!node) {
        return false;
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
    return true;
}

bool DoublyLinkedList_insert(DoublyLinkedList* DLL, size_t index, void* data)
{
    if(index > DLL->size) {
        return false;
    }
    DoublyLinkedListNode* pointer = DLL->head;
    DoublyLinkedListNode* node = doubly_linked_list_node_create(DLL->data_size);
    if(!node) {
        return false;
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
    return true;
}

// bool DoublyLinkedList_sorted_insert(DoublyLinkedList* DLL, void* data)
// {

// }

bool DoublyLinkedList_pop_head(DoublyLinkedList* DLL)
{
    if(!DLL->size) {
        return false;
    }
    DoublyLinkedListNode* pointer = DLL->head;
    DLL->head = DLL->head->next;
    if(!DLL->head) {
        DLL->tail = NULL;
    }
    doubly_linked_list_node_destroy(pointer);
    DLL->size = DLL->size - 1;
    return true;
}

bool DoublyLinkedList_pop_tail(DoublyLinkedList* DLL)
{
    if(!DLL->size) {
        return false;
    }
    DoublyLinkedListNode* pointer = DLL->tail;
    DLL->tail = DLL->tail->previous;
    if(DLL->tail) {
        DLL->tail->next = NULL;
    }
    doubly_linked_list_node_destroy(pointer);
    DLL->size = DLL->size - 1;
    return true;
}

bool DoublyLinkedList_erase(DoublyLinkedList* DLL, size_t index)
{
    if(index == 0 || index > DLL->size) {
        return false;
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
    return true;
}

bool DoublyLinkedList_remove(DoublyLinkedList* DLL, void* data)
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
    return true;
}
