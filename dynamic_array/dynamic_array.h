#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct DynamicArray {
    void *array;
    size_t element_size;
    size_t size;
    size_t capacity;
    double growth_factor;
};

struct DynamicArray dynamic_array_construct(size_t element_size, size_t capacity, double growth_factor);
size_t dynamic_array_search(struct DynamicArray *DA, void *data);
bool dynamic_array_push_front(struct DynamicArray *DA, void *data);
bool dynamic_array_push_back(struct DynamicArray *DA, void *data);
bool dynamic_array_insert(struct DynamicArray *DA, size_t index, void *data);
bool dynamic_array_sorted_insert(struct DynamicArray *DA, void *data);
bool dynamic_array_pop_front(struct DynamicArray *DA);
bool dynamic_array_pop_back(struct DynamicArray *DA);
bool dynamic_array_remove(struct DynamicArray *DA, void *data);
bool dynamic_array_erase(struct DynamicArray *DA, size_t index);

#endif
