#ifndef QueueLL_H
#define QueueLL_H

#include <stdbool.h>
#include <stddef.h>

typedef struct QueueLL QueueLL;

QueueLL* QueueLLCreate(size_t data_size);
void QueueLLDestroy(QueueLL* Q);
size_t QueueLLSize(QueueLL* Q);
bool QueueLLEmpty(QueueLL* Q);
void* QueueLLFront(QueueLL* Q);
void* QueueLLBack(QueueLL* Q);
bool QueueLLEnqueue(QueueLL* Q, void* data);
void QueueLLDequeue(QueueLL* Q);
void QueueLLTraverse(QueueLL* Q, void (*function)(void* data));

#endif
