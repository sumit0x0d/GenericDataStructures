#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

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
    STRING,
    STRUCT
};

#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueArray {
    void *array;
    size_t element_size;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
} QueueArray;

QueueArray queue_array_construct(size_t element_size, size_t capacity);
void queue_array_distroy(QueueArray *Q);

void *queue_array_front(QueueArray *Q);
void *queue_array_back(QueueArray *Q);
size_t queue_array_size(QueueArray *Q);

bool queue_array_enqueue(QueueArray *Q, void *data);
bool queue_array_dequeue(QueueArray *Q);

#endif
