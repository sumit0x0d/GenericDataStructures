#include "deque.h"

#include <stdio.h>

void deque_print(struct Deque *D)
{
    if(!D->size) return;

    struct DequeNode *node = D->front;

    printf("Deque: ");
    do {
        printf("%d ", *(int *)node->data);
        node = node->next;
    } while(node);

    printf("\b\nDeque Size: %zu\n", D->size);
}
