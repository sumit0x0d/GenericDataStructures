#include "dynamic_array.h"

void dynamic_array_print(struct DynamicArray *dynamic_array)
{
    printf("Dynamic Array: ");
    size_t i = 0;
    while(i < dynamic_array->size-1) {
        printf("%d ", dynamic_array->array[i]);
        i++;
    }
    printf("%d\n", dynamic_array->array[dynamic_array->size]);
    printf("Dynamic Array Size: %zu\n", dynamic_array->size);
    printf("Dynamic Array Capacity: %zu\n", dynamic_array->capacity);
    printf("Dynamic Array Growth Factor: %lf\n", dynamic_array->growth_factor);
}

struct DynamicArray *dynamic_array_construct(size_t capacity, double growth_factor)
{
    struct DynamicArray *dynamic_array = malloc(sizeof(struct DynamicArray));
    
    dynamic_array->array = malloc(sizeof(int) * capacity);
    dynamic_array->size = 0;
    dynamic_array->capacity = capacity;
    dynamic_array->growth_factor = growth_factor;
    
    return dynamic_array;
}

void dynamic_array_distroy(struct DynamicArray *dynamic_array)
{
    free(dynamic_array->array);
    free(dynamic_array);
}

// size_t *dynamic_array_search(struct DynamicArray *dynamic_array, int data)
// {
//     for(size_t i = 0; i < dynamic_array->size; i++)
//         if(data == dynamic_array->array[i])
//             return dynamic_array->array[i];
//     return NULL;
// }

void dynamic_array_push_front(struct DynamicArray *dynamic_array, int data)
{
    if(dynamic_array->size == dynamic_array->capacity) {
        dynamic_array->capacity = dynamic_array->capacity * dynamic_array->growth_factor;
        dynamic_array->array = realloc(dynamic_array->array, sizeof (int) * dynamic_array->capacity);
    }
    
    for(size_t i = dynamic_array->size; i > 0; i--)
        dynamic_array->array[i] = dynamic_array->array[i-1];
    dynamic_array->array[0] = data;
    
    ++dynamic_array->size;
}

void dynamic_array_push_back(struct DynamicArray *dynamic_array, int data)
{
    if(dynamic_array->size == dynamic_array->capacity) {
        dynamic_array->capacity = dynamic_array->capacity * dynamic_array->growth_factor;
        dynamic_array->array = realloc(dynamic_array->array, sizeof (int) * dynamic_array->capacity);
    }
    dynamic_array->array[dynamic_array->size] = data;
    ++dynamic_array->size;
}

void dynamic_array_insert(struct DynamicArray *dynamic_array, size_t index, int data)
{
    if(dynamic_array->size == dynamic_array->capacity) {
        dynamic_array->capacity = dynamic_array->capacity * dynamic_array->growth_factor;
        dynamic_array->array = realloc(dynamic_array->array, sizeof (int) * dynamic_array->capacity);
    }
    
    for(size_t i = dynamic_array->size; i > index; i--)
        dynamic_array->array[i] = dynamic_array->array[i-1];
    dynamic_array->array[index] = data;
    
    ++dynamic_array->size;
}

void dynamic_array_sorted_insert(struct DynamicArray *dynamic_array, int data)
{
    
}

void dynamic_array_pop_front(struct DynamicArray *dynamic_array)
{
    for(size_t i = 0; i < dynamic_array->size; i++)
        dynamic_array->array[i] = dynamic_array->array[i+1];
    
    --dynamic_array->size;
}

void dynamic_array_pop_back(struct DynamicArray *dynamic_array)
{
    --dynamic_array->size;
}

void dynamic_array_erase(struct DynamicArray *dynamic_array, size_t index)
{
    for(size_t i = index; i < dynamic_array->size; i++)
        dynamic_array->array[i] = dynamic_array->array[i+1];
    
    --dynamic_array->size;
}
