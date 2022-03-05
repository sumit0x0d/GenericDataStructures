#include "queue.h"

void enqueue(struct Queue *queue, void *data, size_t data_type_size);
void dequeue(struct Queue *queue);

struct Queue queue_construct()
{
    struct Queue queue;

    queue.front = NULL;
    queue.back = NULL;
    queue.size = 0;

    queue.enqueue = enqueue;
    queue.dequeue = dequeue;

    return queue;
}

void queue_distruct(struct Queue *queue)
{
    struct LinkedListNode *node = queue->front;
    while(node) {
        if(node->next) {
            queue->dequeue(queue);
            node = queue->front;   
        }
        else {
            queue->dequeue(queue);
            break;
        }
    }
}

struct LinkedListNode *node_construct(void *data, size_t data_type_size)
{
    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }
    
    memcpy(node->data, data, data_type_size);
    
    node->data_type_size = data_type_size;

    return node;
}

void enqueue(struct Queue *queue, void *data, size_t data_type_size)
{
    struct LinkedListNode *node = node_construct(data, data_type_size);

    node->next = NULL;
    if(queue->size)
        queue->back->next = node;
    else 
        queue->front = node;
    queue->back = node;

    ++queue->size;
}

void node_distruct(struct LinkedListNode *node)
{
    memset(node->data, 0, node->data_type_size);
    free(node->data);
    node->data = NULL;

    memset(node, 0, sizeof(struct LinkedListNode));
    free(node);
    node = NULL;
}

void dequeue(struct Queue *queue)
{
    if(!queue->size) return;

    struct LinkedListNode *node = queue->front;

    queue->front = queue->front->next;
    if(!queue->front)
        queue->back = NULL;

    node_distruct(node);

    --queue->size;
}
