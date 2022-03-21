#include "queue.h"

extern void queue_linked_list_print(QueueLinkedList *Q);

#include <stdint.h>

int main()
{
    QueueLinkedList queue = queue_linked_list_construct();
    for(uint8_t i = 0; i < 127; i++) {
        queue_linked_list_enqueue(&queue, &i, sizeof i);
    }
    // int x = 97;  
    // queue.enqueue(&queue, &x, sizeof x);
    // for(int i=0; i < 128; i++)
    // queue.dequeue(&queue);

    queue_linked_list_print(&queue);
}
