#ifndef DOUBLY_LINKED_LIST_PRINT_H
#define DOUBLY_LINKED_LIST_PRINT_H

#include "doubly_linked_list.h"

#include <stdio.h>

void linked_list_print(struct LinkedList *linked_list)
{
    if(!linked_list->size) return;

    struct LinkedListNode *node = linked_list->head;
    printf("Doubly Linked List: ");
    do {
        printf("%d ", node->data);
        node = node->next;
    } while(node);
    printf("\b\nDoubly Linked List Size: %zu\n", linked_list->size);
}

#endif
