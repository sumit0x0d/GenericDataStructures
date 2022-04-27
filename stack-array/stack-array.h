#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackA StackA;

StackA* stack_array_create(size_t data_size, size_t capacity);
bool stack_array_change_capacity(StackA* S, size_t capacity);
void stack_array_destroy(StackA* S);

void* stack_array_peek(StackA* S);
size_t stack_array_size(StackA* S);

bool stack_array_push(StackA* S, void* data);
bool stack_array_pop(StackA* S);

#endif
