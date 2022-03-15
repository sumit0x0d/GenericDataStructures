#include "singly_linked_list.h"

void push_front(struct SinglyLinkedList *SLL, void *data);
void push_back(struct SinglyLinkedList *SLL, void *data);
void insert(struct SinglyLinkedList *SLL, size_t index, void *data);
void sorted_insert(struct SinglyLinkedList *SLL, void *data);
void pop_front(struct SinglyLinkedList *SLL);
void pop_back(struct SinglyLinkedList *SLL);
void remove(struct SinglyLinkedList *SLL, void *data, size_t data_type_size);
void erase(struct SinglyLinkedList *SLL, size_t index);
void linear(struct SinglyLinkedList *SLL);
void circular(struct SinglyLinkedList *SLL);

struct SinglyLinkedList singly_linked_list_construct(size_t data_type_size)
{
    struct SinglyLinkedList SLL;

    SLL.head = NULL;
    SLL.tail = NULL;
    SLL.data_type_size = data_type_size;
    SLL.size = 0;

    SLL.push_front = push_front;
    SLL.push_back = push_back;
    SLL.insert = insert;
    SLL.sorted_insert = sorted_insert;
    SLL.pop_front = pop_front;
    SLL.pop_back = pop_back;
    SLL.remove = remove;
    SLL.erase = erase;
    SLL.linear = linear;
    SLL.circular = circular;

    return SLL;
}

struct SinglyLinkedListNode *search(struct SinglyLinkedList *SLL, int data)
{
    if(!SLL->size) return NULL;
    struct SinglyLinkedListNode *node = malloc(sizeof (struct SinglyLinkedListNode));
    while(node) {
        if(data == node->data)
            return node;
        node = node->next;
    }
    return NULL;
}

struct SinglyLinkedListNode *node_construct(size_t data_type_size)
{
    struct SinglyLinkedListNode *node = malloc(sizeof (struct SinglyLinkedListNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    return node;
}

void push_front(struct SinglyLinkedList *SLL, void *data)
{
    struct SinglyLinkedListNode *node = node_construct(SLL->data_type_size);
    if(!node) return;

    memcpy(node->data, data, SLL->data_type_size);

    if(SLL->size)
        node->next = SLL->head;
    else {
        node->next = NULL;
        SLL->tail = node;
    }
    SLL->head = node;

    SLL->size = SLL->size + 1;
}

void push_back(struct SinglyLinkedList *SLL, void *data)
{
    struct SinglyLinkedListNode *node = node_construct(SLL->data_type_size);
    if(!node) return;
    
    memcpy(node->data, data, SLL->data_type_size);

    node->next = NULL;
    if(SLL->size) {
        SLL->tail->next = node;
        SLL->tail = node;
    }
    else {
        SLL->head = node;
        SLL->tail = node;
    }
    
    SLL->size = SLL->size + 1;
}

void insert(struct SinglyLinkedList *SLL, size_t index, void *data)
{
    if(!index) {
        push_front(SLL, data);
        return;
    }
    if(index > SLL->size)
        return;

    struct SinglyLinkedListNode *node = SLL->head;
    struct SinglyLinkedListNode *node_new = node_construct(SLL->data_type_size);
    if(!node_new) return;

    memcpy(node_new->data, data, SLL->data_type_size);

    for(size_t i = 0; i < index-1; i++)
        node = node->next;
    node_new->next = node->next;
    node->next = node_new;

    SLL->size = SLL->size + 1;
}

void sorted_insert(struct SinglyLinkedList *SLL, void *data)
{
    if(!SLL->size || memcmp(data, SLL->head->data, SLL->data_type_size) < 0) {
        push_front(SLL, data);
        return;
    }

    if(memcmp(data, SLL->tail->data, SLL->data_type_size) > 0) {
        push_back(SLL, data);
        return;
    }

    struct SinglyLinkedListNode *node = SLL->head;
    struct SinglyLinkedListNode *node_new = node_construct(SLL->data_type_size);
    if(!node_new) return;

    memcpy(node_new->data, data, SLL->data_type_size);

    while(node && data > node->next->data) {
        node = node->next;
    }
    node_new->next = node->next;
    node->next = node_new;
    
    SLL->size = SLL->size + 1;
}

void node_destruct(struct SinglyLinkedListNode *node, size_t data_type_size)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

void pop_front(struct SinglyLinkedList *SLL)
{
    if(!SLL->size) return;

    struct SinglyLinkedListNode *node = SLL->head;

    SLL->head = SLL->head->next;
    
    if(!SLL->size)
        SLL->tail = NULL;

    node_destruct(node, SLL->data_type_size);

    SLL->size = SLL->size - 1;
}

void pop_back(struct SinglyLinkedList *SLL)
{
    if(!SLL->size) return;

    if(SLL->head == SLL->tail) {
        free(SLL->head);
        return;
    }

    struct SinglyLinkedListNode *node = SLL->head;

    while(node->next != SLL->tail)
        node = node->next;
    node->next = NULL;
    free(SLL->tail);
    SLL->tail = node;

    SLL->size = SLL->size - 1;
}

void erase(struct SinglyLinkedList *SLL, size_t index)
{
    if(!index) {
        pop_front(SLL);
        return;
    }
    if(index > SLL->size)
        return;

    struct SinglyLinkedListNode *node = SLL->head;
    struct SinglyLinkedListNode *node_previous;

    for(size_t i = 0; i < index-1; i++) {
        node_previous = node;
        node = node->next;
    }
    node_previous->next = node->next;
    free(node);

    SLL->size = SLL->size - 1;
}

void remove(struct SinglyLinkedList *SLL, void *data, size_t data_type_size)
{
    struct SinglyLinkedListNode *node = SLL->head;
    size_t count = 0;
    while(node) {
        count++;
        if(node->data == data)
            erase(SLL, count);
    }
    
    SLL->size = SLL->size - 1;
}

void linear(struct SinglyLinkedList *SLL)
{
    if(SLL->tail->next)
        SLL->tail->next = NULL;
}

void circular(struct SinglyLinkedList *SLL)
{
    if(!SLL->tail->next)
        SLL->tail->next = SLL->head;
}
