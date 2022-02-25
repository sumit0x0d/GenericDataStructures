#ifndef QUEUE_PRINT_H
#define QUEUE_PRINT_H

#include "queue-linked_list.h"

void queue_print(struct Queue *queue)
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

#endif
