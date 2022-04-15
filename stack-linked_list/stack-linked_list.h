#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackLinkedListNode StackLinkedListNode;
typedef struct StackLinkedList StackLinkedList;

StackLinkedList* stack_linked_list_create(size_t data_size);
void stack_linked_list_destroy(StackLinkedList* S);

void* stack_linked_list_peek(StackLinkedList* S);
size_t stack_linked_list_size(StackLinkedList* S);

bool stack_linked_list_push(StackLinkedList* S, void* data);
bool stack_linked_list_pop(StackLinkedList* S);

#endif
