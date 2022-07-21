#ifndef QueueLL_H
#define QueueLL_H

#include <stdbool.h>
#include <stddef.h>

typedef struct QueueLL QueueLL;

QueueLL* QueueLL_Create(size_t data_size);
void QueueLL_Destroy(QueueLL* Q);
size_t QueueLL_Size(QueueLL* Q);
bool QueueLL_Empty(QueueLL* Q);
void* QueueLL_Front(QueueLL* Q);
void* QueueLL_Back(QueueLL* Q);
bool QueueLL_Enqueue(QueueLL* Q, void* data);
void QueueLL_Dequeue(QueueLL* Q);
void QueueLL_Traverse(QueueLL* Q, void (*function)(void* data));

#endif
