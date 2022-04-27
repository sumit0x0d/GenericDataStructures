#include "queue-linked_list.h"

struct QueueLLNode {
    void* data;
    struct QueueLLNode* next;
};

struct QueueLL {
    QueueLLNode* front;
    QueueLLNode* back;
    size_t data_size;
    size_t size;
};

QueueLL* queue_linked_list_create(size_t data_size);
void queue_linked_list_destroy(QueueLL* Q);

void* queue_linked_list_front(QueueLL* Q);
void* queue_linked_list_back(QueueLL* Q);
size_t queue_linked_list_size(QueueLL* Q);

static QueueLLNode* node_create(size_t data_size);
static void node_destroy(QueueLLNode* Q);

bool queue_linked_list_enqueue(QueueLL* Q, void* data);
bool queue_linked_list_dequeue(QueueLL* Q);

QueueLL* queue_linked_list_create(size_t data_size)
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

void queue_linked_list_destroy(QueueLL* Q)
{
    QueueLLNode* node = Q->front;
    while(node) {
        if(node->next) {
            queue_linked_list_dequeue(Q);
            node = Q->front;   
        }
        else {
            queue_linked_list_dequeue(Q);
            break;
        }
    }
    free(Q);
    Q = NULL;
}

void* queue_linked_list_front(QueueLL* Q)
{
    if(!Q->front) {
        return NULL;
    }
    return Q->front->data;
}

void* queue_linked_list_back(QueueLL* Q)
{
    if(!Q->back) {
        return NULL;
    }
    return Q->back->data;
}

size_t queue_linked_list_size(QueueLL* Q)
{
    return Q->size;
}

static QueueLLNode* node_create(size_t data_size)
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

static void node_destroy(QueueLLNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

bool queue_linked_list_enqueue(QueueLL* Q, void* data)
{
    QueueLLNode* node = node_create(Q->data_size);
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

bool queue_linked_list_dequeue(QueueLL* Q)
{
    if(!Q->front) {
        return false;
    }
    QueueLLNode* node = Q->front;
    Q->front = Q->front->next;
    if(!Q->front) {
        Q->back = NULL;
    }
    node_destroy(node);
    Q->size = Q->size - 1;
    return true;
}
