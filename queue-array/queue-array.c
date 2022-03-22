#include "queue-array.h"

Queue queue_construct(size_t data_type_size, size_t capacity)
{
    Queue Q;

    Q.array = NULL;

    Q.data_type_size = data_type_size;
    Q.front = 0;
    Q.back = 0;
    Q.size = 0;
    Q.capacity = capacity;

    return Q;
}

void queue_distroy(Queue *Q)
{
    free(Q->array);
    Q->array = NULL;

    Q->size = 0;
}

bool queue_enqueue(Queue *Q, void *data)
{
    if(!Q->array) {
        Q->array = malloc(Q->data_type_size * Q->capacity);
        if(!Q->array) return false;
    }

    if(Q->size == Q->capacity) return false;

    memcpy((char *)Q->array + Q->front + Q->back, data, Q->data_type_size);
    
    Q->back = Q->back + 1;
    
    Q->size = Q->size + 1;

    return true;
}

void queue_dequeue(Queue *Q)
{
    if(Q->front != Q->back) {
        Q->front++;
        Q->size--;
    }
}
