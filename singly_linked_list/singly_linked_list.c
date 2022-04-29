#include "singly_linked_list.h"

SinglyLinkedList* SinglyLinkedList_create(size_t data_size,
    int (*compare)(void* data, void* node_data));
void SinglyLinkedList_destroy(SinglyLinkedList* SLL);

static SinglyLinkedListNode* singly_linked_list_node_create(size_t data_size);
static void singly_linked_list_node_destroy(SinglyLinkedListNode* node);

bool SinglyLinkedList_push_head(SinglyLinkedList* SLL, void* data);
bool SinglyLinkedList_push_tail(SinglyLinkedList* SLL, void* data);
bool SinglyLinkedList_insert(SinglyLinkedList* SLL, size_t index, void* data);
bool SinglyLinkedList_sorted_insert(SinglyLinkedList* SLL, void* data);
bool SinglyLinkedList_pop_head(SinglyLinkedList* SLL);
bool SinglyLinkedList_pop_tail(SinglyLinkedList* SLL);
bool SinglyLinkedList_remove(SinglyLinkedList* SLL, void* data);
bool SinglyLinkedList_erase(SinglyLinkedList* SLL, size_t index);
bool SinglyLinkedList_update(SinglyLinkedList* SLL, size_t index, void* data);
bool SinglyLinkedList_linear(SinglyLinkedList* SLL);
bool SinglyLinkedList_circular(SinglyLinkedList* SLL);

SinglyLinkedListNode* SinglyLinkedList_search(SinglyLinkedList* SLL, void* data);
SinglyLinkedListNode* SinglyLinkedList_at(SinglyLinkedList* SLL, size_t index);

void* SinglyLinkedListNode_data(SinglyLinkedListNode* node);
SinglyLinkedListNode* SinglyLinkedListNode_next(SinglyLinkedListNode* node);

SinglyLinkedList* SinglyLinkedList_create(size_t data_size,
    int (*compare)(void* data, void* node_data))
{
    SinglyLinkedList* SLL = malloc(sizeof (SinglyLinkedList));
    if(!SLL) {
        return NULL;
    }
    SLL->head = NULL;
    SLL->tail = NULL;
    SLL->data_size = data_size;
    SLL->size = 0;
    SLL->compare = compare;
    return SLL;
}

void SinglyLinkedList_destroy(SinglyLinkedList* SLL)
{
    free(SLL->head);
    SLL->head = NULL;
}

static SinglyLinkedListNode* singly_linked_list_node_create(size_t data_size)
{
    SinglyLinkedListNode* node = malloc(sizeof (SinglyLinkedListNode));
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

static void singly_linked_list_node_destroy(SinglyLinkedListNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}


bool SinglyLinkedList_push_head(SinglyLinkedList* SLL, void* data)
{
    SinglyLinkedListNode* node = singly_linked_list_node_create(SLL->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, SLL->data_size);
    if(SLL->size) {
        node->next = SLL->head;
    }
    else {
        node->next = NULL;
        SLL->tail = node;
    }
    SLL->head = node;
    SLL->size = SLL->size + 1;
    return true;
}

bool SinglyLinkedList_push_tail(SinglyLinkedList* SLL, void* data)
{
    SinglyLinkedListNode* node = singly_linked_list_node_create(SLL->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, SLL->data_size);
    node->next = NULL;
    if(SLL->size) {
        SLL->tail->next = node;
    }
    else {
        SLL->head = node;
    }
    SLL->tail = node;
    SLL->size = SLL->size + 1;
    return true;
}

bool SinglyLinkedList_insert(SinglyLinkedList* SLL, size_t index, void* data)
{
    if(!index) {
        SinglyLinkedList_push_head(SLL, data);
        return true;
    }
    if(index == SLL->size) {
        SinglyLinkedList_push_tail(SLL, data);
        return true;
    }
    if(index > SLL->size) {
        return false;
    }
    SinglyLinkedListNode* node = SLL->head;
    SinglyLinkedListNode* node_new = singly_linked_list_node_create(SLL->data_size);
    if(!node_new) {
        return false;
    }
    memcpy(node_new->data, data, SLL->data_size);
    for(size_t i = 0; i < index-1; i++) {
        node = node->next;
    }
    node_new->next = node->next;
    node->next = node_new;
    SLL->size = SLL->size + 1;
    return true;
}

bool SinglyLinkedList_sorted_insert(SinglyLinkedList* SLL, void* data)
{
    if(!SLL->size || SLL->compare(data, SLL->head->data) < 0) {
        SinglyLinkedList_push_head(SLL, data);
        return true;
    }
    if(SLL->compare(data, SLL->tail->data) > 0) {
        SinglyLinkedList_push_tail(SLL, data);
        return true;
    }
    SinglyLinkedListNode* node = SLL->head;
    SinglyLinkedListNode* node_new = singly_linked_list_node_create(SLL->data_size);
    if(!node_new) {
        return false;
    }
    memcpy(node_new->data, data, SLL->data_size);
    while(node && data > node->next->data) {
        node = node->next;
    }
    node_new->next = node->next;
    node->next = node_new;
    SLL->size = SLL->size + 1;
    return true;
}

bool SinglyLinkedList_pop_head(SinglyLinkedList* SLL)
{
    if(!SLL->size) {
        return false;
    }
    SinglyLinkedListNode* node = SLL->head;
    SLL->head = SLL->head->next;
    if(!SLL->size) {
        SLL->tail = NULL;
    }
    singly_linked_list_node_destroy(node);
    SLL->size = SLL->size - 1;
    return true;
}

bool SinglyLinkedList_pop_tail(SinglyLinkedList* SLL)
{
    if(!SLL->size) {
        return false;
    }
    if(SLL->head == SLL->tail) {
        free(SLL->head);
        SLL->head = NULL;
        return false;
    }
    SinglyLinkedListNode* node = SLL->head;
    while(node->next != SLL->tail) {
        node = node->next;
    }
    node->next = NULL;
    free(SLL->tail);
    SLL->tail = node;
    SLL->size = SLL->size - 1;
    return true;
}

bool SinglyLinkedList_erase(SinglyLinkedList* SLL, size_t index)
{
    if(!index) {
        SinglyLinkedList_pop_head(SLL);
        return true;
    }
    if(index > SLL->size) {
        return false;
    }
    SinglyLinkedListNode* node = SLL->head;
    SinglyLinkedListNode* node_previous;
    for(size_t i = 0; i < index-1; i++) {
        node_previous = node;
        node = node->next;
    }
    node_previous->next = node->next;
    free(node);
    SLL->size = SLL->size - 1;
    return true;
}

// bool SinglyLinkedList_remove(SinglyLinkedList* SLL, void* data)
// {
//     SinglyLinkedListNode* node = SLL->head;
//     size_t count = 0;

//     while(node) {
//         count = count + 1;
//         if(node->data == data)
//             SinglyLinkedList_erase(SLL, count);
//     }

//     SLL->size = SLL->size - 1;

//     return true;
// }

bool SinglyLinkedList_linear(SinglyLinkedList* SLL)
{
    if(SLL->tail->next) {
        SLL->tail->next = NULL;
    }
    return true;
}

bool SinglyLinkedList_circular(SinglyLinkedList* SLL)
{
    if(!SLL->tail->next) {
        SLL->tail->next = SLL->head;
    }
    return true;
}

SinglyLinkedListNode* search(SinglyLinkedList* SLL, void* data)
{
    if(!SLL->head) {
        return NULL;
    }
    SinglyLinkedListNode* node = malloc(sizeof (SinglyLinkedListNode));
    if(!node) {
        return NULL;
    }
    while(node) {
        if(SLL->compare(data, node->data)) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}
