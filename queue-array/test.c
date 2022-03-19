#include "queue.h"

extern void queue_print(struct Queue *queue);

int main()
{
    struct Queue queue = queue_construct(sizeof (int), 10);
    int i = 10, y = 30;
    queue_enqueue(&queue, &i);
    queue_enqueue(&queue, &y);
    queue_print(&queue);
    return 0;
}
