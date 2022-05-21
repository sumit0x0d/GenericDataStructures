#include "PriorityQueue-Array2.h"

PriorityQueueA* PriorityQueueA_create(size_t data_size, size_t priority_size, size_t capacity,
    int (*compare)(void* priority1, void* priority2));
int PriorityQueueA_change_capacity(PriorityQueueA* PQ, size_t capacity);
void PriorityQueueA_destroy(PriorityQueueA* PQ);

void* PriorityQueueA_back(PriorityQueueA* PQ);
void* PriorityQueueA_front(PriorityQueueA* PQ);

void PriorityQueueA_enqueue(PriorityQueueA* PQ, void* data, void* priority);
void PriorityQueueA_dequeue(PriorityQueueA* PQ);

PriorityQueueA* PriorityQueueA_create(size_t data_size, size_t priority_size, size_t capacity,
    int (*compare)(void* priority1, void* priority2))
{
    PriorityQueueA* PQ = malloc(sizeof (PriorityQueueA));
    if(!PQ) {
        return NULL;
    }
    PQ->array = malloc(sizeof (PriorityQueueANode) * capacity);
    if(!PQ->array) {
        free(PQ);
        PQ = NULL;
        return NULL;
    }
    for(size_t i = 0; i < capacity; i++) {
        PQ->array[i].data = malloc(data_size);
        if(!PQ->array[i].data) {
            for(size_t j = i; j < i; j++) {
                free(PQ->array[j].data);
                PQ->array[j].data = NULL;
            }
            free(PQ->array);
            PQ->array = NULL;
            free(PQ);
            PQ = NULL;
            return NULL;
        }
        PQ->array[i].priority = malloc(priority_size);
        if(!PQ->array[i].priority) {
            for(size_t j = i; j < i; j++) {
                free(PQ->array[j].data);
                PQ->array[j].data = NULL;
                free(PQ->array[j].priority);
                PQ->array[j].priority = NULL;
            }
            free(PQ->array);
            PQ->array = NULL;
            free(PQ);
            PQ = NULL;
            return NULL;
        }
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
    return PQ->array[PQ->front].data;
}

void* PriorityQueueA_back(PriorityQueueA* PQ)
{
    return PQ->array[PQ->back - 1].data;
}

void PriorityQueueA_enqueue(PriorityQueueA* PQ, void* data, void* priority)
{
    if(PQ->back == PQ->capacity) {
        memmove(PQ->array, PQ->array[PQ->front].data, PQ->size);
        PQ->front = 0;
        PQ->back = PQ->size;
    }
    int compare = PQ->compare(priority, PQ->array[PQ->back].data);
    if(compare >= 0) {
        memcpy(PQ->array[PQ->back].data, data, PQ->data_size);
        memcpy(PQ->array[PQ->back].priority, priority, PQ->priority_size);
        PQ->back = PQ->back + 1;
        PQ->size = PQ->size + 1;
    }
}

void PriorityQueueA_dequeue(PriorityQueueA* PQ)
{
    PQ->front = PQ->front + 1;
    PQ->size = PQ->size - 1;
}
