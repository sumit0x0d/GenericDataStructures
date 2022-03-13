#include "deque.h"

#include <stdio.h>

void deque_print(struct Deque *deque)
{
    if(!deque->size) return;

    struct DequeNode *node = deque->front;

    printf("Deque: ");
    do {
        printf("%d ", *(int *)node->data);
        node = node->next;
    } while(node);

    printf("\b\nDeque Size: %zu\n", deque->size);
}
