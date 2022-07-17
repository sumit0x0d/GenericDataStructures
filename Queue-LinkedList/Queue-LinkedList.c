#include "Queue-LinkedList.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct QueueLL {
    Node* front;
    Node* back;
    size_t data_size;
    size_t size;
};

QueueLL* QueueLLCreate(size_t data_size)
{
    QueueLL* Q = (QueueLL*)malloc(sizeof (QueueLL));
    if(!Q) {
        return NULL;
    }
    Q->front = NULL;
    Q->back = NULL;
    Q->data_size = data_size;
    Q->size = 0;
    return Q;
}

void QueueLLDestroy(QueueLL* Q)
{
    Node* node = Q->front;
    while(node) {
        if(node->next) {
            QueueLLDequeue(Q);
            node = Q->front;   
        }
        else {
            QueueLLDequeue(Q);
            break;
        }
    }
    free(Q);
    Q = NULL;
}

size_t QueueLLSize(QueueLL* Q)
{
    return Q->size;
}

bool QueueLLEmpty(QueueLL* Q)
{
    if(Q->size) {
        return false;
    }
    return true;
}

void* QueueLLFront(QueueLL* Q)
{
    return Q->front->data;
}

void* QueueLLBack(QueueLL* Q)
{
    return Q->back->data;
}

bool QueueLLEnqueue(QueueLL* Q, void* data)
{
    Node* node = NodeCreate(Q->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, Q->data_size);
    if(Q->front) {
        Q->back->next = node;
    }
    else {
        Q->front = node;
    }
    Q->back = node;
    Q->size = Q->size + 1;
    return true;
}

void QueueLLDequeue(QueueLL* Q)
{
    Node* node = Q->front;
    Q->front = Q->front->next;
    if(!Q->front) {
        Q->back = NULL;
    }
    NodeDestroy(node);
    Q->size = Q->size - 1;
}

void QueueLLTraverse(QueueLL* Q, void (*function)(void* data))
{
    Node* node = Q->front;
    while(node) {
        function(node->data);
        node = node->next;
    }
}
