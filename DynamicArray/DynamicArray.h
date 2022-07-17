#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct DynamicArray DynamicArray;

DynamicArray* DynamicArrayCreate(size_t data_size, size_t capacity, double growth_factor,
    int (*compare_function)(void* data1, void* data2));
void DynamicArrayDestroy(DynamicArray* DA);
size_t DynamicArraySize(DynamicArray* DA);
bool DynamicArrayEmpty(DynamicArray* DA);
void* DynamicArrayFront(DynamicArray* DA);
void* DynamicArrayBack(DynamicArray* DA);
void* DynamicArrayAt(DynamicArray* DA, size_t index);
void* DynamicArraySearch(DynamicArray* DA, void* data);
bool DynamicArrayPushFront(DynamicArray* DA, void* data);
bool DynamicArrayPushBack(DynamicArray* DA, void* data);
bool DynamicArrayInsert(DynamicArray* DA, size_t index, void* data);
bool DynamicArraySortedInsert(DynamicArray* DA, void* data);
bool DynamicArrayPopFront(DynamicArray* DA);
bool DynamicArrayPopBack(DynamicArray* DA);
bool DynamicArrayRemove(DynamicArray* DA, void* data);
bool DynamicArrayErase(DynamicArray* DA, size_t index);

#endif
