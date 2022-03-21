#include "queue.h"

Queue queue_construct();
void queue_destruct(Queue *);

QueueNode *queue_front(Queue *);
QueueNode *queue_front(Queue *);
size_t queue_size(Queue *);

QueueNode *node_construct(size_t);
void node_destruct(QueueNode *);

bool queue_enqueue(Queue *, void *, size_t);
bool queue_dequeue(Queue *);

Queue queue_construct()
{
    Queue Q;

    Q.front = NULL;
    Q.back = NULL;
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

QueueNode *queue_front(Queue *Q)
{
    return Q->front;
}

QueueNode *queue_back(Queue *Q)
{
    return Q->back;
}

size_t queue_size(Queue *Q)
{
    return Q->size;
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

void node_destruct(QueueNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool queue_enqueue(Queue *Q, void *data, size_t data_type_size)
{
    QueueNode *node = node_construct(data_type_size);
    if(!node) return false;

    memcpy(node->data, data, data_type_size);

    if(Q->size)
        Q->back->next = node;
    else 
        Q->front = node;
    Q->back = node;

    Q->size = Q->size + 1;

    return true;
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
