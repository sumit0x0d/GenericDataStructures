#include "queue.h"

bool queue_enqueue(Queue *Q, void *data);
bool queue_dequeue(Queue *Q);

Queue queue_construct(size_t data_type_size)
{
    Queue Q;

    Q.front = NULL;
    Q.back = NULL;
    Q.data_type_size = data_type_size;
    Q.size = 0;

    return Q;
}

void queue_destruct(Queue *Q)
{
    QueueNode *node = Q->front;
    while(node)
        if(node->next) {
            queue_dequeue(Q);
            node = Q->front;   
        }
        else {
            queue_dequeue(Q);
            break;
        }
}

QueueNode *node_construct(size_t data_type_size)
{
    QueueNode *node = malloc(sizeof (QueueNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }
    
    node->next = NULL;

    return node;
}

bool queue_enqueue(Queue *Q, void *data)
{
    QueueNode *node = node_construct(Q->data_type_size);
    if(!node) return false;

    memcpy(node->data, data, Q->data_type_size);

    if(Q->size)
        Q->back->next = node;
    else 
        Q->front = node;
    Q->back = node;

    Q->size = Q->size + 1;

    return true;
}

void node_destruct(QueueNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool queue_dequeue(Queue *Q)
{
    if(!Q->size) return false;

    QueueNode *node = Q->front;

    Q->front = Q->front->next;
    if(!Q->front)
        Q->back = NULL;

    node_destruct(node);

    Q->size = Q->size - 1;

    return true;
}
