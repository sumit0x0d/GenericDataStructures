#ifndef ARRAY_H
#define ARRAY_H


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

int Array_push_front(Array* DA, void* data);
int Array_push_back(Array* DA, void* data);
int Array_insert(Array* DA, size_t index, void* data);
int Array_sorted_insert(Array* DA, void* data);
int Array_pop_front(Array* DA);
int Array_pop_back(Array* DA);
int Array_remove(Array* DA, void* data);
int Array_erase(Array* DA, size_t index);

size_t Array_search(Array* A, void* data);

#endif
