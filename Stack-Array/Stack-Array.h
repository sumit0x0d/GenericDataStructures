#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct StackA StackA;

StackA* StackA_create(size_t data_size, size_t capacity);
bool StackA_change_capacity(StackA* S, size_t capacity);
void StackA_destroy(StackA* S);
bool StackA_empty(StackA* S);
bool StackA_full(StackA* S);
size_t StackA_size(StackA* S);

void* StackA_top(StackA* S);

void StackA_push(StackA* S, void* data);
void StackA_pop(StackA* S);

#endif
