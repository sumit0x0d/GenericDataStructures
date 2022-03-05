#include "dynamic_array.h"

#include <stdio.h>

void dynamic_array_print(struct DynamicArray *dynamic_array)
{
    printf("Dynamic Array: ");
    // size_t i = 0;
    // while(i < dynamic_array->size) {
        printf("%c ", *(char *)(dynamic_array->array));
        printf("%c ", *(char *)(dynamic_array->array+1));
        printf("%d ", *(int *)(dynamic_array->array+2));
        printf("%d ", *(int *)(dynamic_array->array+3));
        // i++;
    // }
    // printf("%d\n", dynamic_array->array[dynamic_array->size]);
    printf("Dynamic Array Size: %zu\n", dynamic_array->size);
    printf("Dynamic Array Capacity: %zu\n", dynamic_array->capacity);
    printf("Dynamic Array Growth Factor: %lf\n", dynamic_array->growth_factor);
}