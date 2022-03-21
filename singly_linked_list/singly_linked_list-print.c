#include "singly_linked_list.h"

#include <stdio.h>

void singly_linked_list_print(SinglyLinkedList *SLL)
{
    if(!SLL->size) return;

    SinglyLinkedListNode *node = SLL->head;

    printf("Linked List: ");
    do {
        printf("%d ", *(int *)node->data);
        node = node->next;
    } while(node);

    printf("\b\nLinked List Size: %zu\n", SLL->size);
}
