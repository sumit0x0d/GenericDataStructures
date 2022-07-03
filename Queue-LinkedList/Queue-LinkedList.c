#include "Node.h"

QueueLL* QueueLL_create(size_t data_size)
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

void QueueLL_destroy(QueueLL* Q)
{
    Node* node = Q->front;
    while(node) {
        if(node->next) {
            QueueLL_dequeue(Q);
            node = Q->front;   
        }
        else {
            QueueLL_dequeue(Q);
            break;
        }
    }
    free(Q);
    Q = NULL;
}

void* QueueLL_front(QueueLL* Q)
{
    return Q->front->data;
}

void* QueueLL_back(QueueLL* Q)
{
    return Q->back->data;
}

bool QueueLL_enqueue(QueueLL* Q, void* data)
{
    Node* node = Node_create(Q->data_size);
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

void QueueLL_dequeue(QueueLL* Q)
{
    Node* node = Q->front;
    Q->front = Q->front->next;
    if(!Q->front) {
        Q->back = NULL;
    }
    Node_destroy(node);
    Q->size = Q->size - 1;
}
