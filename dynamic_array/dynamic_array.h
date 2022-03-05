#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <string.h>

struct DynamicArray {
    void *array;
    size_t element_size;
    size_t size;
    size_t capacity;
    double growth_factor;
    void (*push_front)(struct DynamicArray *dynamic_array, void *data);
    void (*push_back)(struct DynamicArray *dynamic_array, void *data);
    void (*insert)(struct DynamicArray *dynamic_array, size_t index, void *data);
    void (*sorted_insert)(struct DynamicArray *dynamic_array, void *data);
    void (*pop_front)(struct DynamicArray *dynamic_array);
    void (*pop_back)(struct DynamicArray *dynamic_array);
    void (*remove)(struct DynamicArray *dynamic_array, void *data);
    void (*erase)(struct DynamicArray *dynamic_array, size_t index);
};

struct DynamicArray dynamic_array_construct(size_t element_size, size_t capacity, double growth_factor);
void *dynamic_array_search(struct DynamicArray *dynamic_array, void *data);

#endif
