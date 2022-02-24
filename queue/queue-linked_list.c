#include "queue-linked_list.h"

#include <string.h>

void print(struct Queue *queue);
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

void stack_distruct(struct Queue *queue)
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

void print(struct Queue *queue)
{
   if(!queue->size)
        return;
    struct LinkedListNode *node = queue->front;
    printf("Queue Linked List: ");
    while(node != queue->back) {
        printf("%c ", *(char *)node->data);
        node = node->next;
    }
    printf("%c\n", *(char *)node->data);
    printf("Queue Linked List Size: %zu\n", queue->size);
}

void enqueue(struct Queue *queue, void *data, size_t data_type_size)
{
    assert(queue);
    assert(data);
    assert(data_type_size);

    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    if(!node) return;

    node->data = malloc(data_type_size);
    memcpy(node->data, data, data_type_size);
    node->data_type_size = data_type_size;

    node->next = NULL;
    if(queue->size)
        queue->back->next = node;
    else 
        queue->front = node;

    queue->back = node;
    queue->size++;
}

void dequeue(struct Queue *queue)
{
    assert(queue);
    if(!queue->size) return;

    struct LinkedListNode *node = queue->front;

    queue->front = queue->front->next;
    if(!queue->front)
        queue->back = NULL;

    memset(node->data, 0, node->data_type_size);
    free(node->data);
    node->data = NULL;

    memset(node, 0, sizeof(struct LinkedListNode));
    free(node);
    node = NULL;

    queue->size--;
}
