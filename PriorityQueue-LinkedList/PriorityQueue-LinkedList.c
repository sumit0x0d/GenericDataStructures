#include "PriorityQueue-LinkedList.h"

PriorityQueueLL* PriorityQueueLL_create(size_t data_size);
void PriorityQueueLL_destroy(PriorityQueueLL* Q);

static PriorityQueueLLNode* PriorityQueueLLnode_create(size_t data_size);
static void PriorityQueueLLnode_destroy(PriorityQueueLLNode* Q);

int PriorityQueueLL_enqueue(PriorityQueueLL* Q, void* data, unsigned long priority);
void PriorityQueueLL_dequeue(PriorityQueueLL* Q);

void* PriorityQueueLL_front(PriorityQueueLL* Q);
void* PriorityQueueLL_back(PriorityQueueLL* Q);

PriorityQueueLL* PriorityQueueLL_create(size_t data_size)
{
    PriorityQueueLL* Q = malloc(sizeof (PriorityQueueLL));
    if(!Q) {
        return NULL;
    }
    Q->front = NULL;
    Q->back = NULL;
    Q->data_size = data_size;
    Q->size = 0;
    return Q;
}

void PriorityQueueLL_destroy(PriorityQueueLL* Q)
{
    PriorityQueueLLNode* node = Q->front;
    while(node) {
        if(node->next) {
            PriorityQueueLL_dequeue(Q);
            node = Q->front;   
        }
        else {
            PriorityQueueLL_dequeue(Q);
            break;
        }
    }
    free(Q);
    Q = NULL;
}

static PriorityQueueLLNode* PriorityQueueLLnode_create(size_t data_size)
{
    PriorityQueueLLNode* node = malloc(sizeof (PriorityQueueLLNode));
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

static void PriorityQueueLLnode_destroy(PriorityQueueLLNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

int PriorityQueueLL_enqueue(PriorityQueueLL* Q, void* data, unsigned long priority)
{
    PriorityQueueLLNode* node = PriorityQueueLLnode_create(Q->data_size);
    if(!node) {
        return 0;
    }
    memcpy(node->data, data, Q->data_size);
    node->priority = priority;
    if(Q->front) {
        Q->back->next = node;
    }
    else {
        Q->front = node;
    }
    Q->back = node;
    Q->size = Q->size + 1;
    return 1;
}

void PriorityQueueLL_dequeue(PriorityQueueLL* Q)
{
    PriorityQueueLLNode* node = Q->front;
    Q->front = Q->front->next;
    if(!Q->front) {
        Q->back = NULL;
    }
    PriorityQueueLLnode_destroy(node);
    Q->size = Q->size - 1;
}

void* PriorityQueueLL_front(PriorityQueueLL* Q)
{
    return Q->front->data;
}

void* PriorityQueueLL_back(PriorityQueueLL* Q)
{
    return Q->back->data;
}
