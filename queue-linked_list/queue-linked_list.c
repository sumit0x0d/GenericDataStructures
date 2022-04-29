#include "queue-linked_list.h"

QueueLL* QueueLL_create(size_t data_size);
void QueueLL_destroy(QueueLL* Q);

static QueueLLNode* QueueLLnode_create(size_t data_size);
static void QueueLLnode_destroy(QueueLLNode* Q);

bool QueueLL_enqueue(QueueLL* Q, void* data);
bool QueueLL_dequeue(QueueLL* Q);

QueueLL* QueueLL_create(size_t data_size)
{
    QueueLL* Q = malloc(sizeof (QueueLL));
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
    QueueLLNode* node = Q->front;
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

static QueueLLNode* QueueLLnode_create(size_t data_size)
{
    QueueLLNode* node = malloc(sizeof (QueueLLNode));
    if(!node) {
        return NULL;
    }
    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }
    node->next = NULL;
    return node;
}

static void QueueLLnode_destroy(QueueLLNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

bool QueueLL_enqueue(QueueLL* Q, void* data)
{
    QueueLLNode* node = QueueLLnode_create(Q->data_size);
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

bool QueueLL_dequeue(QueueLL* Q)
{
    if(!Q->front) {
        return false;
    }
    QueueLLNode* node = Q->front;
    Q->front = Q->front->next;
    if(!Q->front) {
        Q->back = NULL;
    }
    QueueLLnode_destroy(node);
    Q->size = Q->size - 1;
    return true;
}
