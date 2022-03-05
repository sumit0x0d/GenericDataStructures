#include "queue.h"

struct Queue *queue_construct(size_t data_type_size, size_t capacity)
{
    assert(capacity);

    struct Queue *queue = malloc(sizeof(struct Queue));
    if(!queue) return NULL;

    queue->array = malloc(data_type_size * capacity);
    if(!queue->array) return NULL;

    queue->data_type_size = data_type_size;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void queue_distroy(struct Queue *queue)
{

}

void queue_enqueue(struct Queue *queue, void *data)
{
    if(queue->size < queue->capacity) {
        queue->back++;
        memcpy(&queue->array[queue->back], data, queue->data_type_size);
        ++queue->size;
    }
}

void queue_dequeue(struct Queue *queue)
{
    if(queue->front != queue->back) {
        queue->front++;
        queue->size--;
    }
}
