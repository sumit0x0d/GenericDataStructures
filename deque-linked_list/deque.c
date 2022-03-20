#include "deque.h"

bool deque_push_front(Deque *D, void *data);
bool deque_push_back(Deque *D, void *data);
bool deque_pop_front(Deque *D);
bool deque_pop_back(Deque *D);

Deque deque_construct(size_t data_type_size)
{
    Deque D;

    D.front = NULL;
    D.back = NULL;
    D.data_type_size = data_type_size;
    D.size = 0;

    return D;
}

DequeNode *node_construct(size_t data_type_size)
{
    DequeNode *node = malloc(sizeof (DequeNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    return node;
}

bool deque_push_front(Deque *D, void *data)
{
    DequeNode *node = node_construct(D->data_type_size);
    if(!node) return false;

    memcpy(node->data, data, D->data_type_size);

    node->previous = NULL;
    if(D->size) {
        D->front->previous = node;
        node->next = D->front;
    }
    else {
        D->back = node;
        node->next = NULL;
    }
    D->front = node;

    D->size = D->size + 1;

    return true;
}

bool deque_push_back(Deque *D, void *data)
{
    DequeNode *node = node_construct(D->data_type_size);
    if(!node) return false; 

    memcpy(node->data, data, D->data_type_size);

    node->next = NULL;
    if(D->size) {
        D->back->next = node;
        node->previous = D->back;
    }
    else {
        D->front = node;
        node->previous = NULL;
    }
    D->back = node;
    
    D->size = D->size + 1;

    return true;
}

void node_destruct(DequeNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool deque_pop_front(Deque *D)
{
    if(!D->size) return false;

    DequeNode *node = D->front;

    D->front = D->front->next;
    if(!D->front)
        D->back = NULL;

    node_destruct(node);

    D->size = D->size - 1;

    return true;
}

bool deque_pop_back(Deque *D)
{
    if(!D->size) return false;

    DequeNode *node = D->back;

    D->back = D->back->previous;
    if(D->back)
        D->back->next = NULL;

    node_destruct(node);

    D->size = D->size - 1;

    return true;
}
