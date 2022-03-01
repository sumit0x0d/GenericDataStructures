#ifndef DEQUE_LINKED_LIST_PRINT_H
#define DEQUE_LINKED_LIST_PRINT_H

#include "deque-linked_list.h"

#include <stdio.h>

void deque_print(struct Deque *deque)
{
    if(!deque->size) return;

    struct LinkedListNode *node = deque->front;

    printf("Deque: ");
    do {
        printf("%d ", *(int *)node->data);
        node = node->next;
    } while(node);

    printf("\b\nDeque Size: %zu\n", deque->size);
}

#endif
