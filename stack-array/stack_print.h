#ifndef QUEUE_PRINT_H
#define QUEUE_PRINT_H

#include "queue-array.h"

void stack_print(struct Stack *stack)
{
    printf("Stack: ");
    size_t i = 0;
    while(i < stack->top-1) {
        printf("%d ", stack->array[i]);
        i++;
    }
    printf("%d\n", stack->array[stack->top]);
    printf("Stack Size: %zu\n", stack->size);
    printf("Stack Capacity: %zu\n", stack->capacity);
}

#endif
