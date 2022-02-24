#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H


#include <stdio.h>
#include <stdlib.h>

struct LinkedListNode {
    struct LinkedListNode *previous;
    int data;
    struct LinkedListNode *next;
};

struct LinkedList {
    struct LinkedListNode *head;
    struct LinkedListNode *tail;   
    size_t size;
};

void linked_list_print(struct LinkedList *linked_list);
struct LinkedList *linked_list_construct();
void linked_list_distroy(struct LinkedList *linked_list);
struct LinkedListNode *linked_list_search(struct LinkedList *linked_list, int data);
void linked_list_push_front(struct LinkedList *linked_list, int data);
void linked_list_push_back(struct LinkedList *linked_list, int data);
void linked_list_insert(struct LinkedList *linked_list, size_t index, int data);
void linked_list_sorted_insert(struct LinkedList *linked_list, int data);
void linked_list_pop_front(struct LinkedList *linked_listlinked_list);
void linked_list_pop_back(struct LinkedList *linked_list);
void linked_list_remove(struct LinkedList *linked_list, int data);
void linked_list_erase(struct LinkedList *linked_list, size_t index);
void linked_list_linear(struct LinkedList *linked_list);
void linked_list_circular(struct LinkedList *linked_list);

#endif
