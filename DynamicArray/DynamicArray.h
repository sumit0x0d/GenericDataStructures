#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <string.h>

typedef struct DynamicArray {
    void* array;
    size_t data_size;
    size_t front;
    size_t back;
    size_t capacity;
    double growth_factor;
    size_t size;
    int (*compare)(void* data1, void* data2);
} DynamicArray;

DynamicArray* DynamicArray_create(size_t data_size, size_t capacity, double growth_factor,
    int (*compare)(void* data1, void* data2));
void DynamicArray_destroy(DynamicArray* DA);

int DynamicArray_push_front(DynamicArray* DA, void* data);
int DynamicArray_push_back(DynamicArray* DA, void* data);
int DynamicArray_insert(DynamicArray* DA, size_t index, void* data);
int DynamicArray_sorted_insert(DynamicArray* DA, void* data);
int DynamicArray_pop_front(DynamicArray* DA);
int DynamicArray_pop_back(DynamicArray* DA);
int DynamicArray_remove(DynamicArray* DA, void* data);
int DynamicArray_erase(DynamicArray* DA, size_t index);

size_t DynamicArray_search(DynamicArray* DA, void* data);
void* DynamicArray_at(DynamicArray* DA, size_t index);
void* DynamicArray_front(DynamicArray* DA);
void* DynamicArray_back(DynamicArray* DA);

#endif
