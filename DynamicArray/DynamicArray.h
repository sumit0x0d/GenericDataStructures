#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct DynamicArray DynamicArray;

DynamicArray* DynamicArray_Create(size_t data_size, size_t capacity, double growth_factor,
    int (*compare)(void* data1, void* data2));
void DynamicArray_Destroy(DynamicArray* DA);
size_t DynamicArray_Size(DynamicArray* DA);
bool DynamicArray_Empty(DynamicArray* DA);
void* DynamicArrayFront(DynamicArray* DA);
void* DynamicArrayBack(DynamicArray* DA);
void* DynamicArray_At(DynamicArray* DA, size_t index);
void* DynamicArray_Search(DynamicArray* DA, void* data);
bool DynamicArray_PushFront(DynamicArray* DA, void* data);
bool DynamicArray_PushBack(DynamicArray* DA, void* data);
bool DynamicArray_Insert(DynamicArray* DA, size_t index, void* data);
bool DynamicArray_SortedInsert(DynamicArray* DA, void* data);
bool DynamicArray_PopFront(DynamicArray* DA);
bool DynamicArray_PopBack(DynamicArray* DA);
bool DynamicArray_Remove(DynamicArray* DA, void* data);
bool DynamicArray_Erase(DynamicArray* DA, size_t index);

#endif
