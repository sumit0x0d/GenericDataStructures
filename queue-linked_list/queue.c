#include "queue.h"

void enqueue(struct Queue *queue, void *data);
void dequeue(struct Queue *queue);

struct Queue queue_construct(size_t data_type_size)
{
    struct Queue queue;

    queue.front = NULL;
    queue.back = NULL;
    queue.data_type_size = data_type_size;
    queue.size = 0;

    queue.enqueue = enqueue;
    queue.dequeue = dequeue;

    return queue;
}

void queue_destruct(struct Queue *queue)
{
    struct QueueNode *node = queue->front;
    while(node)
        if(node->next) {
            queue->dequeue(queue);
            node = queue->front;   
        }
        else {
            queue->dequeue(queue);
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

void enqueue(struct Queue *queue, void *data)
{
    struct QueueNode *node = node_construct(data, queue->data_type_size);
    if(!node) return;

    if(queue->size)
        queue->back->next = node;
    else 
        queue->front = node;
    queue->back = node;

    queue->size = queue->size + 1;
}

void node_destruct(struct QueueNode *node, size_t data_type_size)
{
    memset(node->data, 0, data_type_size);
    free(node->data);
    node->data = NULL;

    memset(node, 0, sizeof (struct QueueNode));
    free(node);
    node = NULL;
}

void dequeue(struct Queue *queue)
{
    if(!queue->size) return;

    struct QueueNode *node = queue->front;

    queue->front = queue->front->next;
    if(!queue->front)
        queue->back = NULL;

    node_destruct(node, queue->data_type_size);

    queue->size = queue->size - 1;
}
