#include "deque-array/deque-array.h"
#include "dynamic_array/dynamic_array.h"
#include "queue-array/queue-array.h"
#include "stack-array/stack-array.h"

#include "data-print.h"

enum {
    DEQUE_ARRAY,
    DYNAMIC_ARRAY,
    QUEUE_ARRAY,
    STACK_ARRAY,
};



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
