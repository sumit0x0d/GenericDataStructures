// #include "queue-array.h"
#include "queue-linked_list.h"
// #include "deque-array.h"
// #include "deque-linked_list.h"

#include <time.h>

int main()
{
    srand(time(0));
    // char random;
    struct Queue *queue = queue_construct();
    for(char i = 0; i < 127; i++) {
        // random = rand() % 100;
        queue_enqueue(queue, &i, sizeof i);
    }
    int x = 97;  
    queue_enqueue(queue, &x, sizeof x);
    // queue_enqueue(queue, &y, sizeof y);
    // int z = *(int *)queue->front->data;
    // for(int i = 0; i< 126; i++)
    //     queue_dequeue(queue);
    // queue_dequeue(queue);
    queue_print(queue);
}
