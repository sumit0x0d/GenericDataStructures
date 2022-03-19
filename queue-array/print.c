#include "queue.h"

#include <stdio.h>

void queue_print(struct Queue *Q)
{
    // printf("Queue Array: ");
    size_t i = Q->front;
    while(i < Q->back) {
        printf("%d ", *(int *)((char *)Q->array + (4*i)));
        i++;
    }
    // printf("%d\n", Q->array[i]);
    // printf("Queue Array Size: %zu\n", Q->size);
    // printf("Queue Array Capacity: %zu\n", Q->capacity);
}
