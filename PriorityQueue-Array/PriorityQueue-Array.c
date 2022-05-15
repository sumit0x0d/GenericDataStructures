#include "PriorityQueue-Array.h"

PriorityQueueA* PriorityQueueA_create(size_t data_size, size_t priority_size, size_t capacity,
    int (*compare)(void* priority1, void* priority2));
int PriorityQueueA_change_capacity(PriorityQueueA* PQ, size_t capacity);
void PriorityQueueA_destroy(PriorityQueueA* PQ);

void PriorityQueueA_enqueue(PriorityQueueA* PQ, void* data, void* priority);
void PriorityQueueA_dequeue(PriorityQueueA* PQ);

void* PriorityQueueA_front(PriorityQueueA* PQ);
void* PriorityQueueA_back(PriorityQueueA* PQ);

PriorityQueueA* PriorityQueueA_create(size_t data_size, size_t priority_size, size_t capacity,
    int (*compare)(void* priority1, void* priority2))
{
    PriorityQueueA* PQ = malloc(sizeof (PriorityQueueA));
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

int PriorityQueueA_change_capacity(PriorityQueueA* PQ, size_t capacity)
{
    void* array = realloc(PQ->array, PQ->data_size * capacity);
    if(!array) {
        return 0;
    }
    PQ->array = array;
    PQ->capacity = capacity;
    if(PQ->capacity < PQ->size) {
        PQ->back = PQ->capacity;
        PQ->size = PQ->capacity;
    }
    return 1;
}

void PriorityQueueA_destroy(PriorityQueueA* PQ)
{
    free(PQ->array);
    PQ->array = NULL;
    free(PQ);
    PQ = NULL;
}

void* PriorityQueueA_front(PriorityQueueA* PQ)
{
    return (char*)PQ->array + ((PQ->data_size + PQ->priority_size) * PQ->front);
}

void* PriorityQueueA_back(PriorityQueueA* PQ)
{
    return (char*)PQ->array + ((PQ->data_size + PQ->priority_size) * (PQ->back - 1));
}

void PriorityQueueA_enqueue(PriorityQueueA* PQ, void* data, void* priority)
{
    if(PQ->back == PQ->capacity) {
        memmove(PQ->array, PriorityQueueA_front(PQ), PQ->size);
        PQ->front = 0;
        PQ->back = PQ->size;
    }
    int compare = PQ->compare(priority, PriorityQueueA_back(PQ) + PQ->data_size);
    if(compare >= 0) {
        memcpy(PriorityQueueA_back(PQ) + (PQ->data_size + PQ->priority_size), data, PQ->data_size);
        memcpy(PriorityQueueA_back(PQ) + ((2 * PQ->data_size) + PQ->priority_size), priority,
            PQ->priority_size);
        PQ->back = PQ->back + 1;
        PQ->size = PQ->size + 1;
        return;
    }
    for(size_t i = PQ->front; i < PQ->back; i++) {
        int compare = PQ->compare(data, (char*)PQ->array + i);
        if(compare < 0) {
            memmove((char*)DA->array + (DA->data_size * (i + 1)),
                (char*)DA->array + (DA->data_size * i), DA->data_size * (DA->size - i - 1));
            memcpy((char*)DA->array + (DA->data_size * i), data, DA->data_size);
            DA->size = DA->size + 1;
            return 1;
        }
    }
}

void PriorityQueueA_dequeue(PriorityQueueA* PQ)
{
    PQ->front = PQ->front + 1;
    PQ->size = PQ->size - 1;
}
