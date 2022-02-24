#ifndef HELPERS_H
#define HELPERS_H


#include <stdio.h>
#include <stdlib.h>

struct LinkedListNode {
    int data;
    struct LinkedListNode *next;
};

struct LinkedList {
    struct LinkedListNode *head;
    struct LinkedListNode *tail;  
    size_t size;
};

void linked_list_print(struct LinkedList *linked_list)
{
    if(!linked_list->size)
        return;
    struct LinkedListNode *node = linked_list->head;
    printf("Linked List: ");
    while(node != linked_list->tail) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("%d\n", linked_list->tail->data);
    printf("Linked List Size: %zu\n", linked_list->size);
}

struct LinkedList *linked_list_construct()
{
    struct LinkedList *linked_list = malloc(sizeof(struct LinkedList));
    assert(linked_list);
    linked_list->head = NULL;
    linked_list->tail = NULL;
    linked_list->size = 0;
    return linked_list;
}

struct LinkedListNode *linked_list_search(struct LinkedList *linked_list, int data)
{
    if(!linked_list->size)
        return NULL;
    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    while(node) {
        if(data == node->data)
            return node;
        node = node->next;
    }
    return NULL;
}

void linked_list_push_front(struct LinkedList *linked_list, int data)
{
    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    assert(node);
    node->data = data;
    if(linked_list->size)
        node->next = linked_list->head;
    else {
        node->next = NULL;
        linked_list->tail = node;
    }
    linked_list->head = node;
    linked_list->size++;
}

void linked_list_push_back(struct LinkedList *linked_list, int data)
{    
    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    assert(node);
    node->data = data;
    node->next = NULL;
    if(linked_list->size) {
        linked_list->tail->next = node;
        linked_list->tail = node;
    }
    else {
        linked_list->head = node;
        linked_list->tail = node;
    }
    linked_list->size++;
}

void linked_list_sorted_insert(struct LinkedList *linked_list, int data)
{
    if(!linked_list->size || data <= linked_list->head->data) {
        linked_list_push_front(linked_list, data);
        return;
    }
    if(data >= linked_list->tail->data) {
        linked_list_push_back(linked_list, data);
        return;
    }
    struct LinkedListNode *node = linked_list->head;
    struct LinkedListNode *node_new = malloc(sizeof(struct LinkedListNode));
    assert(node_new);
    node_new->data = data;
    while(node && data > node->next->data)
        node = node->next;
    node_new->next = node->next;
    node->next = node_new;
    linked_list->size++;
}

void linked_list_remove(struct LinkedList *linked_list, int data)
{

}

#endif
