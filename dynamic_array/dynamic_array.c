#include "dynamic_array.h"

void push_front(struct DynamicArray *dynamic_array, void *data);
void push_back(struct DynamicArray *dynamic_array, void *data);
void insert(struct DynamicArray *dynamic_array, size_t index, void *data);
void sorted_insert(struct DynamicArray *dynamic_array, void *data);
void pop_front(struct DynamicArray *dynamic_array);
void pop_back(struct DynamicArray *dynamic_array);
void remove(struct DynamicArray *dynamic_array, void *data);
void erase(struct DynamicArray *dynamic_array, size_t index);

struct DynamicArray dynamic_array_construct(size_t element_size, size_t capacity, double growth_factor)
{
    struct DynamicArray dynamic_array;
    
    dynamic_array.array = malloc(element_size * capacity);
    dynamic_array.element_size = element_size;
    dynamic_array.size = 0;
    dynamic_array.capacity = capacity;
    dynamic_array.growth_factor = growth_factor;

    dynamic_array.push_front = push_front;
    dynamic_array.push_back = push_back;
    // dynamic_array.insert = insert;
    // dynamic_array.sorted_insert = sorted_insert;
    // dynamic_array.pop_front = pop_front;
    // dynamic_array.pop_back = pop_back;
    // dynamic_array.remove = remove;
    // dynamic_array.erase = erase;
    
    return dynamic_array;
}

void distroy(struct DynamicArray *dynamic_array)
{
    memset(dynamic_array->array, 0, dynamic_array->capacity);
    free(dynamic_array->array);
    dynamic_array->array = NULL;

    dynamic_array->element_size = 0;
    dynamic_array->size = 0;
    dynamic_array->capacity = 0;
    dynamic_array->growth_factor = 0;
}

// size_t *search(struct DynamicArray *dynamic_array, int data)
// {
//     for(size_t i = 0; i < dynamic_array->size; i++)
//         if(data == dynamic_array->array[i])
//             return dynamic_array->array[i];
//     return NULL;
// }

void push_front(struct DynamicArray *dynamic_array, void *data)
{
    if(dynamic_array->size == dynamic_array->capacity) {
        dynamic_array->capacity = dynamic_array->capacity * dynamic_array->growth_factor;
        dynamic_array->array = realloc(dynamic_array->array, dynamic_array->element_size * dynamic_array->capacity);
    }

    memmove((char *)dynamic_array->array + dynamic_array->element_size, dynamic_array->array, dynamic_array->size * dynamic_array->element_size);

    memcpy(dynamic_array->array, data, dynamic_array->element_size);

    ++dynamic_array->size;
}

void push_back(struct DynamicArray *dynamic_array, void *data)
{
    if(dynamic_array->size == dynamic_array->capacity) {
        dynamic_array->capacity = dynamic_array->capacity * dynamic_array->growth_factor;
        dynamic_array->array = realloc(dynamic_array->array, dynamic_array->element_size * dynamic_array->capacity);
    }

    memcpy((char *)dynamic_array->array + (dynamic_array->size * dynamic_array->element_size), data, dynamic_array->element_size);

    ++dynamic_array->size;
}

// void insert(struct DynamicArray *dynamic_array, size_t index, int data)
// {
//     if(dynamic_array->size == dynamic_array->capacity) {
//         dynamic_array->capacity = dynamic_array->capacity * dynamic_array->growth_factor;
//         dynamic_array->array = realloc(dynamic_array->array, sizeof (int) * dynamic_array->capacity);
//     }
    
//     for(size_t i = dynamic_array->size; i > index; i--)
//         dynamic_array->array[i] = dynamic_array->array[i-1];
//     dynamic_array->array[index] = data;
    
//     ++dynamic_array->size;
// }

// void sorted_insert(struct DynamicArray *dynamic_array, int data)
// {
    
// }

// void pop_front(struct DynamicArray *dynamic_array)
// {
//     for(size_t i = 0; i < dynamic_array->size; i++)
//         dynamic_array->array[i] = dynamic_array->array[i+1];
    
//     --dynamic_array->size;
// }

// void pop_back(struct DynamicArray *dynamic_array)
// {
//     --dynamic_array->size;
// }

// void erase(struct DynamicArray *dynamic_array, size_t index)
// {
//     for(size_t i = index; i < dynamic_array->size; i++)
//         dynamic_array->array[i] = dynamic_array->array[i+1];
    
//     --dynamic_array->size;
// }
