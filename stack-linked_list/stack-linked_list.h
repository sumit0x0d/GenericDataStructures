#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackLinkedListNode {
    void *data;
    size_t data_type_size;
    struct StackLinkedListNode *next;
} StackLinkedListNode;

typedef struct StackLinkedList {
    StackLinkedListNode *top;
    size_t size;
} StackLinkedList;

StackLinkedList stack_linked_list_construct();
void stack_linked_list_destruct(StackLinkedList *S);

StackLinkedListNode *stack_linked_list_peek(StackLinkedList *S);
size_t stack_linked_list_size(StackLinkedList *S);

bool stack_linked_list_push(StackLinkedList *S, void *data, size_t data_type_size);
bool stack_linked_list_pop(StackLinkedList *S);

#endif
