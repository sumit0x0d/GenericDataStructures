#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

struct DynamicArray {
    int *array;
    size_t data_type_size;
    size_t size;
    size_t capacity;
    double growth_factor;
    void (*push_front)(struct DynamicArray *dynamic_array, int data);
    void (*push_back)(struct DynamicArray *dynamic_array, int data);
    void (*insert)(struct DynamicArray *dynamic_array, size_t index, int data);
    void (*sorted_insert)(struct DynamicArray *dynamic_array, int data);
    void (*pop_front)(struct DynamicArray *dynamic_array);
    void (*pop_back)(struct DynamicArray *dynamic_array);
    void (*remove)(struct DynamicArray *dynamic_array, int data);
    void (*erase)(struct DynamicArray *dynamic_array, size_t index);
};

void dynamic_array_print(struct DynamicArray *dynamic_array);
struct DynamicArray *dynamic_array_construct(size_t capacity, double growth_factor);
void *dynamic_array_search(struct DynamicArray *dynamic_array, int data);

#endif
