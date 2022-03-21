#include "deque.h"

#include <stdio.h>

void deque_print(Deque *D)
{
    if(!D->size) return;

    DequeNode *node = D->front;

    printf("Deque: ");
    do {
        printf("%d ", *(int *)node->data);
        node = node->next;
    } while(node);

    printf("\b\nDeque Size: %zu\n", D->size);
}
