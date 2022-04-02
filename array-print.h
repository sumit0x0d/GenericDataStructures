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

void queue_array_print(QueueArray *Q, int data_type, size_t data_size)
{
    if(!Q->array) return;

    printf("[Queue (Array)]");

    printf("\n[Data]\t: ");
    for(size_t i = Q->front; i < Q->back; i++)
        data_print(((char *)Q->array + (i * data_size)), data_type);

    printf("\n[Size]\t: %zu\n", Q->size);
}

void stack_array_print(StackArray *S, int data_type, size_t data_size)
{
    if(!S->array) return;

    printf("[Stack (Array)]");

    printf("\n[Data]\t: ");
    for(size_t i = 0; i < S->top; i++)
        data_print(((char *)S->array + (i * data_size)), data_type);

    printf("\n[Size]\t: %zu\n", S->size);
}
