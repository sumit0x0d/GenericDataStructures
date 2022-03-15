#include "dynamic_array.h"

void push_front(struct DynamicArray *DA, void *data);
void push_back(struct DynamicArray *DA, void *data);
void insert(struct DynamicArray *DA, size_t index, void *data);
void sorted_insert(struct DynamicArray *DA, void *data);
void pop_front(struct DynamicArray *DA);
void pop_back(struct DynamicArray *DA);
void remove(struct DynamicArray *DA, void *data);
void erase(struct DynamicArray *DA, size_t index);

struct DynamicArray dynamic_array_construct(size_t element_size, size_t capacity, double growth_factor)
{
    if((size_t)(capacity * growth_factor) <= capacity) {
        capacity = 2;
        growth_factor = 1.5;
    }

    struct DynamicArray DA;

    DA.array = NULL;
    DA.element_size = element_size;
    DA.size = 0;
    DA.capacity = capacity;
    DA.growth_factor = growth_factor;

    // DA.push_front = push_front;
    DA.push_back = push_back;
    // DA.insert = insert;
    // DA.sorted_insert = sorted_insert;
    // DA.pop_front = pop_front;
    // DA.pop_back = pop_back;
    // DA.remove = remove;
    // DA.erase = erase;

    return DA;
}

void dynamic_array_distroy(struct DynamicArray *DA)
{
    free(DA->array);
    DA->array = NULL;

    DA->size = 0;
    DA->capacity = 2;
}

// size_t *search(struct DynamicArray *DA. int data)
// {
//     for(size_t i = 0; i < DA->size; i++)
//         if(data == DA->array[i])
//             return DA->array[i];
//     return NULL;
// }

void array_construct(void **array, size_t element_size, size_t size, size_t *capacity, double growth_factor)
{
    if(!array) {
        array = malloc(element_size);
        if(!array) return;
    }

    if(size == (*capacity)) {
        (*capacity) = (*capacity) * growth_factor;
        array = realloc(array, element_size * (*capacity));
    }
}

void push_front(struct DynamicArray *DA, void *data)
{
    if(!DA->array) {
        DA->array = malloc(DA->element_size);
        if(!DA->array) return;
    }

    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        DA->array = realloc(DA->array, DA->element_size * DA->capacity);
    }

    memmove((char *)DA->array + DA->element_size, *DA->array, DA->element_size * DA->size);

    memcpy(DA->array, data, DA->element_size);

    DA->size = DA->size + 1;
}

void push_back(struct DynamicArray *DA, void *data)
{
    if(!DA->array) {
        DA->array = malloc(DA->element_size);
        if(!DA->array) return;
    }

    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        DA->array = realloc(DA->array, DA->element_size * DA->capacity);
    }

    memcpy((char *)DA->array + (DA->element_size * DA->size), data, DA->element_size);

    DA->size = DA->size + 1;
}

// void insert(struct DynamicArray *DA. size_t index, int data)
// {
//     if(DA->size == DA->capacity) {
//         DA->capacity = DA->capacity * DA->growth_factor;
//         DA->array = realloc(DA->array, sizeof (int) * DA->capacity);
//     }
    
//     for(size_t i = DA->size; i > index; i--)
//         DA->array[i] = DA->array[i-1];
//     DA->array[index] = data;
    
//     ++DA->size;
// }

// void sorted_insert(struct DynamicArray *DA. int data)
// {
    
// }

// void pop_front(struct DynamicArray *da)
// {
//     memmove(DA->array, (char *)DA->array + DA->element_size, (DA->size - 1) * DA->element_size);

//     DA->size = DA->size - 1;
// }

// void pop_back(struct DynamicArray *da)
// {
//     DA->size = DA->size - 1;
// }

// void erase(struct DynamicArray *DA. size_t index)
// {
//     for(size_t i = index; i < DA->size; i++)
//         DA->array[i] = DA->array[i+1];
    
//     DA->size = DA->size - 1;
// }
