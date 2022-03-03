#ifndef QUEUE_PRINT_H
#define QUEUE_PRINT_H

#include "singly_linked_list.h"

#include <stdio.h>

void singly_linked_list_print(struct SinglyLinkedList *linked_list)
{
    if(!linked_list->size) return;

    struct SinglyLinkedListNode *node = linked_list->head;

    printf("Linked List: ");
    do {
        printf("%d ", *(int *)node->data);
        node = node->next;
    } while(node);

    printf("\b\nLinked List Size: %zu\n", linked_list->size);
}

#endif
