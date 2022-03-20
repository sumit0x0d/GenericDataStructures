#include "dynamic_array.h"

bool dynamic_array_push_front(DynamicArray *DA, void *data);
bool dynamic_array_push_back(DynamicArray *DA, void *data);
bool dynamic_array_insert(DynamicArray *DA, size_t index, void *data);
bool dynamic_array_sorted_insert(DynamicArray *DA, void *data);
bool dynamic_array_pop_front(DynamicArray *DA);
bool dynamic_array_pop_back(DynamicArray *DA);
bool dynamic_array_remove(DynamicArray *DA, void *data);
bool dynamic_array_erase(DynamicArray *DA, size_t index);

DynamicArray dynamic_array_construct(size_t element_size, size_t capacity, double growth_factor)
{
    if((size_t)(capacity * growth_factor) <= capacity) {
        capacity = 2;
        growth_factor = 1.5;
    }

    DynamicArray DA;

    DA.array = NULL;
    DA.element_size = element_size;
    DA.size = 0;
    DA.capacity = capacity;
    DA.growth_factor = growth_factor;

    return DA;
}

void dynamic_array_destruct(DynamicArray *DA)
{
    free(DA->array);
    DA->array = NULL;

    DA->size = 0;
    DA->capacity = 2;
}

// size_t *search(DynamicArray *DA. int data)
// {
//     for(size_t i = 0; i < DA->size; i++)
//         if(data == DA->array[i])
//             return DA->array[i];
//     return NULL;
// }

void array_construct(void *array, size_t element_size, size_t size, size_t *capacity, double growth_factor)
{
    if(!array) {
        array = malloc(element_size * (*capacity));
        if(!array) return;
    }

    if(size == (*capacity)) {
        (*capacity) = (*capacity) * growth_factor;
        array = realloc(array, element_size * (*capacity));
    }
}

bool dynamic_array_push_front(DynamicArray *DA, void *data)
{
    if(!DA->array) {
        DA->array = malloc(DA->element_size * DA->capacity);
        if(!DA->array) return false;
    }

    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void *array = realloc(DA->array, DA->element_size * DA->capacity);
        if(!array) return false;
        
        DA->array = array;
    }

    memmove((char *)DA->array + DA->element_size, DA->array, DA->element_size * DA->size);

    memcpy(DA->array, data, DA->element_size);

    DA->size = DA->size + 1;

    return true;
}

bool dynamic_array_push_back(DynamicArray *DA, void *data)
{
    if(!DA->array) {
        DA->array = malloc(DA->element_size * DA->capacity);
        if(!DA->array) return false;
    }

    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void *array = realloc(DA->array, DA->element_size * DA->capacity);
        if(!array) return false;
        
        DA->array = array;
    }

    // array_construct(DA->array, DA->element_size, DA->size, &DA->capacity, DA->growth_factor);

    memcpy((char *)DA->array + (DA->element_size * DA->size), data, DA->element_size);

    DA->size = DA->size + 1;

    return true;
}

bool dynamic_array_insert(DynamicArray *DA, size_t index, void *data)
{
    if(index > DA->size) return false;

    if(!DA->array) {
        DA->array = malloc(DA->element_size * DA->capacity);
        if(!DA->array) return false;
    }

    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void *array = realloc(DA->array, DA->element_size * DA->capacity);
        if(!array) return false;

        DA->array = array;
    }

    memmove((char *)DA->array + (DA->element_size * index) + DA->element_size, (char *)DA->array + (DA->element_size * index), DA->element_size * DA->size);

    memcpy((char *)DA->array + (DA->element_size * index), data, DA->element_size);

    DA->size = DA->size + 1;

    return true;
}

// void dynamic_array_sorted_insert(DynamicArray *DA. int data)
// {
    
// }

// void dynamic_array_pop_front(DynamicArray *da)
// {
//     memmove(DA->array, (char *)DA->array + DA->element_size, (DA->size - 1) * DA->element_size);

//     DA->size = DA->size - 1;
// }

// void dynamic_array_pop_back(DynamicArray *da)
// {
//     DA->size = DA->size - 1;
// }

// void dynamic_array_erase(DynamicArray *DA. size_t index)
// {
//     for(size_t i = index; i < DA->size; i++)
//         DA->array[i] = DA->array[i+1];
    
//     DA->size = DA->size - 1;
// }
