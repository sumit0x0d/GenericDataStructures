#ifndef DEQUE_ARRAY_H
#define DEQUE_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct DequeA DequeA;

DequeA* DequeACreate(size_t data_size, size_t capacity);
bool DequeAChangeCapacity(DequeA* D, size_t capacity);
void DequeADestroy(DequeA* D);
size_t DequeASize(DequeA* D);
bool DequeAEmpty(DequeA* D);
bool DequeAFull(DequeA* D);
void* DequeAFront(DequeA* Q);
void* DequeABack(DequeA* Q);
void DequeAPushFront(DequeA* D, void* data);
void DequeAPushBack(DequeA* D, void* data);
void DequeAPopFront(DequeA* D);
void DequeAPopBack(DequeA* D);

#endif
