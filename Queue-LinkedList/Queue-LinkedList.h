#ifndef QueueLL_H
#define QueueLL_H

#include <stdbool.h>
#include <stddef.h>

typedef struct QueueLL QueueLL;

QueueLL* QueueLL_create(size_t data_size);
void QueueLL_destroy(QueueLL* Q);
size_t QueueLL_size(QueueLL* Q);
bool QueueLL_empty(QueueLL* Q);
void* QueueLL_front(QueueLL* Q);
void* QueueLL_back(QueueLL* Q);
bool QueueLL_enqueue(QueueLL* Q, void* data);
void QueueLL_dequeue(QueueLL* Q);

#endif
