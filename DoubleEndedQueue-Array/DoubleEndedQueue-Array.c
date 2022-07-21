#include "DoubleEndedQueue-Array.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct DoubleEndedQueueA {
    void* array;
    size_t data_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
};

DoubleEndedQueueA* DoubleEndedQueueA_Create(size_t data_size, size_t capacity)
{
    DoubleEndedQueueA* DEQ = (DoubleEndedQueueA*)malloc(sizeof (DoubleEndedQueueA));
    if(!DEQ) {
        return NULL;
    }
    DEQ->array = malloc(data_size * capacity);
    if(!DEQ->array) {
        free(DEQ);
        DEQ = NULL;
        return NULL;
    }
    DEQ->data_size = data_size;
    DEQ->front = 0;
    DEQ->back = 0;
    DEQ->capacity = capacity;
    DEQ->size = 0;
    return DEQ;
}

bool DoubleEndedQueueA_ChangeCapacity(DoubleEndedQueueA* DEQ, size_t capacity)
{
    void* array = realloc(DEQ->array, DEQ->data_size * capacity);
    if(!array) {
        return false;
    }
    DEQ->array = array;
    DEQ->capacity = capacity;
    return true;
}

void DoubleEndedQueueA_Destroy(DoubleEndedQueueA* DEQ)
{
    free(DEQ->array);
    DEQ->array = NULL;
    free(DEQ);
    DEQ = NULL;
}

size_t DoubleEndedQueueA_Size(DoubleEndedQueueA* DEQ)
{
    return DEQ->size;
}

bool DoubleEndedQueueA_Empty(DoubleEndedQueueA* DEQ)
{
    if(DEQ->size) {
        return false;
    }
    return true;
}

bool DoubleEndedQueueA_Full(DoubleEndedQueueA* DEQ)
{
    if(DEQ->size != DEQ->capacity) {
        return false;
    }
    return true;
}

static inline void* DataAt(DoubleEndedQueueA* DEQ, size_t index)
{
    return (char*)DEQ->array + (DEQ->data_size * index);
}

void* DoubleEndedQueueA_Front(DoubleEndedQueueA* DEQ)
{
    return DataAt(DEQ, DEQ->front);
}

void* DoubleEndedQueueA_Back(DoubleEndedQueueA* DEQ)
{
    return DataAt(DEQ DEQ->back - 1);
}

void DoubleEndedQueueA_PushFront(DoubleEndedQueueA* DEQ, void* data)
{
    if(DEQ->front) {
        DEQ->front = DEQ->front - 1;
    }
    else {
        memmove(DataAt(DEQ, 1), DataAt(DEQ, DEQ->front), DEQ->data_size * DEQ->size);
    }
    memcpy(DataAt(DEQ, DEQ->front), data, DEQ->data_size);
    DEQ->size = DEQ->size + 1;
}

void DoubleEndedQueueA_PushBack(DoubleEndedQueueA* DEQ, void* data)
{
    if(DEQ->back == DEQ->capacity) {
        memmove(DataAt(DEQ, 0), DataAt(DEQ, DEQ->front), DEQ->data_size * DEQ->size);
        DEQ->front = 0;
        DEQ->back = DEQ->size;
    }
    memcpy(DataAt(DEQ, DEQ->back), data, DEQ->data_size);
    DEQ->back = DEQ->back + 1;
    DEQ->size = DEQ->size + 1;
}

void DoubleEndedQueueA_PopFront(DoubleEndedQueueA* DEQ)
{
    DEQ->front = DEQ->front + 1;
    DEQ->size = DEQ->size - 1;
}

void DoubleEndedQueueA_PopBack(DoubleEndedQueueA* DEQ)
{
    DEQ->back = DEQ->back - 1;
    DEQ->size = DEQ->size - 1;
}
