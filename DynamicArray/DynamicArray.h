#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct DynamicArray DynamicArray;

DynamicArray* DynamicArray_create(size_t data_size, size_t capacity, double growth_factor,
    int (*compare)(void* data1, void* data2));
void DynamicArray_destroy(DynamicArray* DA);
size_t DynamicArray_size(DynamicArray* DA);
bool DynamicArray_empty(DynamicArray* DA);
void* DynamicArray_front(DynamicArray* DA);
void* DynamicArray_back(DynamicArray* DA);
void* DynamicArray_at(DynamicArray* DA, size_t index);
void* DynamicArray_search(DynamicArray* DA, void* data);
bool DynamicArray_push_front(DynamicArray* DA, void* data);
bool DynamicArray_push_back(DynamicArray* DA, void* data);
bool DynamicArray_insert(DynamicArray* DA, size_t index, void* data);
bool DynamicArray_sorted_insert(DynamicArray* DA, void* data);
bool DynamicArray_pop_front(DynamicArray* DA);
bool DynamicArray_pop_back(DynamicArray* DA);
bool DynamicArray_remove(DynamicArray* DA, void* data);
bool DynamicArray_erase(DynamicArray* DA, size_t index);

#endif
