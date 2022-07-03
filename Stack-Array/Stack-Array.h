#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackA {
    void* array;
    size_t data_size;
    size_t capacity;
    size_t size;
} StackA;

StackA* StackA_create(size_t data_size, size_t capacity);
bool StackA_change_capacity(StackA* S, size_t capacity);
void StackA_destroy(StackA* S);

void* StackA_top(StackA* S);

void StackA_push(StackA* S, void* data);
void StackA_pop(StackA* S);

#endif