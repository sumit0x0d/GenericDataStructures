#include "singly_linked_list.h"

void push_front(struct SinglyLinkedList *sll, void *data, size_t data_type_size);
void push_back(struct SinglyLinkedList *sll, void *data, size_t data_type_size);
void insert(struct SinglyLinkedList *sll, size_t index, void *data, size_t data_type_size);
void sorted_insert(struct SinglyLinkedList *sll, void *data, size_t data_type_size);
void pop_front(struct SinglyLinkedList *sll);
void pop_back(struct SinglyLinkedList *sll);
void remove(struct SinglyLinkedList *sll, void *data, size_t data_type_size);
void erase(struct SinglyLinkedList *sll, size_t index);
void linear(struct SinglyLinkedList *sll);
void circular(struct SinglyLinkedList *sll);

struct SinglyLinkedList singly_linked_list_construct()
{
    struct SinglyLinkedList sll;

    sll.head = NULL;
    sll.tail = NULL;

    sll.size = 0;

    sll.push_front = push_front;
    sll.push_back = push_back;
    sll.insert = insert;
    sll.sorted_insert = sorted_insert;
    sll.pop_front = pop_front;
    sll.pop_back = pop_back;
    sll.remove = remove;
    sll.erase = erase;
    sll.linear = linear;
    sll.circular = circular;

    return sll;
}

struct SinglyLinkedListNode *search(struct SinglyLinkedList *sll, int data)
{
    if(!sll->size)
        return NULL;
    struct SinglyLinkedListNode *node = malloc(sizeof (struct SinglyLinkedListNode));
    while(node) {
        if(data == node->data)
            return node;
        node = node->next;
    }
    return NULL;
}

struct SinglyLinkedListNode *node_construct(void *data, size_t data_type_size)
{
    struct SinglyLinkedListNode *node = malloc(sizeof (struct SinglyLinkedListNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    memcpy(node->data, data, data_type_size);

    node->data_type_size = data_type_size;

    return node;
}

void push_front(struct SinglyLinkedList *sll, void *data, size_t data_type_size)
{
    struct SinglyLinkedListNode *node = node_construct(data, data_type_size);

    if(sll->size)
        node->next = sll->head;
    else {
        node->next = NULL;
        sll->tail = node;
    }
    sll->head = node;

    sll->size = sll->size + 1;
}

void push_back(struct SinglyLinkedList *sll, void *data, size_t data_type_size)
{
    struct SinglyLinkedListNode *node = node_construct(data, data_type_size);
    
    node->next = NULL;
    if(sll->size) {
        sll->tail->next = node;
        sll->tail = node;
    }
    else {
        sll->head = node;
        sll->tail = node;
    }
    
    sll->size = sll->size + 1;
}

void insert(struct SinglyLinkedList *sll, size_t index, void *data, size_t data_type_size)
{
    if(!index) {
        push_front(sll, data, data_type_size);
        return;
    }
    if(index > sll->size)
        return;

    struct SinglyLinkedListNode *node = sll->head;
    struct SinglyLinkedListNode *node_new = node_construct(data, data_type_size);

    for(size_t i = 0; i < index-1; i++)
        node = node->next;
    node_new->next = node->next;
    node->next = node_new;

    sll->size = sll->size + 1;
}

void sorted_insert(struct SinglyLinkedList *sll, void *data, size_t data_type_size)
{
    if(!sll->size || data <= sll->head->data) {
        push_front(sll, data, data_type_size);
        return;
    }
    if(data >= sll->tail->data) {
        push_back(sll, data, data_type_size);
        return;
    }

    struct SinglyLinkedListNode *node = sll->head;
    struct SinglyLinkedListNode *node_new = node_construct(data, data_type_size);

    while(node && data > node->next->data) {
        node = node->next;
    }
    node_new->next = node->next;
    node->next = node_new;
    
    sll->size = sll->size + 1;
}

void node_destruct(struct SinglyLinkedListNode *node)
{
    memset(node->data, 0, node->data_type_size);
    free(node->data);
    node->data = NULL;

    memset(node, 0, sizeof (struct SinglyLinkedListNode));
    free(node);
    node = NULL;
}

void pop_front(struct SinglyLinkedList *sll)
{
    if(!sll->size) return;

    struct SinglyLinkedListNode *node = sll->head;

    sll->head = sll->head->next;
    
    if(!sll->size)
        sll->tail = NULL;

    node_destruct(node);

    sll->size = sll->size - 1;
}

void pop_back(struct SinglyLinkedList *sll)
{
    if(!sll->size) return;

    if(sll->head == sll->tail) {
        free(sll->head);
        return;
    }

    struct SinglyLinkedListNode *node = sll->head;

    while(node->next != sll->tail)
        node = node->next;
    node->next = NULL;
    free(sll->tail);
    sll->tail = node;

    sll->size = sll->size - 1;
}

void erase(struct SinglyLinkedList *sll, size_t index)
{
    if(!index) {
        pop_front(sll);
        return;
    }
    if(index > sll->size)
        return;

    struct SinglyLinkedListNode *node = sll->head;
    struct SinglyLinkedListNode *node_previous = NULL;

    for(size_t i = 0; i < index-1; i++) {
        node_previous = node;
        node = node->next;
    }
    node_previous->next = node->next;
    free(node);

    sll->size = sll->size - 1;
}

void remove(struct SinglyLinkedList *sll, void *data, size_t data_type_size)
{
    struct SinglyLinkedListNode *node = sll->head;
    size_t count = 0;
    while(node) {
        count++;
        if(node->data == data)
            erase(sll, count);
    }
    
    sll->size = sll->size - 1;
}

void linear(struct SinglyLinkedList *sll)
{
    if(sll->tail->next)
        sll->tail->next = NULL;
}

void circular(struct SinglyLinkedList *sll)
{
    if(!sll->tail->next)
        sll->tail->next = sll->head;
}
