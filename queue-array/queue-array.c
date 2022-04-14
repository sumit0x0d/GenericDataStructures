#include "queue-array.h"

typedef struct QueueArray {
    void *array;
    size_t data_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
} QueueArray;

QueueArray *queue_array_create(size_t data_size, size_t capacity);
bool queue_array_change_capacity(QueueArray *Q, size_t capacity);
void queue_array_destroy(QueueArray *Q);

void *queue_array_front(QueueArray *Q);
void *queue_array_back(QueueArray *Q);
size_t queue_array_size(QueueArray *Q);

bool queue_array_enqueue(QueueArray *Q, void *data);
bool queue_array_dequeue(QueueArray *Q);

QueueArray *queue_array_create(size_t data_size, size_t capacity)
{
    QueueArray *Q = malloc(sizeof (QueueArray));
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

bool queue_array_change_capacity(QueueArray *Q, size_t capacity)
{
    if(!capacity) {
        return false;
    }
    void *array = realloc(Q->array, Q->data_size * capacity);
    if(!array) {
        return false;
    }
    Q->array = array;
    Q->capacity = capacity;
    return true;
}

void queue_array_destroy(QueueArray *Q)
{
    free(Q->array);
    Q->array = NULL;
    Q->front = 0;
    Q->back = 0;
    Q->size = 0;
}

void *queue_array_front(QueueArray *Q)
{
    if(!Q->array) {
        return NULL;
    }
    return (char *)Q->array + (Q->data_size * Q->front);
}

void *queue_array_back(QueueArray *Q)
{
    if(!Q->array) {
        return NULL;
    }
    return (char *)Q->array + (Q->data_size * Q->back);
}

size_t queue_array_size(QueueArray *Q)
{
    return Q->size;
}

bool queue_array_enqueue(QueueArray *Q, void *data)
{
    if(Q->back == Q->capacity) {
        if(Q->front) {
            memmove(Q->array, (char *)Q->array + (Q->data_size * Q->front), Q->size);
            Q->front = 0;
            Q->back = Q->size;
        }
        else {
            return false;
        }
    }
    memcpy((char *)Q->array + (Q->data_size * Q->back), data, Q->data_size);
    Q->back = Q->back + 1;
    Q->size = Q->size + 1;
    return true;
}

bool queue_array_dequeue(QueueArray *Q)
{
    if(!Q->size) {
        return false;
    }
    Q->front = Q->front + 1;
    Q->size = Q->size - 1;
    return true;
}
