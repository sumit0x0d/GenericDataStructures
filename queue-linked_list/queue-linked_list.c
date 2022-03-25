#include "queue-linked_list.h"

QueueLinkedList queue_linked_list_construct();
void queue_linked_list_destruct(QueueLinkedList *Q);

QueueLinkedListNode *queue_linked_list_front(QueueLinkedList *Q);
QueueLinkedListNode *queue_linked_list_back(QueueLinkedList *Q);
size_t queue_linked_list_size(QueueLinkedList *Q);

static QueueLinkedListNode *node_construct(size_t data_type_size);
static void node_destruct(QueueLinkedListNode *Q);

bool queue_linked_list_enqueue(QueueLinkedList *Q, void *data, int data_type, size_t data_type_size);
bool queue_linked_list_dequeue(QueueLinkedList *Q);

QueueLinkedList queue_linked_list_construct()
{
    QueueLinkedList Q;

    Q.front = NULL;
    Q.back = NULL;
    Q.size = 0;

    return Q;
}

void queue_linked_list_destruct(QueueLinkedList *Q)
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

static QueueLinkedListNode *node_construct(size_t data_type_size)
{
    QueueLinkedListNode *node = malloc(sizeof (QueueLinkedListNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    node->next = NULL;

    return node;
}

static void node_destruct(QueueLinkedListNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool queue_linked_list_enqueue(QueueLinkedList *Q, void *data, int data_type, size_t data_type_size)
{
    QueueLinkedListNode *node = node_construct(data_type_size);
    if(!node) return false;

    memcpy(node->data, data, data_type_size);

    node->data_type = data_type;

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

    node_destruct(node);

    Q->size = Q->size - 1;

    return true;
}
