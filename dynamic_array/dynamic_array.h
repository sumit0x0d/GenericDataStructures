#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct DynamicArray {
    int *array;
    size_t data_type_size;
    size_t size;
    size_t capacity;
    double growth_factor;
};

void dynamic_array_print(struct DynamicArray *dynamic_array);
struct DynamicArray *dynamic_array_construct(size_t capacity, double growth_factor);
void *dynamic_array_search(struct DynamicArray *dynamic_array, int data);
void dynamic_array_push_front(struct DynamicArray *dynamic_array, int data);
void dynamic_array_push_back(struct DynamicArray *dynamic_array, int data);
void dynamic_array_insert(struct DynamicArray *dynamic_array, size_t index, int data);
void dynamic_array_sorted_insert(struct DynamicArray *dynamic_array, int data);
void dynamic_array_pop_front(struct DynamicArray *dynamic_array);
void dynamic_array_pop_back(struct DynamicArray *dynamic_array);
void dynamic_array_remove(struct DynamicArray *dynamic_array, int data);
void dynamic_array_erase(struct DynamicArray *dynamic_array, size_t index);

#endif
