#include "doubly_linked_list.h"

void linked_list_print(struct LinkedList *linked_list)
{
    if(!linked_list->size)
        return;
    struct LinkedListNode *node = linked_list->head;
    printf("Doubly Linked List: ");
    while(node != linked_list->tail) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("%d\n", linked_list->tail->data);
    printf("Doubly Linked List Size: %zu\n", linked_list->size);
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
    node->previous = NULL;
    node->data = data;
    node->next = linked_list->head;
    linked_list->head->previous = node;
    linked_list->head = node;
}

void linked_list_push_back(struct LinkedList *linked_list, int data)
{
    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    assert(node);
    node->data = data;
    node->next = NULL;
    if(linked_list->size) {
        node->previous = linked_list->tail;
        linked_list->tail->next = node;
        linked_list->tail = node;
    }
    else {
        node->previous = NULL;
        linked_list->head = node;
        linked_list->tail = node;
    }
    ++linked_list->size;
}

void linked_list_insert(struct LinkedList *linked_list, size_t index, int data)
{
    if(index > linked_list->size)
        return;
    struct LinkedListNode *node = head;
    struct LinkedListNode *node_new = malloc(sizeof(struct LinkedListNode));
    assert(node_new);
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

void linked_list_sorted_insert(struct LinkedList *linked_list, int data)
{

}

void linked_list_pop_front(struct LinkedList *linked_list)
{
    if(!linked_list->head)
        return;
    struct LinkedListNode *node = linked_list->head;
    linked_list->head = linked_list->head->next;
    if(linked_list->head)
        linked_list->head->previous = NULL;
    free(node);
}

void linked_list_pop_back(struct LinkedList *linked_list)
{
    if(!linked_list->head)
        return;
    if(!linked_list->head->next) {
        free(linked_list->head);
        return;
    }
    struct LinkedListNode *node = linked_list->tail;
    linked_list->tail = linked_list->tail->previous;
    linked_list->tail->next = NULL;
    free(node);
}

void linked_list_erase(struct LinkedList *linked_list, size_t index)
{
    if(index == 0 || index > linked_list->size)
        return;
    if(index == 1)
        linked_list_pop_front(head);
    struct LinkedListNode *node = linked_list->head;
    for(size_t i = 0; i < index-1; ++i) {
        node->previous = node;
        node = node->next;
    }
    node->previous->next = node->next;
    free(node);
}

void linked_list_remove(struct LinkedList *linked_list, int data)
{
    struct LinkedListNode *node = head;
    size_t count = 0;
    while(node) {
        count++;
        node = node->next;
    }
    if(node->data == data)
        linked_list_erase(head, count);
}
