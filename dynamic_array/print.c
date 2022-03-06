#include "dynamic_array.h"

#include <stdio.h>

void dynamic_array_print(struct DynamicArray *da)
{
    printf("Dynamic Array: ");
    // size_t i = 0;
    // while(i < da->size) {
        printf("%c ", *(char *)(da->array));
        printf("%c ", *(char *)(da->array+1));
        printf("%d ", *(int *)(da->array+2));
        printf("%d ", *(int *)(da->array+3));
        // i++;
    // }
    // printf("%d\n", da->array[da->size]);
    printf("Dynamic Array Size: %zu\n", da->size);
    printf("Dynamic Array Capacity: %zu\n", da->capacity);
    printf("Dynamic Array Growth Factor: %lf\n", da->growth_factor);
}