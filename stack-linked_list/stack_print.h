#ifndef STACK_PRINT_H
#define STACK_PRINT_H

#include "stack-linked_list.h"

#include <stdio.h>

void node_print(struct LinkedListNode *node)
{
    switch(node->data_type_size) {
    case sizeof (char):
        printf("%c ", *(char *)node->data);
        break;
    case sizeof (int):
        if((int)*(float *)node->data == 0.0)
            printf("%d ", *(int *)node->data);
        else
            printf("%f ", *(float *)node->data);
        break;
    case sizeof (long):
        printf("%ld ", *(long *)node->data);
        break;
    default:
        break;
    }
}

void stack_print(struct Stack *stack)
{
    if(!stack->size) return;

    struct LinkedListNode *node = stack->top;

    printf("Stack: ");
    do {
        node_print(node);
        node = node->next;
    } while(node);

    printf("\b\nStack Size: %zu\n", stack->size);
}

#endif
