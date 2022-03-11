#include "dynamic_array.h"

void push_front(struct DynamicArray *da, void *data);
void push_back(struct DynamicArray *da, void *data);
void insert(struct DynamicArray *da, size_t index, void *data);
void sorted_insert(struct DynamicArray *da, void *data);
void pop_front(struct DynamicArray *da);
void pop_back(struct DynamicArray *da);
void remove(struct DynamicArray *da, void *data);
void erase(struct DynamicArray *da, size_t index);

struct DynamicArray dynamic_array_construct(size_t element_size, double growth_factor)
{
    struct DynamicArray da;
    
    da.array = malloc(element_size);
    da.element_size = element_size;
    da.size = 0;
    da.capacity = 2;
    da.growth_factor = growth_factor;

    da.push_front = push_front;
    da.push_back = push_back;
    da.insert = insert;
    da.sorted_insert = sorted_insert;
    da.pop_front = pop_front;
    da.pop_back = pop_back;
    da.remove = remove;
    da.erase = erase;

    return da;
}

void distroy(struct DynamicArray *da)
{
    memset(da->array, 0, da->capacity);
    free(da->array);
    da->array = NULL;

    da->element_size = 0;
    da->size = 0;
    da->capacity = 0;
    da->growth_factor = 0;
}

// size_t *search(struct DynamicArray *da, int data)
// {
//     for(size_t i = 0; i < da->size; i++)
//         if(data == da->array[i])
//             return da->array[i];
//     return NULL;
// }

void push_front(struct DynamicArray *da, void *data)
{
    if(da->size == da->capacity) {
        da->capacity = da->capacity * da->growth_factor;
        da->array = realloc(da->array, da->element_size * da->capacity);
    }

    memmove((char *)da->array + da->element_size, da->array, da->element_size * da->size);

    memcpy(da->array, data, da->element_size);

    da->size = da->size + 1;
}

void push_back(struct DynamicArray *da, void *data)
{
    if(da->size == da->capacity) {
        da->capacity = da->capacity * da->growth_factor;
        da->array = realloc(da->array, da->element_size * da->capacity);
    }

    memcpy((char *)da->array + (da->element_size * da->size), data, da->element_size);

    da->size = da->size + 1;
}

// void insert(struct DynamicArray *da, size_t index, int data)
// {
//     if(da->size == da->capacity) {
//         da->capacity = da->capacity * da->growth_factor;
//         da->array = realloc(da->array, sizeof (int) * da->capacity);
//     }
    
//     for(size_t i = da->size; i > index; i--)
//         da->array[i] = da->array[i-1];
//     da->array[index] = data;
    
//     ++da->size;
// }

// void sorted_insert(struct DynamicArray *da, int data)
// {
    
// }

void pop_front(struct DynamicArray *da)
{
    memmove(da->array, (char *)da->array + da->element_size, (da->size - 1) * da->element_size);

    da->size = da->size - 1;
}

void pop_back(struct DynamicArray *da)
{
    da->size = da->size - 1;
}

// void erase(struct DynamicArray *da, size_t index)
// {
//     for(size_t i = index; i < da->size; i++)
//         da->array[i] = da->array[i+1];
    
//     da->size = da->size - 1;
// }
