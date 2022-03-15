#include "queue.h"

void enqueue(struct Queue *Q, void *data);
void dequeue(struct Queue *Q);

struct Queue queue_construct(size_t data_type_size)
{
    struct Queue Q;

    Q.front = NULL;
    Q.back = NULL;
    Q.data_type_size = data_type_size;
    Q.size = 0;

    Q.enqueue = enqueue;
    Q.dequeue = dequeue;

    return Q;
}

void queue_destruct(struct Queue *Q)
{
    struct QueueNode *node = Q->front;
    while(node)
        if(node->next) {
            Q->dequeue(Q);
            node = Q->front;   
        }
        else {
            Q->dequeue(Q);
            break;
        }
}

struct QueueNode *node_construct(void *data, size_t data_type_size)
{
    struct QueueNode *node = malloc(sizeof (struct QueueNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    memcpy(node->data, data, data_type_size);
    
    node->next = NULL;

    return node;
}

void enqueue(struct Queue *Q, void *data)
{
    struct QueueNode *node = node_construct(data, Q->data_type_size);
    if(!node) return;

    if(Q->size)
        Q->back->next = node;
    else 
        Q->front = node;
    Q->back = node;

    Q->size = Q->size + 1;
}

void node_destruct(struct QueueNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

void dequeue(struct Queue *Q)
{
    if(!Q->size) return;

    struct QueueNode *node = Q->front;

    Q->front = Q->front->next;
    if(!Q->front)
        Q->back = NULL;

    node_destruct(node);

    Q->size = Q->size - 1;
}
