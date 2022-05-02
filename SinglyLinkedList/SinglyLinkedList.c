#include "SinglyLinkedList.h"

SinglyLinkedList* SinglyLinkedList_create(size_t data_size,
    int (*compare)(void* data, void* node_data));
void SinglyLinkedList_destroy(SinglyLinkedList* SLL);

static SinglyLinkedListNode* SinglyLinkedListNode_create(size_t data_size);
static void SinglyLinkedListNode_destroy(SinglyLinkedListNode* node);

bool SinglyLinkedList_push_head(SinglyLinkedList* SLL, void* data);
bool SinglyLinkedList_push_tail(SinglyLinkedList* SLL, void* data);
bool SinglyLinkedList_insert(SinglyLinkedList* SLL, size_t index, void* data);
bool SinglyLinkedList_sorted_insert(SinglyLinkedList* SLL, void* data);
bool SinglyLinkedList_pop_head(SinglyLinkedList* SLL);
bool SinglyLinkedList_pop_tail(SinglyLinkedList* SLL);
bool SinglyLinkedList_remove(SinglyLinkedList* SLL, void* data);
bool SinglyLinkedList_erase(SinglyLinkedList* SLL, size_t index);
bool SinglyLinkedList_update(SinglyLinkedList* SLL, size_t index, void* data);

SinglyLinkedListNode* SinglyLinkedList_search(SinglyLinkedList* SLL, void* data);
SinglyLinkedListNode* SinglyLinkedList_at(SinglyLinkedList* SLL, size_t index);

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


bool SinglyLinkedList_push_head(SinglyLinkedList* SLL, void* data)
{
    SinglyLinkedListNode* node = SinglyLinkedListNode_create(SLL->data_size);
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
    SinglyLinkedListNode* node = SinglyLinkedListNode_create(SLL->data_size);
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
    SinglyLinkedListNode* pointer = SLL->head;
    SinglyLinkedListNode* node = SinglyLinkedListNode_create(SLL->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, SLL->data_size);
    for(size_t i = 0; i < index-1; i++) {
        pointer = pointer->next;
    }
    node->next = pointer->next;
    pointer->next = node;
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
    SinglyLinkedListNode* pointer = SLL->head;
    SinglyLinkedListNode* node = SinglyLinkedListNode_create(SLL->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, SLL->data_size);
    while(pointer && data > pointer->next->data) {
        pointer = pointer->next;
    }
    node->next = pointer->next;
    pointer->next = node;
    SLL->size = SLL->size + 1;
    return true;
}

bool SinglyLinkedList_pop_head(SinglyLinkedList* SLL)
{
    if(!SLL->size) {
        return false;
    }
    SinglyLinkedListNode* pointer = SLL->head;
    SLL->head = SLL->head->next;
    if(!SLL->size) {
        SLL->tail = NULL;
    }
    SinglyLinkedListNode_destroy(pointer);
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
    SinglyLinkedListNode* pointer = SLL->head;
    while(pointer->next != SLL->tail) {
        pointer = pointer->next;
    }
    pointer->next = NULL;
    free(SLL->tail);
    SLL->tail = pointer;
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
    SinglyLinkedListNode* pointer = SLL->head;
    SinglyLinkedListNode* pointer_previous;
    for(size_t i = 0; i < index-1; i++) {
        pointer_previous = pointer;
        pointer = pointer->next;
    }
    pointer_previous->next = pointer->next;
    free(pointer);
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
