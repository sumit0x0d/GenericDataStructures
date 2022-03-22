#include "deque-linked_list.h"

#include <stdio.h>

void deque_print(DequeLinkedList *D)
{
    if(!D->size) return;

    DequeLinkedListNode *node = D->front;

    printf("Deque: ");
    do {
        printf("%d ", *(int *)node->data);
        node = node->next;
    } while(node);

    printf("\b\nDeque Size: %zu\n", D->size);
}
