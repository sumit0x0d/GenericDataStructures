#include "singly_linked_list.h"

#include <stdio.h>

void singly_linked_list_print(struct SinglyLinkedList *sll)
{
    if(!sll->size) return;

    struct SinglyLinkedListNode *node = sll->head;

    printf("Linked List: ");
    do {
        printf("%d ", *(int *)node->data);
        node = node->next;
    } while(node);

    printf("\b\nLinked List Size: %zu\n", sll->size);
}
