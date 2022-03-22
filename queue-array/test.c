#include "queue-array.h"

extern void queue_array_print(Queue *Q);

int main()
{
    Queue queue = queue_array_construct(sizeof (int), 10);
    int i = 10, y = 30, z = 40;
    queue_array_enqueue(&queue, &i);
    queue_array_enqueue(&queue, &z);
    queue_array_enqueue(&queue, &y);
    queue_array_dequeue(&queue);
    queue_array_print(&queue);
    return 0;
}
