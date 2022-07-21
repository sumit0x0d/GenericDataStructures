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

QueueLL* QueueLL_Create(size_t data_size)
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

void QueueLL_Destroy(QueueLL* Q)
{
    Node* node = Q->front;
    while(node) {
        if(node->next) {
            QueueLL_Dequeue(Q);
            node = Q->front;   
        }
        else {
            QueueLL_Dequeue(Q);
            break;
        }
    }
    free(Q);
    Q = NULL;
}

size_t QueueLL_Size(QueueLL* Q)
{
    return Q->size;
}

bool QueueLL_Empty(QueueLL* Q)
{
    if(Q->size) {
        return false;
    }
    return true;
}

void* QueueLL_Front(QueueLL* Q)
{
    return Q->front->data;
}

void* QueueLL_Back(QueueLL* Q)
{
    return Q->back->data;
}

bool QueueLL_Enqueue(QueueLL* Q, void* data)
{
    Node* node = Node_Create(Q->data_size);
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

void QueueLL_Dequeue(QueueLL* Q)
{
    Node* node = Q->front;
    Q->front = Q->front->next;
    if(!Q->front) {
        Q->back = NULL;
    }
    Node_Destroy(node);
    Q->size = Q->size - 1;
}

void QueueLL_Traverse(QueueLL* Q, void (*function)(void* data))
{
    Node* node = Q->front;
    while(node) {
        function(node->data);
        node = node->next;
    }
}
