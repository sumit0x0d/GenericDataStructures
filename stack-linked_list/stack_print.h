#ifndef QUEUE_PRINT_H
#define QUEUE_PRINT_H

#include "stack-linked_list.h"

void stack_print(struct Stack *stack)
{
    if(!stack->size) return;

    struct LinkedListNode *node = stack->top;

    printf("Stack: ");
    do {
        if(node->data_type_size == sizeof (char))
            printf("%c ", *(char *)node->data);
        // else if(node->size == sizeof (int))
        //     printf("%d ", *(int *)node->data);
        else if(node->data_type_size == sizeof (float))
            printf("%i ", *(int *)node->data);
        node = node->next;
    } while(node);
    
    printf("\b\nStack Size: %zu\n", stack->size);
}
#endif
