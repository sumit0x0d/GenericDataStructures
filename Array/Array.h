#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Array Array;

Array* ArrayCreate(size_t data_size, size_t capacity, int (*compare_function)(void* data1, void* data2));
bool ArrayChangeCapacity(Array* A, size_t capacity);
void ArrayDestroy(Array* A);
size_t ArraySize(Array* A);
bool ArrayEmpty(Array* A);
bool ArrayFull(Array* A);
void* ArrayFront(Array* A);
void* ArrayBack(Array* A);
void* ArrayAt(Array* A, size_t index);
void* ArraySearch(Array* A, void* data);
void ArrayPushFront(Array* A, void* data);
void ArrayPushBack(Array* A, void* data);
void ArrayInsert(Array* A, size_t index, void* data);
void ArraySortedInsert(Array* A, void* data);
void ArrayPopFront(Array* A);
void ArrayPopBack(Array* A);
void ArrayRemove(Array* A, void* data);
void ArrayErase(Array* A, size_t index);

#endif
