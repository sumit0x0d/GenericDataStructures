#include "PriorityQueue-LinkedList.h"

typedef struct Node {
    void* data;
    void* priority;
    struct Node* next;
} Node;

PriorityQueueLL* PriorityQueueLL_create(size_t data_size)
{
    PriorityQueueLL* PQ = (PriorityQueueLL*)malloc(sizeof (PriorityQueueLL));
    if(!PQ) {
        return NULL;
    }
    PQ->front = NULL;
    PQ->back = NULL;
    PQ->data_size = data_size;
    PQ->size = 0;
    return PQ;
}

void PriorityQueueLL_destroy(PriorityQueueLL* PQ)
{
    Node* node = PQ->front;
    while(node) {
        if(node->next) {
            PriorityQueueLL_dequeue(PQ);
            node = PQ->front;   
        }
        else {
            PriorityQueueLL_dequeue(PQ);
            break;
        }
    }
    free(PQ);
    PQ = NULL;
}

static Node* node_create(size_t data_size, size_t priority_size)
{
    Node* node = (Node*)malloc(sizeof (Node));
    if(!node) {
        return NULL;
    }
    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        return NULL;
    }
    node->priority = malloc(priority_size);
    if(!node->priority) {
        free(node->data);
        free(node);
        return NULL;
    }
    return node;
}

static void node_destroy(Node* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

void* PriorityQueueLL_front(PriorityQueueLL* PQ)
{
    return PQ->front->data;
}

void* PriorityQueueLL_back(PriorityQueueLL* PQ)
{
    return PQ->back->data;
}

bool PriorityQueueLL_enqueue(PriorityQueueLL* PQ, void* data, void* priority)
{
    Node* node = node_create(PQ->data_size, PQ->priority_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, PQ->data_size);
    memcpy(node->priority, priority, PQ->priority_size);
    node->next = NULL;
    if(PQ->front) {
        PQ->back->next = node;
    }
    else {
        PQ->front = node;
    }
    PQ->back = node;
    PQ->size = PQ->size + 1;
    return true;
}

void PriorityQueueLL_dequeue(PriorityQueueLL* PQ)
{
    Node* node = PQ->front;
    PQ->front = PQ->front->next;
    if(!PQ->front) {
        PQ->back = NULL;
    }
    node_destroy(node);
    PQ->size = PQ->size - 1;
}
