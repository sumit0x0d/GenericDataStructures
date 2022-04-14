#include "dynamic_array.h"

typedef struct DynamicArray {
    void *array;
    size_t data_size;
    size_t capacity;
    double growth_factor;
    int (*compare)(void *data, void *node_data);
    size_t size;
} DynamicArray;

DynamicArray *dynamic_array_create(size_t data_size, size_t capacity, double growth_factor,
    int (*compare)(void *data, void *node_data));
void dynamic_array_destroy(DynamicArray *DA);

void *dynamic_array_front(DynamicArray *DA);
void *dynamic_array_back(DynamicArray *DA);
size_t dynamic_array_size(DynamicArray *DA);

bool dynamic_array_push_front(DynamicArray *DA, void *data);
bool dynamic_array_push_back(DynamicArray *DA, void *data);
bool dynamic_array_insert(DynamicArray *DA, size_t index, void *data);
bool dynamic_array_sorted_insert(DynamicArray *DA, void *data);
bool dynamic_array_pop_front(DynamicArray *DA);
bool dynamic_array_pop_back(DynamicArray *DA);
bool dynamic_array_remove(DynamicArray *DA, void *data);
bool dynamic_array_erase(DynamicArray *DA, size_t index);

DynamicArray *dynamic_array_create(size_t data_size, size_t capacity, double growth_factor,
    int (*compare)(void *data, void *node_data))
{
    if((size_t)(capacity * growth_factor) <= capacity) {
        return NULL;
    }
    DynamicArray *DA = malloc(sizeof (DynamicArray));
    if(!DA) {
        return NULL;
    }
    DA->array = malloc(data_size * capacity);
    if(!DA->array) {
        return NULL;
    }
    DA->data_size = data_size;
    DA->capacity = capacity;
    DA->growth_factor = growth_factor;
    DA->compare = compare;
    DA->size = 0;
    return DA;
}

void dynamic_array_destroy(DynamicArray *DA)
{
    free(DA->array);
    DA->array = NULL;
    DA->size = 0;
    free(DA);
    DA = NULL;
}

void *dynamic_array_front(DynamicArray *DA)
{
    if(!DA->array) {
        return false;
    }
    return DA->array;
}

void *dynamic_array_back(DynamicArray *DA)
{
    if(!DA->array) {
        return false;
    }
    return (char *)DA->array + (DA->data_size * DA->size);
}

size_t dynamic_array_size(DynamicArray *DA)
{
    return DA->size;
}

// size_t dynamic_array_search(DynamicArray *DA, void *data)
// {

// }

bool dynamic_array_push_front(DynamicArray *DA, void *data)
{
    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void *array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return false;
        }
        DA->array = array;
    }
    memmove((char *)DA->array + DA->data_size, DA->array, DA->data_size * DA->size);
    memcpy(DA->array, data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool dynamic_array_push_back(DynamicArray *DA, void *data)
{
    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void *array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return false;
        }
        DA->array = array;
    }
    memcpy((char *)DA->array + (DA->data_size * DA->size), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool dynamic_array_insert(DynamicArray *DA, size_t index, void *data)
{
    if(index > DA->size) {
        return false;
    }
    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void *array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return false;
        }
        DA->array = array;
    }
    memmove((char *)DA->array + (DA->data_size * index) + DA->data_size, (char *)DA->array + (DA->data_size * index), DA->data_size * DA->size);
    memcpy((char *)DA->array + (DA->data_size * index), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool dynamic_array_sorted_insert(DynamicArray *DA, void *data)
{
    if(DA->size == DA->capacity) {
        DA->capacity = DA->capacity * DA->growth_factor;
        void *array = realloc(DA->array, DA->data_size * DA->capacity);
        if(!array) {
            return false;
        }
        DA->array = array;
    }
    for(size_t i = 0; i < DA->size; i++) {
        int compare = DA->compare(data, (char *)DA->array + i);
        if(compare <= 0) {
            memmove((char *)DA->array + (DA->data_size * (i + 1)), (char *)DA->array + (DA->data_size * i), DA->data_size * (DA->size - i - 1));
            memcpy((char *)DA->array + (DA->data_size * i), data, DA->data_size);
            DA->size = DA->size + 1;
            return true;
        }
    }
    memcpy((char *)DA->array + (DA->data_size * DA->size), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool dynamic_array_pop_front(DynamicArray *DA)
{
    if(!DA->size) {
        return false;
    }
    memmove(DA->array, (char *)DA->array + DA->data_size, (DA->size - 1) * DA->data_size);
    DA->size = DA->size - 1;
    return true;
}

bool dynamic_array_pop_back(DynamicArray *DA)
{
    if(!DA->size) {
        return false;
    }
    DA->size = DA->size - 1;
    return true;
}

bool dynamic_array_erase(DynamicArray *DA, size_t index)
{
    if(!DA->size) {
        return false;
    }
    if(index >= DA->data_size) {
        return false;
    }
    memmove((char *)DA->array + (DA->data_size * index), (char *)DA->array + (DA->data_size * (index + 1)), DA->data_size * (DA->size - index + 1));
    DA->size = DA->size - 1;
    return true;
}

bool dynamic_array_remove(DynamicArray *DA, void *data)
{
    if(!DA->size) {
        return false;
    }
    for(size_t i = 0; i < DA->size; i++) {
        if(!DA->compare(data, (char *)DA->array + i)) {
            memmove((char *)DA->array + (DA->data_size * i), (char *)DA->array + (DA->data_size * (i + 1)), DA->data_size * (DA->size - i + 1));
            DA->size = DA->size - 1;
            return true;
        }
    }
    return false;
}
