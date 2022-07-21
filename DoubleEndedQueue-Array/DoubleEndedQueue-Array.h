#ifndef DOUBLE_ENDED_QUEUE_ARRAY_H
#define DOUBLE_ENDED_QUEUE_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct DoubleEndedQueueA DoubleEndedQueueA;

DoubleEndedQueueA* DoubleEndedQueueA_Create(size_t data_size, size_t capacity);
bool DoubleEndedQueueA_ChangeCapacity(DoubleEndedQueueA* DEQ, size_t capacity);
void DoubleEndedQueueA_Destroy(DoubleEndedQueueA* DEQ);
size_t DoubleEndedQueueA_Size(DoubleEndedQueueA* DEQ);
bool DoubleEndedQueueA_Empty(DoubleEndedQueueA* DEQ);
bool DoubleEndedQueueA_Full(DoubleEndedQueueA* DEQ);
void* DoubleEndedQueueA_Front(DoubleEndedQueueA* DEQ);
void* DoubleEndedQueueA_Back(DoubleEndedQueueA* DEQ);
void DoubleEndedQueueA_PushFront(DoubleEndedQueueA* DEQ, void* data);
void DoubleEndedQueueA_PushBack(DoubleEndedQueueA* DEQ, void* data);
void DoubleEndedQueueA_PopFront(DoubleEndedQueueA* DEQ);
void DoubleEndedQueueA_PopBack(DoubleEndedQueueA* DEQ);

#endif
