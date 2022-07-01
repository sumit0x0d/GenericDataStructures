#ifndef QueueLL_H
#define QueueLL_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueLL {
    struct Node* front;
    struct Node* back;
    size_t data_size;
    size_t size;
} QueueLL;

QueueLL* QueueLL_create(size_t data_size);
void QueueLL_destroy(QueueLL* Q);

void* QueueLL_front(QueueLL* Q);
void* QueueLL_back(QueueLL* Q);

bool QueueLL_enqueue(QueueLL* Q, void* data);
void QueueLL_dequeue(QueueLL* Q);

#endif
