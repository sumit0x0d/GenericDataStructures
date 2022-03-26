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

void queue_array_print(QueueArray *Q)
{
    if(!Q->array) return;

    printf("[Queue (Array)]");

    printf("\n[Data]\t: ");
    size_t i = Q->front;
    do {
        data_print(((char *)Q->array + (i * Q->element_size)), Q->element_type);
        i++;
    } while(i < Q->back);

    printf("\n[Size]\t: %zu\n", Q->size);
}


void stack_array_print(StackArray *S)
{
    if(!S->array) return;

    printf("[Stack (Array)]");

    printf("\n[Data]\t: ");
    size_t i = 0;
    while(i < S->top) {
        data_print(((char *)S->array + (i * S->element_size)), S->element_type);
        i++;
    }

    printf("\n[Size]\t: %zu\n", S->size);
}
