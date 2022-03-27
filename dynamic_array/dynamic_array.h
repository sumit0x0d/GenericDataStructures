#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#ifndef DATA_TYPE
#define DATA_TYPE

enum {
    BOOL,
    CHAR,
    UNSIGNED_CHAR,
    SHORT,
    UNSIGNED_SHORT,
    INT,
    UNSIGNED_INT,
    FLOAT,
    LONG,
    UNSIGNED_LONG,
    DOUBLE,
    LONG_LONG,
    UNSIGNED_LONG_LONG,
    LONG_DOUBLE,
    STRING,
    STRUCT
};

#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DynamicArray {
    void *array;
    int element_type;
    size_t element_size;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
    double growth_factor;
} DynamicArray;

DynamicArray dynamic_array_create(int element_type, size_t element_size, size_t capacity, double growth_factor);
void dynamic_array_distroy(DynamicArray *DA);

void *dynamic_array_front(DynamicArray *DS);
void *dynamic_array_back(DynamicArray *DS);
size_t dynamic_array_size(DynamicArray *DS);

size_t dynamic_array_search(DynamicArray *DA, void *data);
bool dynamic_array_push_front(DynamicArray *DA, void *data);
bool dynamic_array_push_back(DynamicArray *DA, void *data);
bool dynamic_array_insert(DynamicArray *DA, size_t index, void *data);
bool dynamic_array_sorted_insert(DynamicArray *DA, void *data);
bool dynamic_array_pop_front(DynamicArray *DA);
bool dynamic_array_pop_back(DynamicArray *DA);
bool dynamic_array_remove(DynamicArray *DA, void *data);
bool dynamic_array_erase(DynamicArray *DA, size_t index);

#endif
