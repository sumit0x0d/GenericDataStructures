#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DynamicArray {
    void *array;
    size_t front;
    size_t back;
    size_t capacity;
    double growth_factor;
    size_t size;
} DynamicArray;

DynamicArray dynamic_array_create(size_t capacity, double growth_factor);
void dynamic_array_destroy(DynamicArray *DA);

void *dynamic_array_front(DynamicArray *DA, size_t data_size);
void *dynamic_array_back(DynamicArray *DA, size_t data_size);
size_t dynamic_array_size(DynamicArray *DA);

size_t dynamic_array_search(DynamicArray *DA, void *data, size_t data_size);
bool dynamic_array_push_front(DynamicArray *DA, void *data, size_t data_size);
bool dynamic_array_push_back(DynamicArray *DA, void *data, size_t data_size);
bool dynamic_array_insert(DynamicArray *DA, size_t index, void *data, size_t data_size);
bool dynamic_array_sorted_insert(DynamicArray *DA, void *data, size_t data_size);
bool dynamic_array_pop_front(DynamicArray *DA);
bool dynamic_array_pop_back(DynamicArray *DA);
bool dynamic_array_remove(DynamicArray *DA, void *data, size_t data_size);
bool dynamic_array_erase(DynamicArray *DA, size_t index);

#endif
