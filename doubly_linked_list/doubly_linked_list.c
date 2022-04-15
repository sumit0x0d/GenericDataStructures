#include "doubly_linked_list.h"

typedef struct DoublyLinkedListNode {
    void* data;
    struct DoublyLinkedListNode* previous;
    struct DoublyLinkedListNode* next;
} DoublyLinkedListNode;

typedef struct DoublyLinkedList {
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;
    size_t data_size;
    size_t size;
    int (*compare)(void* data, void* node_data);
} DoublyLinkedList;

DoublyLinkedList* doubly_linked_list_create(size_t data_size,
    int (*compare)(void* data, void* node_data));
void doubly_linked_list_destroy(DoublyLinkedList* );

void* doubly_linked_list_head(DoublyLinkedList* DLL);
void* doubly_linked_list_tail(DoublyLinkedList* DLL);
size_t doubly_linked_list_size(DoublyLinkedList* DLL);

static inline DoublyLinkedListNode* node_create(size_t data_size);
static inline void node_destroy(DoublyLinkedListNode* node);

DoublyLinkedListNode* doubly_linked_list_search(DoublyLinkedList* DLL, void* data);
void* doubly_linked_list_at(DoublyLinkedList* DLL, size_t index);

bool doubly_linked_list_push_head(DoublyLinkedList* DLL, void* data);
bool doubly_linked_list_push_tail(DoublyLinkedList* DLL, void* data);
bool doubly_linked_list_insert(DoublyLinkedList* DLL, size_t index, void* data);
bool doubly_linked_list_sorted_insert(DoublyLinkedList* DLL, void* data);
bool doubly_linked_list_pop_head(DoublyLinkedList* DLL);
bool doubly_linked_list_pop_tail(DoublyLinkedList* DLL);
bool doubly_linked_list_remove(DoublyLinkedList* DLL, void* data);
bool doubly_linked_list_erase(DoublyLinkedList* DLL, size_t index);
bool doubly_linked_list_update(DoublyLinkedList* SLL, size_t index, void* data);
bool doubly_linked_list_linear(DoublyLinkedList* DLL);
bool doubly_linked_list_circular(DoublyLinkedList* DLL);

void* doubly_linked_list_node_data(DoublyLinkedListNode* node);
DoublyLinkedListNode* doubly_linked_list_node_next(DoublyLinkedListNode* node);
DoublyLinkedListNode* doubly_linked_list_node_previous(DoublyLinkedListNode* node);

DoublyLinkedList* doubly_linked_list_create(size_t data_size, int (*compare)(void* data, void* node_data))
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

void* doubly_linked_list_head(DoublyLinkedList* DLL)
{
    if(!DLL->head) {
        return NULL;
    }
    return DLL->head->data;
}

void* doubly_linked_list_tail(DoublyLinkedList* DLL)
{
    if(!DLL->tail) {
        return NULL;
    }
    return DLL->tail->data;
}

size_t doubly_linked_list_size(DoublyLinkedList* DLL)
{
    return DLL->size;
}

static inline DoublyLinkedListNode* node_create(size_t data_size)
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

static inline void node_destroy(DoublyLinkedListNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}


DoublyLinkedListNode* doubly_linked_list_search(DoublyLinkedList* DLL, void* data)
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

bool doubly_linked_list_push_head(DoublyLinkedList* DLL, void* data)
{
    DoublyLinkedListNode* node = node_create(DLL->data_size);
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

bool doubly_linked_list_push_tail(DoublyLinkedList* DLL, void* data)
{
    DoublyLinkedListNode* node = node_create(DLL->data_size);
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

bool doubly_linked_list_insert(DoublyLinkedList* DLL, size_t index, void* data)
{
    if(index > DLL->size) {
        return false;
    }
    DoublyLinkedListNode* node = DLL->head;
    DoublyLinkedListNode* node_new = node_create(DLL->data_size);
    if(!node_new) {
        return false;
    }
    memcpy(node_new->data, data, DLL->data_size);
    if(!index) {
        doubly_linked_list_push_head(DLL, data);
    }
    else if(index == DLL->size) {
        doubly_linked_list_push_tail(DLL, data);
    }
    else {
        for(size_t i = 0; i < index-1; ++i) {
            node = node->next;
        }
        node_new->previous = node;
        node_new->next = node->next;
        node->next->previous = node_new;
        node->next = node_new;
    }
    DLL->size = DLL->size + 1;
    return true;
}

// bool doubly_linked_list_sorted_insert(DoublyLinkedList* DLL, void* data)
// {

// }

bool doubly_linked_list_pop_head(DoublyLinkedList* DLL)
{
    if(!DLL->size) {
        return false;
    }
    DoublyLinkedListNode* node = DLL->head;
    DLL->head = DLL->head->next;
    if(!DLL->head) {
        DLL->tail = NULL;
    }
    node_destroy(node);
    DLL->size = DLL->size - 1;
    return true;
}

bool doubly_linked_list_pop_tail(DoublyLinkedList* DLL)
{
    if(!DLL->size) {
        return false;
    }
    DoublyLinkedListNode* node = DLL->tail;
    DLL->tail = DLL->tail->previous;
    if(DLL->tail) {
        DLL->tail->next = NULL;
    }
    node_destroy(node);
    DLL->size = DLL->size - 1;
    return true;
}

bool doubly_linked_list_erase(DoublyLinkedList* DLL, size_t index)
{
    if(index == 0 || index > DLL->size) {
        return false;
    }
    if(index == 1) {
        doubly_linked_list_pop_head(DLL);
    }
    DoublyLinkedListNode* node = DLL->head;
    for(size_t i = 0; i < index-1; ++i) {
        node->previous = node;
        node = node->next;
    }
    node->previous->next = node->next;
    free(node);
    return true;
}

bool doubly_linked_list_remove(DoublyLinkedList* DLL, void* data)
{
    DoublyLinkedListNode* node = DLL->head;
    size_t count = 0;
    while(node) {
        if(!DLL->compare(data, node->data)) {
            break;
        }
        count++;
        node = node->next;
    }
    erase(DLL, count);
    return true;
}

void* doubly_linked_list_node_data(DoublyLinkedListNode* node)
{
    if(!node) {
        return NULL;
    }
    return node->data;
}

DoublyLinkedListNode* doubly_linked_list_node_next(DoublyLinkedListNode* node)
{
    if(!node) {
        return NULL;
    }
    return node->next;
}

DoublyLinkedListNode* doubly_linked_list_node_previous(DoublyLinkedListNode* node)
{
    if(!node) {
        return NULL;
    }
    return node->previous;
}
