#include "stack-linked_list.h"

#include <stdio.h>

void node_print(StackLinkedListNode *node)
{
    // switch(data_type_size) {
    // case sizeof (char):
    //     printf("%c ", *(char *)node->data);
    //     break;
    // case sizeof (int):
        if((int)*(float *)node->data == *(int *)node->data)
            printf("%d ", *(int *)node->data);
        else
            printf("%f ", *(float *)node->data);
    //     break;
    // case sizeof (long):
    //     printf("%ld ", *(long *)node->data);
    //     break;
    // default:
    //     printf("%s ", (char *)node->data);
    //     break;
    // }
}

void stack_linked_list_print(StackLinkedList *stack)
{
    if(!stack->size) return;

    StackLinkedListNode *node = stack->top;

    printf("StackLinkedList: ");
    do {
        node_print(node);
        node = node->next;
    } while(node);

    printf("\b\nStackLinkedList Size: %zu\n", stack->size);
}
