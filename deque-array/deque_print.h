#ifndef DEQUE_ARRAY_PRINT_H
#define DEQUE_ARRAY_PRINT_H

#include "deque-array.h"

void deque_print(struct Deque *deque)
{
    printf("Deque: ");
    size_t i = deque->front;
    while(i < deque->back-1) {
        printf("%d ", deque->array[i]);
        i++;
    }
    printf("%d\n", deque->array[i]);
    printf("Deque Size: %zu\n", deque->size);
    printf("deque Capacity: %zu\n", deque->capacity);
}

#endif
