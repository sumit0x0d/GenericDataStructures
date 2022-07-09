#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Array Array;

Array* Array_create(size_t data_size, size_t capacity, int (*compare)(void* data1, void* data2));
bool Array_change_capacity(Array* A, size_t capacity);
void Array_destroy(Array* A);
size_t Array_size(Array* A);
bool Array_empty(Array* A);
bool Array_full(Array* A);
void* Array_front(Array* A);
void* Array_back(Array* A);
void* Array_at(Array* A, size_t index);
void* Array_search(Array* A, void* data);
void Array_push_front(Array* A, void* data);
void Array_push_back(Array* A, void* data);
void Array_insert(Array* A, size_t index, void* data);
void Array_sorted_insert(Array* A, void* data);
void Array_pop_front(Array* A);
void Array_pop_back(Array* A);
void Array_remove(Array* A, void* data);
void Array_erase(Array* A, size_t index);

#endif
