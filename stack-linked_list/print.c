#include "stack.h"

#include <stdio.h>

void node_print(struct StackNode *node)
{
    switch(node->data_type_size) {
    case sizeof (char):
        printf("%c ", *(char *)node->data);
        break;
    case sizeof (int):
        if((int)*(float *)node->data == *(float *)node->data)
            printf("%d ", *(int *)node->data);
        else
            printf("%f ", *(float *)node->data);
        break;
    case sizeof (long):
        printf("%ld ", *(long *)node->data);
        break;
    default:
        printf("%s ", (char *)node->data);
        break;
    }
}

void stack_print(struct Stack *stack)
{
    if(!stack->size) return;

    struct StackNode *node = stack->top;

    printf("Stack: ");
    do {
        node_print(node);
        node = node->next;
    } while(node);

    printf("\b\nStack Size: %zu\n", stack->size);
}
