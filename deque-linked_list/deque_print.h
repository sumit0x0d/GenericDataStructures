#ifndef DEQUE_LINKED_LIST_PRINT_H
#define DEQUE_LINKED_LIST_PRINT_H

#include "deque-linked_list.h"

#include <stdio.h>

void deque_print(struct Deque *deque)
{
   if(!deque->size)
        return;
    struct LinkedListNode *node = deque->front;
    printf("Queue: ");
    while(node != deque->back) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("%d\n", deque->back->data);
    printf("Queue Size: %zu\n", deque->size);
}
#endif
