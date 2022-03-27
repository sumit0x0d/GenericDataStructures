#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

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
    STRUCT,
    UNION,
    ARRAY,
    POINTER
};

#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackArray {
    void *array;
    int element_type;
    size_t element_size;
    size_t top;
    size_t size;
    size_t capacity;
} StackArray;

StackArray stack_array_create(int element_type, size_t element_size, size_t capacity);
void stack_array_distroy(StackArray *S);

void *stack_array_peek(StackArray *S);
size_t stack_array_size(StackArray *S);

bool stack_array_push(StackArray *S, void *data);
bool stack_array_pop(StackArray *S);

#endif
