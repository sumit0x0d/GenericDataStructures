#include "queue-array.h"

QueueArray queue_array_create(int element_type, size_t element_size, size_t capacity);
void queue_array_distroy(QueueArray *Q);

void *queue_array_front(QueueArray *Q);
void *queue_array_back(QueueArray *Q);
size_t queue_array_size(QueueArray *Q);

bool queue_array_enqueue(QueueArray *Q, void *data);
bool queue_array_dequeue(QueueArray *Q);

QueueArray queue_array_create(int element_type, size_t element_size, size_t capacity)
{
    QueueArray Q;

    Q.array = NULL;
    Q.element_type = element_type;
    Q.element_size = element_size;
    Q.front = 0;
    Q.back = 0;
    Q.size = 0;
    Q.capacity = capacity;

    return Q;
}

void queue_array_distroy(QueueArray *Q)
{
    free(Q->array);
    Q->array = NULL;

    Q->front = 0;
    Q->back = 0;
    Q->size = 0;
}

void *queue_array_front(QueueArray *Q)
{
    return (char *)Q->array + Q->front;
}

void *queue_array_back(QueueArray *Q)
{
    return (char *)Q->array + (Q->element_size * Q->back);
}

size_t queue_array_size(QueueArray *Q)
{
    return Q->size;
}

bool queue_array_enqueue(QueueArray *Q, void *data)
{
    if(!Q->array) {
        if(!Q->element_size || !Q->capacity) return false;

        Q->array = malloc(Q->element_size * Q->capacity);
        if(!Q->array) return false;
    }

    if(Q->back == Q->capacity) return false;
        // if(Q->front) {
        //     memmove(Q->array, (char *)Q->array + (Q->element_size * Q->front), Q->size);
        //     Q->front = 0;
        //     Q->back = Q->size;
        // }

    memcpy((char *)Q->array + (Q->element_size * Q->back), data, Q->element_size);

    Q->back = Q->back + 1;

    Q->size = Q->size + 1;

    return true;
}

bool queue_array_dequeue(QueueArray *Q)
{
    if(!Q->size) return false;

    Q->front = Q->front + 1;

    Q->size = Q->size - 1;

    return true;

}
