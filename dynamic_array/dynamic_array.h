#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DynamicArray {
    void* array;
    size_t data_size;
    size_t capacity;
    double growth_factor;
    size_t size;
    int (*compare)(void* data, void* node_data);
} DynamicArray;

DynamicArray* DynamicArray_create(size_t data_size, size_t capacity, double growth_factor,
    int (*compare)(void* data, void* node_data));
void DynamicArray_destroy(DynamicArray* DA);

bool DynamicArray_push_front(DynamicArray* DA, void* data);
bool DynamicArray_push_back(DynamicArray* DA, void* data);
bool DynamicArray_insert(DynamicArray* DA, size_t index, void* data);
bool DynamicArray_sorted_insert(DynamicArray* DA, void* data);
bool DynamicArray_pop_front(DynamicArray* DA);
bool DynamicArray_pop_back(DynamicArray* DA);
bool DynamicArray_remove(DynamicArray* DA, void* data);
bool DynamicArray_erase(DynamicArray* DA, size_t index);

size_t DynamicArray_search(DynamicArray* DA, void* data);
void* DynamicArray_at(DynamicArray* DA, size_t index);

#endif
