#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Array Array;

Array* Array_Create(size_t data_size, size_t capacity, int (*compare_function)(void* data1, void* data2));
bool Array_ChangeCapacity(Array* A, size_t capacity);
void Array_Destroy(Array* A);
size_t Array_Size(Array* A);
bool Array_Empty(Array* A);
bool Array_Full(Array* A);
void* ArrayFront(Array* A);
void* ArrayBack(Array* A);
void* Array_At(Array* A, size_t index);
void* Array_Search(Array* A, void* data);
void Array_PushFront(Array* A, void* data);
void Array_PushBack(Array* A, void* data);
void Array_Insert(Array* A, size_t index, void* data);
void Array_SortedInsert(Array* A, void* data);
void Array_PopFront(Array* A);
void Array_PopBack(Array* A);
void Array_Remove(Array* A, void* data);
void Array_Erase(Array* A, size_t index);

#endif
