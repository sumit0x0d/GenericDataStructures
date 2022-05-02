#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

typedef struct Array {
    void* array;
    size_t data_size;
    size_t capacity;
    size_t size;
    int (*compare)(void* data, void* node_data);
} Array;

Array* Array_create(size_t capacity);
void Array_change_capacity(Array* A);
void Array_destroy(Array* A);

bool Array_insert(Array* A, void* data);
bool Array_remove(Array* A, void* data);

size_t Array_search(Array* A, void* data);

#endif
