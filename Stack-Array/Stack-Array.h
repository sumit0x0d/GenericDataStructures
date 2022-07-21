#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct StackA StackA;

StackA* StackA_Create(size_t data_size, size_t capacity);
bool StackA_ChangeCapacity(StackA* S, size_t capacity);
void StackA_Destroy(StackA* S);
size_t StackA_Size(StackA* S);
bool StackA_Empty(StackA* S);
bool StackA_Full(StackA* S);
void* StackA_Top(StackA* S);
void StackA_Push(StackA* S, void* data);
void StackA_Pop(StackA* S);

#endif
