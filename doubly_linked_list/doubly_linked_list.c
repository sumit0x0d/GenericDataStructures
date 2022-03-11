#include "doubly_linked_list.h"

struct DoublyLinkedList doubly_linked_list_construct()
{
    struct DoublyLinkedList linked_list;

    linked_list.head = NULL;
    linked_list.tail = NULL;
    linked_list.size = 0;

    return linked_list;
}

struct DoublyLinkedListNode *search(struct DoublyLinkedList *dll, int data)
{
    if(!dll->size) return NULL;

    struct DoublyLinkedListNode *node = malloc(sizeof (struct DoublyLinkedListNode));
    while(node) {
        if(data == node->data)
            return node;
        node = node->next;
    }
    
    return NULL;
}

void push_front(struct DoublyLinkedList *dll, int data)
{
    struct DoublyLinkedListNode *node = malloc(sizeof (struct DoublyLinkedListNode));
    if(!node) return;
    node->previous = NULL;
    node->data = data;
    node->next = dll->head;
    dll->head->previous = node;
    dll->head = node;
}

void push_back(struct DoublyLinkedList *dll, int data)
{
    struct DoublyLinkedListNode *node = malloc(sizeof (struct DoublyLinkedListNode));
    assert(node);
    node->data = data;
    node->next = NULL;
    if(dll->size) {
        node->previous = dll->tail;
        dll->tail->next = node;
        dll->tail = node;
    }
    else {
        node->previous = NULL;
        dll->head = node;
        dll->tail = node;
    }
    dll->size = dll->size + 1;
}

void insert(struct DoublyLinkedList *dll, size_t index, int data)
{
    if(index > dll->size)
        return;
    struct DoublyLinkedListNode *node = head;
    struct DoublyLinkedListNode *node_new = malloc(sizeof (struct DoublyLinkedListNode));
    node_new->data = data;
    if(index==0) {
        node_new->previous = NULL;
        node_new->next = head;
        head->previous = node_new;
        head = node_new;
    }
    else {
        for(size_t i = 0; i < index-1; ++i)
            node = node->next;
        node_new->previous = node;
        node_new->next = node->next;
        if(node->next)
            node->next->previous = node_new;
        node->next = node_new;
    }
}

void sorted_insert(struct DoublyLinkedList *dll, int data)
{

}

void pop_front(struct DoublyLinkedList *dll)
{
    if(!dll->head)
        return;
    struct DoublyLinkedListNode *node = dll->head;
    dll->head = dll->head->next;
    if(dll->head)
        dll->head->previous = NULL;
    free(node);
}

void pop_back(struct DoublyLinkedList *dll)
{
    if(!dll->head)
        return;
    if(!dll->head->next) {
        free(dll->head);
        return;
    }
    struct DoublyLinkedListNode *node = dll->tail;
    dll->tail = dll->tail->previous;
    dll->tail->next = NULL;
    free(node);
}

void erase(struct DoublyLinkedList *dll, size_t index)
{
    if(index == 0 || index > dll->size)
        return;
    if(index == 1)
        pop_front(head);
    struct DoublyLinkedListNode *node = dll->head;
    for(size_t i = 0; i < index-1; ++i) {
        node->previous = node;
        node = node->next;
    }
    node->previous->next = node->next;
    free(node);
}

void remove(struct DoublyLinkedList *dll, int data)
{
    struct DoublyLinkedListNode *node = head;
    size_t count = 0;
    while(node) {
        count++;
        node = node->next;
    }
    if(node->data == data)
        erase(head, count);
}
