#include "queue.h"

void queue_print(struct Queue *queue)
{
   if(!queue->size)
        return;
    struct QueueNode *node = queue->front;
    printf("Queue Linked List: ");
    while(node != queue->back) {
        printf("%c ", *(char *)node->data);
        node = node->next;
    }
    printf("%c\n", *(char *)node->data);
    printf("Queue Linked List Size: %zu\n", queue->size);
}
