#include "queue.h"

void queue_print(QueueLinkedList *queue)
{
   if(!queue->size)
        return;
    QueueLinkedListNode *node = queue->front;
    printf("QueueLinkedList Linked List: ");
    while(node != queue->back) {
        printf("%c ", *(char *)node->data);
        node = node->next;
    }
    printf("%c\n", *(char *)node->data);
    printf("QueueLinkedList Linked List Size: %zu\n", queue->size);
}

