#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Array {
    void* array;
    size_t data_size;
    size_t capacity;
    size_t size;
    int (*compare)(void* data1, void* data2);
} Array;

Array* Array_create(size_t data_size, size_t capacity,
    int (*compare)(void* data1, void* data2));
void Array_change_capacity(Array* A, size_t capacity);
void Array_destroy(Array* A);

bool Array_push_front(Array* DA, void* data);
bool Array_push_back(Array* DA, void* data);
bool Array_insert(Array* DA, size_t index, void* data);
bool Array_sorted_insert(Array* DA, void* data);
bool Array_pop_front(Array* DA);
bool Array_pop_back(Array* DA);
bool Array_remove(Array* DA, void* data);
bool Array_erase(Array* DA, size_t index);

size_t Array_search(Array* A, void* data);

#endif
