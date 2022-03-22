#include "queue-array.h"

Queue queue_array_construct(size_t element_size, size_t capacity);
void queue_array_distroy(Queue *Q);

inline void *queue_array_front(Queue *Q);
inline void *queue_array_back(Queue *Q);
inline size_t queue_array_size(Queue *Q);

bool queue_array_enqueue(Queue *Q, void *data);
bool queue_array_dequeue(Queue *Q);


Queue queue_array_construct(size_t element_size, size_t capacity)
{
    Queue Q;

    Q.array = NULL;
    Q.element_size = element_size;
    Q.front = 0;
    Q.back = 0;
    Q.size = 0;
    Q.capacity = capacity;

    return Q;
}

void queue_array_distroy(Queue *Q)
{
    free(Q->array);
    Q->array = NULL;

    Q->front = 0;
    Q->back = 0;
    Q->size = 0;
}

inline void *queue_array_front(Queue *Q)
{

}

inline void *queue_array_back(Queue *Q)
{

}

inline size_t queue_array_size(Queue *Q)
{

}

bool queue_array_enqueue(Queue *Q, void *data)
{
    if(!Q->array) {
        Q->array = malloc(Q->element_size * Q->capacity);
        if(!Q->array) return false;
    }

    if(Q->size == Q->capacity) return false;

    memcpy((char *)Q->array + Q->front + Q->back, data, Q->element_size);

    Q->back = Q->back + 1;

    Q->size = Q->size + 1;

    return true;
}

bool queue_array_dequeue(Queue *Q)
{
    if(Q->front != Q->back) {
        Q->front++;
        Q->size--;
    }
}
