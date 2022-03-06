#include "dynamic_array.h"

#include <stdio.h>

void dynamic_array_print(struct DynamicArray *da)
{
    printf("Dynamic Array: ");
    // size_t i = 0;
    // while(i < da->size) {
        for(int i = 0; i < 10; i++)
        printf("%d ", *(int *)((char *)da->array+(4*i)));
        // printf("%d ", *(int *)((char *)da->array+4));
        // i++;
    // }
    // printf("%d\n", da->array[da->size]);
    printf("Dynamic Array Size: %zu\n", da->size);
    printf("Dynamic Array Capacity: %zu\n", da->capacity);
    printf("Dynamic Array Growth Factor: %lf\n", da->growth_factor);
}
