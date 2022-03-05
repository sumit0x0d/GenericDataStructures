#include "stack.h"

#include <stdio.h>

void node_print(struct LinkedListNode *node)
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
        // for(size_t i = 0; i < node->data_type_size; i++) {
            printf("%s ", (char *)node->data);
        // }
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
