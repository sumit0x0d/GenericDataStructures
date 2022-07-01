#include "DynamicArray.h"

DynamicArray* DynamicArray_create(size_t data_size, size_t capacity, double growth_factor,
    int (*compare)(void* data1, void* data2))
{
    if((size_t)(capacity * growth_factor) <= capacity) {
        return NULL;
    }
    DynamicArray* DA = (DynamicArray*)malloc(sizeof (DynamicArray));
    if(!DA) {
        return NULL;
    }
    DA->array = malloc(data_size * capacity);
    if(!DA->array) {
        free(DA);
        DA = NULL;
        return NULL;
    }
    DA->data_size = data_size;
    DA->capacity = capacity;
    DA->growth_factor = growth_factor;
    DA->compare = compare;
    DA->size = 0;
    return DA;
}

void DynamicArray_destroy(DynamicArray* DA)
{
    free(DA->array);
    DA->array = NULL;
    DA->size = 0;
    free(DA);
    DA = NULL;
}

static bool DynamicArray_change_capacity(DynamicArray* DA, size_t capacity)
{
    void* array = realloc(DA->array, DA->data_size * DA->capacity);
    if(!array) {
        return false;
    }
    DA->array = array;
    DA->capacity = capacity;
    return true;
}

static inline void* data_at(DynamicArray* DA, size_t index)
{
    return (char*)DA->array + (DA->data_size * index);
}

void* DynamicArray_front(DynamicArray* DA)
{
    return data_at(DA, 0);
}

void* DynamicArray_back(DynamicArray* DA)
{
    return data_at(DA, DA->size - 1);
}

void* DynamicArray_at(DynamicArray* DA, size_t index)
{
    return data_at(DA, index);
}

void* DynamicArray_search(DynamicArray* DA, void* data)
{
    size_t left = 0;
    size_t right = DA->size;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare = DA->compare(data, data_at(DA, middle));
        if(!compare) {
            return data_at(DA, middle);
        }
        else if(compare < 0) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return NULL;
}

bool DynamicArray_push_front(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity) {
        if(!DynamicArray_change_capacity(DA, DA->capacity * DA->growth_factor)) {
            return false;
        }
    }
    memmove(data_at(DA, 1), data_at(DA, 0), DA->data_size * (DA->size - 1));
    memcpy(data_at(DA, 0), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool DynamicArray_push_back(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity) {
        if(!DynamicArray_change_capacity(DA, DA->capacity * DA->growth_factor)) {
            return false;
        }
    }
    memcpy(data_at(DA, DA->size), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool DynamicArray_insert(DynamicArray* DA, size_t index, void* data)
{
    if(DA->size == DA->capacity) {
        if(!DynamicArray_change_capacity(DA, DA->capacity * DA->growth_factor)) {
            return false;
        }
    }
    memmove(data_at(DA, index + 1), data_at(DA, index), DA->data_size * (DA->size - index - 1));
    memcpy(data_at(DA, index), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool DynamicArray_sorted_insert(DynamicArray* DA, void* data)
{
    if(!DA->size) {
        memcpy(data_at(DA, 0), data, DA->data_size);
        DA->size = DA->size + 1;
        return true;
    }
    if(DA->size == DA->capacity) {
        if(!DynamicArray_change_capacity(DA, DA->capacity * DA->growth_factor)) {
            return false;
        }
    }
    if(DA->compare(data, data_at(DA, 0)) < 0) {
        memmove(data_at(DA, 1), data_at(DA, 0), DA->data_size * DA->size);
        memcpy(data_at(DA, 0), data, DA->data_size);
        DA->size = DA->size + 1;
        return true;
    }
    if(DA->compare(data, data_at(DA, DA->size - 1)) > 0) {
        memcpy(data_at(DA, DA->size), data, DA->data_size);
        DA->size = DA->size + 1;
        return true;
    }
    size_t left = 0;
    size_t right = DA->size - 1;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare = DA->compare(data, data_at(DA, middle));
        if(!compare) {
            memmove(data_at(DA, middle + 2), data_at(DA, middle + 1),
                DA->data_size * (DA->size - middle - 1));
            memcpy(data_at(DA, middle + 1), data, DA->data_size);
            DA->size = DA->size + 1;
            return true;
        }
        else if(compare < 0) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }   
    }
    memmove(data_at(DA, left + 1), data_at(DA, left), DA->data_size * (DA->size - left + 1));
    memcpy(data_at(DA, left), data, DA->data_size);
    DA->size = DA->size + 1;
    return true;
}

bool DynamicArray_pop_front(DynamicArray* DA)
{
    if(DA->size == DA->capacity / DA->growth_factor) {
        if(!DynamicArray_change_capacity(DA, DA->capacity / DA->growth_factor)) {
            return false;
        }
    }
    memmove(data_at(DA, 0), data_at(DA, 1), DA->data_size * (DA->size - 1));
    DA->size = DA->size - 1;
    return true;
}

bool DynamicArray_pop_back(DynamicArray* DA)
{
    if(DA->size == DA->capacity / DA->growth_factor) {
        if(!DynamicArray_change_capacity(DA, DA->capacity / DA->growth_factor)) {
            return false;
        }
    }
    DA->size = DA->size - 1;
    return true;
}

bool DynamicArray_remove(DynamicArray* DA, void* data)
{
    if(DA->size == DA->capacity / DA->growth_factor) {
        if(!DynamicArray_change_capacity(DA, DA->capacity / DA->growth_factor)) {
            return false;
        }
    }
    size_t left = 0;
    size_t right = DA->size;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare = DA->compare(data, data_at(DA, middle));
        if(!compare) {
            memmove(data_at(DA, middle), data_at(DA, middle + 1),
                DA->data_size * (DA->size - middle + 1));
            DA->size = DA->size - 1;
            break;
        }
        else if(compare < 0) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return true;
}

bool DynamicArray_erase(DynamicArray* DA, size_t index)
{
    if(DA->size == DA->capacity / DA->growth_factor) {
        if(!DynamicArray_change_capacity(DA, DA->capacity / DA->growth_factor)) {
            return false;
        }
    }
    memmove(data_at(DA, index), data_at(DA, index + 1), DA->data_size * (DA->size - index + 1));
    DA->size = DA->size - 1;
    return true;
}
