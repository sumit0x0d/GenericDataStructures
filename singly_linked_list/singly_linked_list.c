#include "singly_linked_list.h"

void push_front(struct SinglyLinkedList *linked_list, void *data, size_t data_type_size);
void push_back(struct SinglyLinkedList *linked_list, void *data, size_t data_type_size);
void insert(struct SinglyLinkedList *linked_list, size_t index, void *data, size_t data_type_size);
void sorted_insert(struct SinglyLinkedList *linked_list, void *data, size_t data_type_size);
void pop_front(struct SinglyLinkedList *linked_list);
void pop_back(struct SinglyLinkedList *linked_list);
void remove(struct SinglyLinkedList *linked_list, void *data, size_t data_type_size);
void erase(struct SinglyLinkedList *linked_list, size_t index);
void linear(struct SinglyLinkedList *linked_list);
void circular(struct SinglyLinkedList *linked_list);

struct SinglyLinkedList singly_linked_list_construct()
{
    struct SinglyLinkedList linked_list;

    linked_list.head = NULL;
    linked_list.tail = NULL;

    linked_list.size = 0;

    linked_list.push_front = push_front;
    linked_list.push_back = push_back;
    linked_list.insert = insert;
    linked_list.sorted_insert = sorted_insert;
    linked_list.pop_front = pop_front;
    linked_list.pop_back = pop_back;
    linked_list.remove = remove;
    linked_list.erase = erase;
    linked_list.linear = linear;
    linked_list.circular = circular;

    return linked_list;
}

struct SinglyLinkedListNode *search(struct SinglyLinkedList *linked_list, int data)
{
    if(!linked_list->size)
        return NULL;
    struct SinglyLinkedListNode *node = malloc(sizeof(struct SinglyLinkedListNode));
    while(node) {
        if(data == node->data)
            return node;
        node = node->next;
    }
    return NULL;
}

struct SinglyLinkedListNode *node_construct(void *data, size_t data_type_size)
{
    struct SinglyLinkedListNode *node = malloc(sizeof(struct SinglyLinkedListNode));
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

void push_front(struct SinglyLinkedList *linked_list, void *data, size_t data_type_size)
{
    struct SinglyLinkedListNode *node = node_construct(data, data_type_size);

    if(linked_list->size)
        node->next = linked_list->head;
    else {
        node->next = NULL;
        linked_list->tail = node;
    }
    linked_list->head = node;

    ++linked_list->size;
}

void push_back(struct SinglyLinkedList *linked_list, void *data, size_t data_type_size)
{
    struct SinglyLinkedListNode *node = node_construct(data, data_type_size);
    
    node->next = NULL;
    if(linked_list->size) {
        linked_list->tail->next = node;
        linked_list->tail = node;
    }
    else {
        linked_list->head = node;
        linked_list->tail = node;
    }
    
    ++linked_list->size;
}

void insert(struct SinglyLinkedList *linked_list, size_t index, void *data, size_t data_type_size)
{
    if(!index) {
        push_front(linked_list, data, data_type_size);
        return;
    }
    if(index > linked_list->size)
        return;

    struct SinglyLinkedListNode *node = linked_list->head;
    struct SinglyLinkedListNode *node_new = node_construct(data, data_type_size);

    for(size_t i = 0; i < index-1; i++)
        node = node->next;
    node_new->next = node->next;
    node->next = node_new;

    ++linked_list->size;
}

void sorted_insert(struct SinglyLinkedList *linked_list, void *data, size_t data_type_size)
{
    if(!linked_list->size || data <= linked_list->head->data) {
        push_front(linked_list, data, data_type_size);
        return;
    }
    if(data >= linked_list->tail->data) {
        push_back(linked_list, data, data_type_size);
        return;
    }

    struct SinglyLinkedListNode *node = linked_list->head;
    struct SinglyLinkedListNode *node_new = node_construct(data, data_type_size);

    while(node && data > node->next->data) {
        node = node->next;
    }
    node_new->next = node->next;
    node->next = node_new;
    
    ++linked_list->size;
}

void node_distruct(struct SinglyLinkedListNode *node)
{
    memset(node->data, 0, node->data_type_size);
    free(node->data);
    node->data = NULL;

    memset(node, 0, sizeof(struct SinglyLinkedListNode));
    free(node);
    node = NULL;
}

void pop_front(struct SinglyLinkedList *linked_list)
{
    if(!linked_list->size) return;

    struct SinglyLinkedListNode *node = linked_list->head;

    linked_list->head = linked_list->head->next;
    
    if(!linked_list->size)
        linked_list->tail = NULL;

    node_distruct(node);

    --linked_list->size;
}

void pop_back(struct SinglyLinkedList *linked_list)
{
    if(!linked_list->size) return;

    if(linked_list->head == linked_list->tail) {
        free(linked_list->head);
        return;
    }

    struct SinglyLinkedListNode *node = linked_list->head;

    while(node->next != linked_list->tail)
        node = node->next;
    node->next = NULL;
    free(linked_list->tail);
    linked_list->tail = node;

    --linked_list->size;
}

void erase(struct SinglyLinkedList *linked_list, size_t index)
{
    if(!index) {
        pop_front(linked_list);
        return;
    }
    if(index > linked_list->size)
        return;

    struct SinglyLinkedListNode *node = linked_list->head;
    struct SinglyLinkedListNode *node_previous = NULL;

    for(size_t i = 0; i < index-1; i++) {
        node_previous = node;
        node = node->next;
    }
    node_previous->next = node->next;
    free(node);

    --linked_list->size;
}

void remove(struct SinglyLinkedList *linked_list, void *data, size_t data_type_size)
{
    struct SinglyLinkedListNode *node = linked_list->head;
    size_t count = 0;
    while(node) {
        count++;
        if(node->data == data)
            erase(linked_list, count);
    }
    linked_list->size--;
}

void linear(struct SinglyLinkedList *linked_list)
{
    if(linked_list->tail->next)
        linked_list->tail->next = NULL;
}

void circular(struct SinglyLinkedList *linked_list)
{
    if(!linked_list->tail->next)
        linked_list->tail->next = linked_list->head;
}
