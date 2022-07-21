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
    int (*compare_function)(void* priority1, void* priority2);
};

PriorityQueueA* PriorityQueueA_Create(size_t data_size, size_t priority_size, size_t capacity,
    int (*compare_function)(void* priority1, void* priority2))
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
    PQ->compare_function = compare_function;
    return PQ;
}

bool PriorityQueueA_ChangeCapacity(PriorityQueueA* PQ, size_t capacity)
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

void PriorityQueueA_Destroy(PriorityQueueA* PQ)
{
    free(PQ->array);
    PQ->array = NULL;
    free(PQ);
    PQ = NULL;
}

size_t PriorityQueueA_Size(PriorityQueueA* PQ)
{
    return PQ->size;
}

bool PriorityQueueA_Empty(PriorityQueueA* PQ)
{
    if(PQ->size) {
        return false;
    }
    return true;
}

bool PriorityQueueA_Full(PriorityQueueA *PQ)
{
    if(PQ->size != PQ->capacity) {
        return false;
    }
    return true;
}

static inline void* DataAt(PriorityQueueA* PQ, size_t index)
{
    return (char*)PQ->array + (PQ->data_size + PQ->priority_size) * index;
}

static inline void* priority_At(PriorityQueueA* PQ, size_t index)
{
    return (char*)PQ->array + ((PQ->data_size + PQ->priority_size) * index) + PQ->data_size;
}

void* PriorityQueueA_Front(PriorityQueueA* PQ)
{
    return DataAt(PQ, PQ->front);
}

void* PriorityQueueA_Back(PriorityQueueA* PQ)
{
    return DataAt(PQ, PQ->back - 1);
}

void PriorityQueueA_Enqueue(PriorityQueueA* PQ, void* data, void* priority)
{
    if(PQ->back == PQ->capacity) {
        memmove(DataAt(PQ, 0), DataAt(PQ, PQ->front),
            (PQ->data_size + PQ->priority_size) * PQ->size);
        PQ->front = 0;
        PQ->back = PQ->size;
    }
    if(PQ->compare_function(data, priority_At(PQ, PQ->front)) < 0) {
        memmove(DataAt(PQ, 1), DataAt(PQ, 0), (PQ->data_size + PQ->priority_size) * PQ->size);
        memcpy(DataAt(PQ, 0), data, PQ->data_size);
        memcpy(priority_At(PQ, 0), priority, PQ->priority_size);
        PQ->size = PQ->size + 1;
        return;
    }
    if(PQ->compare_function(data, priority_At(PQ, PQ->back - 1)) > 0) {
        memcpy(DataAt(PQ, PQ->back), data, PQ->data_size);
        memcpy(priority_At(PQ, PQ->back), priority, PQ->priority_size);
        PQ->back = PQ->back + 1;
        PQ->size = PQ->size + 1;
        return;
    }
    size_t left = PQ->front;
    size_t right = PQ->back - 1;
    while(left <= right) {
        size_t middle = left + ((right - left) / 2);
        int compare_function = PQ->compare_function(data, priority_At(PQ, middle));
        if(!compare_function) {
            memmove(DataAt(PQ, middle + 2), DataAt(PQ, middle + 1),
                (PQ->data_size + PQ->priority_size) * (PQ->back - middle - 1));
            memcpy(DataAt(PQ, middle + 1), data, PQ->data_size);
            memcpy(priority_At(PQ, middle + 1), priority, PQ->priority_size);
            PQ->back = PQ->back + 1;
            PQ->size = PQ->size + 1;
            return;
        }
        else if(compare_function < 0) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }   
    }
    memmove(DataAt(PQ, left + 1), DataAt(PQ, left),
        (PQ->data_size + PQ->priority_size) * (PQ->back - left + 1));
    memcpy(DataAt(PQ, left), data, PQ->data_size);
    memcpy(priority_At(PQ, left), priority, PQ->priority_size);
    PQ->back = PQ->back + 1;
    PQ->size = PQ->size + 1;
}

void PriorityQueueA_Dequeue(PriorityQueueA* PQ)
{
    PQ->front = PQ->front + 1;
    PQ->size = PQ->size - 1;
}
