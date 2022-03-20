#include "queue.h"

extern void queue_print(Queue *queue);

#include <stdint.h>

int main()
{
    Queue queue = queue_construct();
    for(uint8_t i = 0; i < 127; i++) {
        queue.enqueue(&queue, &i, sizeof i);
    }
    // int x = 97;  
    // queue.enqueue(&queue, &x, sizeof x);
    // for(int i=0; i < 128; i++)
    // queue.dequeue(&queue);

    queue_print(&queue);
}
