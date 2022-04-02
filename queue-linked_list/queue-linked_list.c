#include "queue-linked_list.h"

QueueLinkedList queue_linked_list_create();
void queue_linked_list_destroy(QueueLinkedList *Q);

QueueLinkedListNode *queue_linked_list_front(QueueLinkedList *Q);
QueueLinkedListNode *queue_linked_list_back(QueueLinkedList *Q);
size_t queue_linked_list_size(QueueLinkedList *Q);

static QueueLinkedListNode *node_create(size_t data_size);
static void node_destroy(QueueLinkedListNode *Q);

bool queue_linked_list_enqueue(QueueLinkedList *Q, void *data, size_t data_size);
bool queue_linked_list_dequeue(QueueLinkedList *Q);

QueueLinkedList queue_linked_list_create()
{
    QueueLinkedList Q;

    Q.front = NULL;
    Q.back = NULL;
    Q.size = 0;

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
}

QueueLinkedListNode *queue_linked_list_front(QueueLinkedList *Q)
{
    return Q->front;
}

QueueLinkedListNode *queue_linked_list_back(QueueLinkedList *Q)
{
    return Q->back;
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

bool queue_linked_list_enqueue(QueueLinkedList *Q, void *data, size_t data_size)
{
    QueueLinkedListNode *node = node_create(data_size);
    if(!node) return false;

    memcpy(node->data, data, data_size);

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
    if(!Q->size) return false;

    QueueLinkedListNode *node = Q->front;

    Q->front = Q->front->next;
    if(!Q->front)
        Q->back = NULL;

    node_destroy(node);

    Q->size = Q->size - 1;

    return true;
}
