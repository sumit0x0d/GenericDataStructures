#include "deque.h"

bool deque_push_front(struct Deque *D, void *data);
bool deque_push_back(struct Deque *D, void *data);
bool deque_pop_front(struct Deque *D);
bool deque_pop_back(struct Deque *D);

struct Deque deque_construct(size_t data_type_size)
{
    struct Deque D;

    D.front = NULL;
    D.back = NULL;
    D.data_type_size = data_type_size;
    D.size = 0;

    return D;
}

struct DequeNode *node_construct(size_t data_type_size)
{
    struct DequeNode *node = malloc(sizeof (struct DequeNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    return node;
}

bool deque_push_front(struct Deque *D, void *data)
{
    struct DequeNode *node = node_construct(D->data_type_size);
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

bool deque_push_back(struct Deque *D, void *data)
{
    struct DequeNode *node = node_construct(D->data_type_size);
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

void node_destruct(struct DequeNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool deque_pop_front(struct Deque *D)
{
    if(!D->size) return false;

    struct DequeNode *node = D->front;

    D->front = D->front->next;
    if(!D->front)
        D->back = NULL;

    node_destruct(node);

    D->size = D->size - 1;

    return true;
}

bool deque_pop_back(struct Deque *D)
{
    if(!D->size) return false;

    struct DequeNode *node = D->back;

    D->back = D->back->previous;
    if(D->back)
        D->back->next = NULL;

    node_destruct(node);

    D->size = D->size - 1;

    return true;
}
