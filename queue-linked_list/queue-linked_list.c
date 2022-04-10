#include "queue-linked_list.h"

typedef struct QueueLinkedListNode {
    void *data;
    struct QueueLinkedListNode *next;
} QueueLinkedListNode;

typedef struct QueueLinkedList {
    QueueLinkedListNode *front;
    QueueLinkedListNode *back;
    size_t data_size;
    size_t size;
} QueueLinkedList;

QueueLinkedList *queue_linked_list_create(size_t data_size);
void queue_linked_list_destroy(QueueLinkedList *Q);

void *queue_linked_list_front(QueueLinkedList *Q);
void *queue_linked_list_back(QueueLinkedList *Q);
size_t queue_linked_list_size(QueueLinkedList *Q);

static QueueLinkedListNode *node_create(size_t data_size);
static void node_destroy(QueueLinkedListNode *Q);

bool queue_linked_list_enqueue(QueueLinkedList *Q, void *data);
bool queue_linked_list_dequeue(QueueLinkedList *Q);

QueueLinkedList *queue_linked_list_create(size_t data_size)
{
    QueueLinkedList *Q = malloc(sizeof (QueueLinkedList));
    if(!Q) return NULL;

    Q->front = NULL;
    Q->back = NULL;
    Q->data_size = data_size;
    Q->size = 0;

    return Q;
}

void queue_linked_list_destroy(QueueLinkedList *Q)
{
    QueueLinkedListNode *node = Q->front;
    while(node)
        if(node->next) {
            queue_linked_list_dequeue(Q);
            node = Q->front;   
        }
        else {
            queue_linked_list_dequeue(Q);
            break;
        }
    
    free(Q);
    Q = NULL;
}

void *queue_linked_list_front(QueueLinkedList *Q)
{
    if(!Q->front) return NULL;

    return Q->front->data;
}

void *queue_linked_list_back(QueueLinkedList *Q)
{
    if(!Q->back) return NULL;
    
    return Q->back->data;
}

size_t queue_linked_list_size(QueueLinkedList *Q)
{
    return Q->size;
}

static QueueLinkedListNode *node_create(size_t data_size)
{
    QueueLinkedListNode *node = malloc(sizeof (QueueLinkedListNode));
    if(!node) return NULL;

    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    node->next = NULL;

    return node;
}

static void node_destroy(QueueLinkedListNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool queue_linked_list_enqueue(QueueLinkedList *Q, void *data)
{
    QueueLinkedListNode *node = node_create(Q->data_size);
    if(!node) return false;

    memcpy(node->data, data, Q->data_size);

    if(Q->size)
        Q->back->next = node;
    else 
        Q->front = node;
    Q->back = node;

    Q->size = Q->size + 1;

    return true;
}

bool queue_linked_list_dequeue(QueueLinkedList *Q)
{
    if(!Q->front) return false;

    QueueLinkedListNode *node = Q->front;

    Q->front = Q->front->next;
    if(!Q->front)
        Q->back = NULL;

    node_destroy(node);

    Q->size = Q->size - 1;

    return true;
}
