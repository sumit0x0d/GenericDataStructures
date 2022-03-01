#ifndef STACK_PRINT_H
#define STACK_PRINT_H

#include "stack-linked_list.h"

#include <stdio.h>

void stack_print(struct Stack *stack)
{
    if(!stack->size) return;

    struct LinkedListNode *node = stack->top;

    printf("Stack: ");
    do {
        printf("%d ", *(int *)node->data);
        node = node->next;
    } while(node);

    printf("\b\nStack Size: %zu\n", stack->size);
}

#endif
