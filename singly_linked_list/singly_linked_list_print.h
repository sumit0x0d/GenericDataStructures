#ifndef QUEUE_PRINT_H
#define QUEUE_PRINT_H

#include "singly_linked_list.h"

#include <stdio.h>

void print(struct LinkedList *linked_list)
{
    if(!linked_list->size)
        return;
    struct LinkedListNode *node = linked_list->head;
    printf("Singly Linked List: ");
    while(node != linked_list->tail) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("%d\n", linked_list->tail->data);
    printf("Singly Linked List Size: %zu\n", linked_list->size);
}

#endif
