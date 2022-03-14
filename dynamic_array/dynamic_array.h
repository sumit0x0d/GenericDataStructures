#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <string.h>

struct Array {
    void *data;
    // size_t data_type_size;
    // size_t size;
    // size_t capacity;
};

struct DynamicArray {
    // struct Array *array;
    void **array;
    size_t data_type_size;
    size_t size;
    size_t capacity;
    double growth_factor;
    void (*push_front)(struct DynamicArray *da, void *data);
    void (*push_back)(struct DynamicArray *da, void *data);
    void (*insert)(struct DynamicArray *da, size_t index, void *data);
    void (*sorted_insert)(struct DynamicArray *da, void *data);
    void (*pop_front)(struct DynamicArray *da);
    void (*pop_back)(struct DynamicArray *da);
    void (*remove)(struct DynamicArray *da, void *data);
    void (*erase)(struct DynamicArray *da, size_t index);
};

struct DynamicArray dynamic_array_construct(size_t element_size, size_t capacity, double growth_factor);
void *dynamic_array_search(struct DynamicArray *da, void *data);

#endif
