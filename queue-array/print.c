#include "queue.h"

#include <stdio.h>

void queue_print(struct Queue *queue)
{
    printf("Queue Array: ");
    size_t i = queue->front;
    while(i < queue->back-1) {
        printf("%d ", queue->array[i]);
        i++;
    }
    printf("%d\n", queue->array[i]);
    printf("Queue Array Size: %zu\n", queue->size);
    printf("Queue Array Capacity: %zu\n", queue->capacity);
}
