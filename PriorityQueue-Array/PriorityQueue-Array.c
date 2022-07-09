#include "PriorityQueue-Array.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct PriorityQueueA {
    void* array;
    size_t data_size;
    size_t priority_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
    int (*compare)(void* priority1, void* priority2);
};

PriorityQueueA* PriorityQueueA_create(size_t data_size, size_t priority_size, size_t capacity,
    int (*compare)(void* priority1, void* priority2))
{
    PriorityQueueA* PQ = (PriorityQueueA*)malloc(sizeof (PriorityQueueA));
    if(!PQ) {
        return NULL;
    }
    PQ->array = malloc((data_size + priority_size) * capacity);
    if(!PQ->array) {
        return NULL;
    }
    PQ->data_size = data_size;
    PQ->priority_size = priority_size;
    PQ->front = 0;
    PQ->back = 0;
    PQ->capacity = capacity;
    PQ->size = 0;
    PQ->compare = compare;
    return PQ;
}

bool PriorityQueueA_change_capacity(PriorityQueueA* PQ, size_t capacity)
{
    void* array = realloc(PQ->array, PQ->data_size * capacity);
    if(!array) {
        return false;
    }
    PQ->array = array;
    PQ->capacity = capacity;
    if(PQ->capacity < PQ->size) {
        PQ->back = PQ->capacity;
        PQ->size = PQ->capacity;
    }
    return true;
}

void PriorityQueueA_destroy(PriorityQueueA* PQ)
{
    free(PQ->array);
    PQ->array = NULL;
    free(PQ);
    PQ = NULL;
}

bool PriorityQueueA_empty(PriorityQueueA* PQ)
{
    if(PQ->size) {
        return false;
    }
    return true;
}

size_t PriorityQueueA_size(PriorityQueueA* PQ)
{
    return PQ->size;
}

static inline void* data_at(PriorityQueueA* PQ, size_t index)
{
    return (char*)PQ->array + (PQ->data_size + PQ->priority_size) * index;
}

static inline void* priority_at(PriorityQueueA* PQ, size_t index)
{
    return (char*)PQ->array + ((PQ->data_size + PQ->priority_size) * index) + PQ->data_size;
}

void* PriorityQueueA_front(PriorityQueueA* PQ)
{
    return data_at(PQ, PQ->front);
}

void* PriorityQueueA_back(PriorityQueueA* PQ)
{
    return data_at(PQ, PQ->back - 1);
}

void PriorityQueueA_enqueue(PriorityQueueA* PQ, void* data, void* priority)
{
    if(PQ->back == PQ->capacity) {
        memmove(data_at(PQ, 0), data_at(PQ, PQ->front),
            (PQ->data_size + PQ->priority_size) * PQ->size);
        PQ->front = 0;
        PQ->back = PQ->size;
    }
    if(PQ->compare(data, priority_at(PQ, PQ->front)) < 0) {
        memmove(data_at(PQ, 1), data_at(PQ, 0), (PQ->data_size + PQ->priority_size) * PQ->size);
        memcpy(data_at(PQ, 0), data, PQ->data_size);
        memcpy(priority_at(PQ, 0), priority, PQ->priority_size);
        PQ->size = PQ->size + 1;
        return;
    }
    if(PQ->compare(data, priority_at(PQ, PQ->back - 1)) > 0) {
        memcpy(data_at(PQ, PQ->back), data, PQ->data_size);
        memcpy(priority_at(PQ, PQ->back), priority, PQ->priority_size);
        PQ->back = PQ->back + 1;
        PQ->size = PQ->size + 1;
        return;
    }
    size_t left = PQ->front;
    size_t right = PQ->back - 1;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare = PQ->compare(data, priority_at(PQ, middle));
        if(!compare) {
            memmove(data_at(PQ, middle + 2), data_at(PQ, middle + 1),
                (PQ->data_size + PQ->priority_size) * (PQ->back - middle - 1));
            memcpy(data_at(PQ, middle + 1), data, PQ->data_size);
            memcpy(priority_at(PQ, middle + 1), priority, PQ->priority_size);
            PQ->back = PQ->back + 1;
            PQ->size = PQ->size + 1;
            return;
        }
        else if(compare < 0) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }   
    }
    memmove(data_at(PQ, left + 1), data_at(PQ, left),
        (PQ->data_size + PQ->priority_size) * (PQ->back - left + 1));
    memcpy(data_at(PQ, left), data, PQ->data_size);
    memcpy(priority_at(PQ, left), priority, PQ->priority_size);
    PQ->back = PQ->back + 1;
    PQ->size = PQ->size + 1;
}

void PriorityQueueA_dequeue(PriorityQueueA* PQ)
{
    PQ->front = PQ->front + 1;
    PQ->size = PQ->size - 1;
}
