#include "deque.h"

void deque_print(Deque *D)
{
    printf("Deque: ");
    size_t i = D->front;
    while(i < D->back-1) {
        printf("%d ", D->array[i]);
        i++;
    }
    printf("%d\n", D->array[i]);
    printf("Deque Size: %zu\n", D->size);
    printf("deque Capacity: %zu\n", D->capacity);
}
