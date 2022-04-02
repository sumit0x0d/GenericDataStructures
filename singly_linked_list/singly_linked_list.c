#include "singly_linked_list.h"

SinglyLinkedList singly_linked_list_create(int (*compare_data)(void *data, void *node_data));
void singly_linked_list_destroy(SinglyLinkedList *SLL);

SinglyLinkedListNode *singly_linked_list_head(SinglyLinkedList *SLL);
SinglyLinkedListNode *singly_linked_list_tail(SinglyLinkedList *SLL);
size_t singly_linked_list_size(SinglyLinkedList *SLL);

static SinglyLinkedListNode *node_create(size_t data_size);
static void node_destroy(SinglyLinkedListNode *node);

SinglyLinkedListNode *singly_linked_list_search(SinglyLinkedList *SLL, void *data, size_t data_size);
bool singly_linked_list_push_front(SinglyLinkedList *SLL, void *data, size_t data_size);
bool singly_linked_list_push_back(SinglyLinkedList *SLL, void *data, size_t data_size);
bool singly_linked_list_insert(SinglyLinkedList *SLL, size_t index, void *data, size_t data_size);
bool singly_linked_list_sorted_insert(SinglyLinkedList *SLL, void *data, size_t data_size);
bool singly_linked_list_pop_front(SinglyLinkedList *SLL);
bool singly_linked_list_pop_back(SinglyLinkedList *SLL);
// bool singly_linked_list_remove(SinglyLinkedList *SLL, void *data);
bool singly_linked_list_erase(SinglyLinkedList *SLL, size_t index);
bool singly_linked_list_linear(SinglyLinkedList *SLL);
bool singly_linked_list_circular(SinglyLinkedList *SLL);

SinglyLinkedList singly_linked_list_create(int (*compare_data)(void *data, void *node_data))
{
    SinglyLinkedList SLL;

    SLL.head = NULL;
    SLL.tail = NULL;
    SLL.size = 0;

    SLL.compare_data = compare_data;

    return SLL;
}

// void singly_linked_list_destroy(SinglyLinkedList *SLL)
// {

// }

SinglyLinkedListNode *singly_linked_list_head(SinglyLinkedList *SLL)
{
    return SLL->head;
}

SinglyLinkedListNode *singly_linked_list_tail(SinglyLinkedList *SLL)
{
    return SLL->tail;
}

size_t singly_linked_list_size(SinglyLinkedList *SLL)
{
    return SLL->size;
}

static SinglyLinkedListNode *node_create(size_t data_size)
{
    SinglyLinkedListNode *node = malloc(sizeof (SinglyLinkedListNode));
    if(!node) return NULL;

    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    return node;
}

static void node_destroy(SinglyLinkedListNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

// SinglyLinkedListNode *search(SinglyLinkedList *SLL, int data)
// {
//     if(!SLL->size) return NULL;

//     SinglyLinkedListNode *node = malloc(sizeof (SinglyLinkedListNode));
//     if(!node) return NULL;
    
//     while(node) {
//         if(data == node->data)
//             return node;
//         node = node->next;
//     }

//     return NULL;
// }

bool singly_linked_list_push_front(SinglyLinkedList *SLL, void *data, size_t data_size)
{
    SinglyLinkedListNode *node = node_create(data_size);
    if(!node) return false;

    memcpy(node->data, data, data_size);

    if(SLL->size)
        node->next = SLL->head;
    else {
        node->next = NULL;
        SLL->tail = node;
    }
    SLL->head = node;

    SLL->size = SLL->size + 1;

    return true;
}

bool singly_linked_list_push_back(SinglyLinkedList *SLL, void *data, size_t data_size)
{
    SinglyLinkedListNode *node = node_create(data_size);
    if(!node) return false;

    memcpy(node->data, data, data_size);

    node->next = NULL;
    if(SLL->size)
        SLL->tail->next = node;
    else
        SLL->head = node;
    SLL->tail = node;
    
    SLL->size = SLL->size + 1;

    return true;
}

bool singly_linked_list_insert(SinglyLinkedList *SLL, size_t index, void *data, size_t data_size)
{
    if(!index) {
        singly_linked_list_push_front(SLL, data, data_size);
        return true;
    }

    if(index == SLL->size) {
        singly_linked_list_push_back(SLL, data, data_size);
        return true;
    }

    if(index > SLL->size)
        return false;

    SinglyLinkedListNode *node = SLL->head;
    SinglyLinkedListNode *node_new = node_create(data_size);
    if(!node_new) return false;

    memcpy(node_new->data, data, data_size);

    for(size_t i = 0; i < index-1; i++)
        node = node->next;
    node_new->next = node->next;
    node->next = node_new;

    SLL->size = SLL->size + 1;

    return true;
}

bool singly_linked_list_sorted_insert(SinglyLinkedList *SLL, void *data, size_t data_size)
{
    if(!SLL->size || memcmp(data, SLL->head->data, data_size) < 0) {
        singly_linked_list_push_front(SLL, data, data_size);
        return true;
    }

    if(memcmp(data, SLL->tail->data, data_size) > 0) {
        singly_linked_list_push_back(SLL, data, data_size);
        return true;
    }

    SinglyLinkedListNode *node = SLL->head;
    SinglyLinkedListNode *node_new = node_create(data_size);
    if(!node_new) return false;

    memcpy(node_new->data, data, data_size);

    while(node && data > node->next->data) {
        node = node->next;
    }
    node_new->next = node->next;
    node->next = node_new;

    SLL->size = SLL->size + 1;

    return true;
}

bool singly_linked_list_pop_front(SinglyLinkedList *SLL)
{
    if(!SLL->size) return false;

    SinglyLinkedListNode *node = SLL->head;

    SLL->head = SLL->head->next;
    if(!SLL->size)
        SLL->tail = NULL;

    node_destroy(node);

    SLL->size = SLL->size - 1;

    return true;
}

bool singly_linked_list_pop_back(SinglyLinkedList *SLL)
{
    if(!SLL->size) return false;

    if(SLL->head == SLL->tail) {
        free(SLL->head);
        return false;
    }

    SinglyLinkedListNode *node = SLL->head;

    while(node->next != SLL->tail)
        node = node->next;
    node->next = NULL;
    free(SLL->tail);
    SLL->tail = node;

    SLL->size = SLL->size - 1;

    return true;
}

bool singly_linked_list_erase(SinglyLinkedList *SLL, size_t index)
{
    if(!index) {
        singly_linked_list_pop_front(SLL);
        return true;
    }
    if(index > SLL->size)
        return false;

    SinglyLinkedListNode *node = SLL->head;
    SinglyLinkedListNode *node_previous;

    for(size_t i = 0; i < index-1; i++) {
        node_previous = node;
        node = node->next;
    }
    node_previous->next = node->next;
    free(node);

    SLL->size = SLL->size - 1;

    return true;
}

// bool singly_linked_list_remove(SinglyLinkedList *SLL, void *data, size_t data_size)
// {
//     SinglyLinkedListNode *node = SLL->head;
//     size_t count = 0;

//     while(node) {
//         count = count + 1;
//         if(node->data == data)
//             singly_linked_list_erase(SLL, count);
//     }

//     SLL->size = SLL->size - 1;

//     return true;
// }

bool singly_linked_list_linear(SinglyLinkedList *SLL)
{
    if(SLL->tail->next)
        SLL->tail->next = NULL;
    
    return true;
}

bool singly_linked_list_circular(SinglyLinkedList *SLL)
{
    if(!SLL->tail->next)
        SLL->tail->next = SLL->head;
    
    return true;
}
