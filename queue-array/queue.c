#include "queue.h"

struct Queue *queue_construct(size_t data_type_size, size_t capacity)
{
    assert(capacity);

    struct Queue *Q = malloc(sizeof (struct Queue));
    if(!Q) return NULL;

    Q->array = malloc(data_type_size * capacity);
    if(!Q->array) return NULL;

    Q->data_type_size = data_type_size;
    Q->size = 0;
    Q->capacity = capacity;
    return Q;
}

void queue_distroy(struct Queue *Q)
{

}

void queue_enqueue(struct Queue *Q, void *data)
{
    if(Q->size < Q->capacity) {
        Q->back++;
        memcpy(&Q->array[Q->back], data, Q->data_type_size);
        ++Q->size;
    }
}

void queue_dequeue(struct Queue *Q)
{
    if(Q->front != Q->back) {
        Q->front++;
        Q->size--;
    }
}
