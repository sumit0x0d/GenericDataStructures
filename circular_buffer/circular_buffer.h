#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct CircularBuffer {
    void* array;
    size_t data_size;
    size_t begin;
    size_t end;
    size_t capacity;
    size_t size;
} CircularBuffer;

CircularBuffer* CircularBuffer_create(size_t data_size, size_t capacity);
void CircularBuffer_destroy(CircularBuffer *CB);

bool CircularBuffer_push(CircularBuffer* CB, void* data);
bool CircularBuffer_pop(CircularBuffer* CB);

#endif
