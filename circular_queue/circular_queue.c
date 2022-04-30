#include "circular_queue.h"

CircularQueue* CircularQueue_create(size_t data_size, size_t capacity);
void CircularQueue_destroy(CircularQueue *CB);

bool CircularQueue_enqueue(CircularQueue* CB, void* data);
bool CircularQueue_dequeue(CircularQueue* CB);

CircularQueue* CircularQueue_create(size_t data_size, size_t capacity)
{
    CircularQueue* CB = malloc(sizeof (CircularQueue));
    if(!CB) {
        return NULL;
    }
    CB->array = malloc(data_size * capacity);
    if(!CB->array) {
        free(CB);
        CB = NULL;
        return NULL;
    }
    CB->data_size = data_size;
    CB->front = 0;
    CB->back = 0;
    CB->capacity = capacity;
    CB->size = 0;
    return CB;
}

void CircularQueue_destroy(CircularQueue *CB)
{
    free(CB->array);
    CB->array = NULL;
    free(CB);
    CB = NULL;
}

bool CircularQueue_enqueue(CircularQueue* CB, void* data)
{
    memcpy((char*)CB->array + (CB->data_size * CB->back), data, CB->data_size);
    CB->back = (CB->back + 1) % CB->capacity;
    CB->size = CB->size + 1;
    return true;
}

bool CircularQueue_dequeue(CircularQueue* CB)
{
    if(!CB->size) {
        return false;
    }
    CB->front = (CB->front + 1) % CB->capacity;
    CB->size = CB->size - 1;
    return true;
}
