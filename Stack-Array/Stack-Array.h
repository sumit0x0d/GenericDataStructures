#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct StackA StackA;

StackA* StackACreate(size_t data_size, size_t capacity);
bool StackAChangeCapacity(StackA* S, size_t capacity);
void StackADestroy(StackA* S);
size_t StackASize(StackA* S);
bool StackAEmpty(StackA* S);
bool StackAFull(StackA* S);
void* StackATop(StackA* S);
void StackAPush(StackA* S, void* data);
void StackAPop(StackA* S);

#endif
