#include "stack-linked_list.h"

void stack_print(StackLinkedList *S)
{
    printf("Stack: ");
    size_t i = 0;
    while(i < S->top-1) {
        printf("%d ", S->array[i]);
        i++;
    }
    printf("%d\n", S->array[S->top]);
    printf("Stack Size: %zu\n", S->size);
    printf("Stack Capacity: %zu\n", S->capacity);
}
