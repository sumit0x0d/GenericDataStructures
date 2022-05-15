#include "SinglyLinkedList.h"

SinglyLinkedList* SinglyLinkedList_create(size_t data_size,
    int (*compare)(void* data1, void* data2));
void SinglyLinkedList_destroy(SinglyLinkedList* SLL);

static SinglyLinkedListNode* SinglyLinkedListNode_create(size_t data_size);
static void SinglyLinkedListNode_destroy(SinglyLinkedListNode* node);

int SinglyLinkedList_push_head(SinglyLinkedList* SLL, void* data);
int SinglyLinkedList_push_tail(SinglyLinkedList* SLL, void* data);
int SinglyLinkedList_insert(SinglyLinkedList* SLL, size_t index, void* data);
int SinglyLinkedList_sorted_insert(SinglyLinkedList* SLL, void* data);
void SinglyLinkedList_pop_head(SinglyLinkedList* SLL);
int SinglyLinkedList_pop_tail(SinglyLinkedList* SLL);
int SinglyLinkedList_remove(SinglyLinkedList* SLL, void* data);
int SinglyLinkedList_erase(SinglyLinkedList* SLL, size_t index);
int SinglyLinkedList_update(SinglyLinkedList* SLL, size_t index, void* data);

SinglyLinkedListNode* SinglyLinkedList_search(SinglyLinkedList* SLL, void* data);
SinglyLinkedListNode* SinglyLinkedList_at(SinglyLinkedList* SLL, size_t index);

void* SinglyLinkedList_head(SinglyLinkedList* SLL);
void* SinglyLinkedList_tail(SinglyLinkedList* SLL);

SinglyLinkedList* SinglyLinkedList_create(size_t data_size,
    int (*compare)(void* data1, void* data2))
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

static SinglyLinkedListNode* SinglyLinkedListNode_create(size_t data_size)
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

static void SinglyLinkedListNode_destroy(SinglyLinkedListNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}


int SinglyLinkedList_push_head(SinglyLinkedList* SLL, void* data)
{
    SinglyLinkedListNode* node = SinglyLinkedListNode_create(SLL->data_size);
    if(!node) {
        return 0;
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
    return 1;
}

int SinglyLinkedList_push_tail(SinglyLinkedList* SLL, void* data)
{
    SinglyLinkedListNode* node = SinglyLinkedListNode_create(SLL->data_size);
    if(!node) {
        return 0;
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
    return 1;
}

int SinglyLinkedList_insert(SinglyLinkedList* SLL, size_t index, void* data)
{
    if(!index) {
        SinglyLinkedList_push_head(SLL, data);
        return 1;
    }
    if(index == SLL->size) {
        SinglyLinkedList_push_tail(SLL, data);
        return 1;
    }
    if(index > SLL->size) {
        return 0;
    }
    SinglyLinkedListNode* node = SinglyLinkedListNode_create(SLL->data_size);
    SinglyLinkedListNode* node_previous = SLL->head;
    if(!node) {
        return 0;
    }
    memcpy(node->data, data, SLL->data_size);
    for(size_t i = 0; i < index-1; i++) {
        node_previous = node_previous->next;
    }
    node->next = node_previous->next;
    node_previous->next = node;
    SLL->size = SLL->size + 1;
    return 1;
}

int SinglyLinkedList_sorted_insert(SinglyLinkedList* SLL, void* data)
{
    if(!SLL->size || SLL->compare(data, SLL->head->data) < 0) {
        SinglyLinkedList_push_head(SLL, data);
        return 1;
    }
    if(SLL->compare(data, SLL->tail->data) > 0) {
        SinglyLinkedList_push_tail(SLL, data);
        return 1;
    }
    SinglyLinkedListNode* node = SinglyLinkedListNode_create(SLL->data_size);
    SinglyLinkedListNode* node_previous = SLL->head;
    if(!node) {
        return 0;
    }
    memcpy(node->data, data, SLL->data_size);
    while(node_previous && node_previous->next->data < data) {
        node_previous = node_previous->next;
    }
    node->next = node_previous->next;
    node_previous->next = node;
    SLL->size = SLL->size + 1;
    return 1;
}

void SinglyLinkedList_pop_head(SinglyLinkedList* SLL)
{
    SinglyLinkedListNode* node = SLL->head;
    SLL->head = SLL->head->next;
    if(!SLL->size) {
        SLL->tail = NULL;
    }
    SinglyLinkedListNode_destroy(node);
    SLL->size = SLL->size - 1;
}

int SinglyLinkedList_pop_tail(SinglyLinkedList* SLL)
{
    if(SLL->head == SLL->tail) {
        free(SLL->head);
        SLL->head = NULL;
        return 0;
    }
    SinglyLinkedListNode* node = SLL->head;
    while(node->next != SLL->tail) {
        node = node->next;
    }
    node->next = NULL;
    free(SLL->tail);
    SLL->tail = node;
    SLL->size = SLL->size - 1;
    return 1;
}

int SinglyLinkedList_erase(SinglyLinkedList* SLL, size_t index)
{
    if(!index) {
        SinglyLinkedList_pop_head(SLL);
        return 1;
    }
    if(index > SLL->size) {
        return 0;
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
    return 1;
}

// int SinglyLinkedList_remove(SinglyLinkedList* SLL, void* data)
// {
//     SinglyLinkedListNode* node = SLL->head;
//     size_t count = 0;

//     while(node) {
//         count = count + 1;
//         if(node->data == data)
//             SinglyLinkedList_erase(SLL, count);
//     }

//     SLL->size = SLL->size - 1;

//     return 1;
// }

SinglyLinkedListNode* search(SinglyLinkedList* SLL, void* data)
{
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

void* SinglyLinkedList_head(SinglyLinkedList* SLL)
{
    return SLL->head->data;
}

void* SinglyLinkedList_tail(SinglyLinkedList* SLL)
{
    return SLL->tail->data;
}
