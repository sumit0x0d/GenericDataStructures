#include "doubly_linked_list.h"

#include <stdio.h>

void doubly_linked_list_print(struct DoublyLinkedList *dll)
{
    if(!linked_list->size) return;

    struct DoublyLinkedListNode *node = linked_list->head;
    printf("Doubly Linked List: ");
    do {
        printf("%d ", node->data);
        node = node->next;
    } while(node);
    printf("\b\nDoubly Linked List Size: %zu\n", linked_list->size);
}
