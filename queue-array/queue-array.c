#include "queue-array.h"

struct QueueA {
    void* array;
    size_t data_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
};

QueueA* queue_array_create(size_t data_size, size_t capacity);
bool queue_array_change_capacity(QueueA* Q, size_t capacity);
void queue_array_destroy(QueueA* Q);

void* queue_array_front(QueueA* Q);
void* queue_array_back(QueueA* Q);
size_t queue_array_size(QueueA* Q);

bool queue_array_enqueue(QueueA* Q, void* data);
bool queue_array_dequeue(QueueA* Q);

QueueA* queue_array_create(size_t data_size, size_t capacity)
{
    QueueA* Q = malloc(sizeof (QueueA));
    if(!Q) {
        return NULL;
    }
    Q->array = malloc(data_size * capacity);
    if(!Q->array) {
        return NULL;
    }
    Q->data_size = data_size;
    Q->front = 0;
    Q->back = 0;
    Q->capacity = capacity;
    Q->size = 0;
    return Q;
}

bool queue_array_change_capacity(QueueA* Q, size_t capacity)
{
    if(!capacity) {
        return false;
    }
    void* array = realloc(Q->array, Q->data_size * capacity);
    if(!array) {
        return false;
    }
    Q->array = array;
    Q->capacity = capacity;
    return true;
}

void queue_array_destroy(QueueA* Q)
{
    free(Q->array);
    Q->array = NULL;
    free(Q);
    Q = NULL;
}

void* queue_array_front(QueueA* Q)
{
    return (char*)Q->array + (Q->data_size * Q->front);
}

void* queue_array_back(QueueA* Q)
{
    return (char*)Q->array + (Q->data_size * Q->back);
}

size_t queue_array_size(QueueA* Q)
{
    return Q->size;
}

bool queue_array_enqueue(QueueA* Q, void* data)
{
    if(Q->back == Q->capacity) {
        if(Q->front) {
            memmove(Q->array, (char*)Q->array + (Q->data_size * Q->front), Q->size);
            Q->front = 0;
            Q->back = Q->size;
        }
        else {
            return false;
        }
    }
    memcpy((char*)Q->array + (Q->data_size * Q->back), data, Q->data_size);
    Q->back = Q->back + 1;
    Q->size = Q->size + 1;
    return true;
}

bool queue_array_dequeue(QueueA* Q)
{
    if(!Q->size) {
        return false;
    }
    Q->front = Q->front + 1;
    Q->size = Q->size - 1;
    return true;
}
