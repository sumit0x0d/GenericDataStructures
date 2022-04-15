#include "singly_linked_list.h"

typedef struct SinglyLinkedListNode {
    void* data;
    struct SinglyLinkedListNode* next;
} SinglyLinkedListNode;

typedef struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
    size_t data_size;
    size_t size;
    int (*compare)(void* data, void* node_data);
} SinglyLinkedList;

SinglyLinkedList* singly_linked_list_create(size_t data_size,
    int (*compare)(void* data, void* node_data));
void singly_linked_list_destroy(SinglyLinkedList* SLL);

void* singly_linked_list_head(SinglyLinkedList* SLL);
void* singly_linked_list_tail(SinglyLinkedList* SLL);
size_t singly_linked_list_size(SinglyLinkedList* SLL);

static inline SinglyLinkedListNode* node_create(size_t data_size);
static inline void node_destroy(SinglyLinkedListNode* node);

SinglyLinkedListNode* singly_linked_list_search(SinglyLinkedList* SLL, void* data);
void* singly_linked_list_at(SinglyLinkedList* SLL, size_t index);

bool singly_linked_list_push_head(SinglyLinkedList* SLL, void* data);
bool singly_linked_list_push_tail(SinglyLinkedList* SLL, void* data);
bool singly_linked_list_insert(SinglyLinkedList* SLL, size_t index, void* data);
bool singly_linked_list_sorted_insert(SinglyLinkedList* SLL, void* data);
bool singly_linked_list_pop_head(SinglyLinkedList* SLL);
bool singly_linked_list_pop_tail(SinglyLinkedList* SLL);
bool singly_linked_list_remove(SinglyLinkedList* SLL, void* data);
bool singly_linked_list_erase(SinglyLinkedList* SLL, size_t index);
bool singly_linked_list_update(SinglyLinkedList* SLL, size_t index, void* data);
bool singly_linked_list_linear(SinglyLinkedList* SLL);
bool singly_linked_list_circular(SinglyLinkedList* SLL);

SinglyLinkedList* singly_linked_list_create(size_t data_size,
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

void singly_linked_list_destroy(SinglyLinkedList* SLL)
{
    free(SLL->head);
    SLL->head = NULL;
}

void* singly_linked_list_head(SinglyLinkedList* SLL)
{
    if(!SLL->head) {
        return NULL;
    }
    return SLL->head->data;
}

void* singly_linked_list_tail(SinglyLinkedList* SLL)
{
    if(!SLL->tail) {
        return NULL;
    }
    return SLL->tail->data;
}

size_t singly_linked_list_size(SinglyLinkedList* SLL)
{
    return SLL->size;
}

static inline SinglyLinkedListNode* node_create(size_t data_size)
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

static inline void node_destroy(SinglyLinkedListNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
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

bool singly_linked_list_push_head(SinglyLinkedList* SLL, void* data)
{
    SinglyLinkedListNode* node = node_create(SLL->data_size);
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

bool singly_linked_list_push_tail(SinglyLinkedList* SLL, void* data)
{
    SinglyLinkedListNode* node = node_create(SLL->data_size);
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

bool singly_linked_list_insert(SinglyLinkedList* SLL, size_t index, void* data)
{
    if(!index) {
        singly_linked_list_push_head(SLL, data);
        return true;
    }
    if(index == SLL->size) {
        singly_linked_list_push_tail(SLL, data);
        return true;
    }
    if(index > SLL->size) {
        return false;
    }
    SinglyLinkedListNode* node = SLL->head;
    SinglyLinkedListNode* node_new = node_create(SLL->data_size);
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

bool singly_linked_list_sorted_insert(SinglyLinkedList* SLL, void* data)
{
    if(!SLL->size || SLL->compare(data, SLL->head->data) < 0) {
        singly_linked_list_push_head(SLL, data);
        return true;
    }
    if(SLL->compare(data, SLL->tail->data) > 0) {
        singly_linked_list_push_tail(SLL, data);
        return true;
    }
    SinglyLinkedListNode* node = SLL->head;
    SinglyLinkedListNode* node_new = node_create(SLL->data_size);
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

bool singly_linked_list_pop_head(SinglyLinkedList* SLL)
{
    if(!SLL->size) {
        return false;
    }
    SinglyLinkedListNode* node = SLL->head;
    SLL->head = SLL->head->next;
    if(!SLL->size) {
        SLL->tail = NULL;
    }
    node_destroy(node);
    SLL->size = SLL->size - 1;
    return true;
}

bool singly_linked_list_pop_tail(SinglyLinkedList* SLL)
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

bool singly_linked_list_erase(SinglyLinkedList* SLL, size_t index)
{
    if(!index) {
        singly_linked_list_pop_head(SLL);
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

// bool singly_linked_list_remove(SinglyLinkedList* SLL, void* data)
// {
//     SinglyLinkedListNode* node = SLL->head;
//     size_t count = 0;

//     while(node) {
//         count = count + 1;
//         if(node->data == data)
//             singly_linked_list_erase(SLL, count);
//     }

//     SLL->size = SLL->size - 1;

//     return true;
// }

bool singly_linked_list_linear(SinglyLinkedList* SLL)
{
    if(SLL->tail->next) {
        SLL->tail->next = NULL;
    }
    return true;
}

bool singly_linked_list_circular(SinglyLinkedList* SLL)
{
    if(!SLL->tail->next) {
        SLL->tail->next = SLL->head;
    }
    return true;
}
