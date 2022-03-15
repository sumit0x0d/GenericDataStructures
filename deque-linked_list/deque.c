#include "deque.h"

void push_front(struct Deque *D, void *data);
void push_back(struct Deque *D, void *data);
void pop_front(struct Deque *D);
void pop_back(struct Deque *D);

struct Deque deque_construct(size_t data_type_size)
{
    struct Deque D;

    D.front = NULL;
    D.back = NULL;
    D.data_type_size = data_type_size;
    D.size = 0;

    D.push_front = push_front;
    D.push_back = push_back;
    D.pop_front = pop_front;
    D.pop_back = pop_back;

    return D;
}

struct DequeNode *node_construct(void *data, size_t data_type_size)
{
    struct DequeNode *node = malloc(sizeof (struct DequeNode));
    if(!node) return;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    memcpy(node->data, data, data_type_size);

    return node;
}

void push_front(struct Deque *D, void *data)
{
    struct DequeNode *node = node_construct(data, D->data_type_size);
    if(!node) return;

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
}

void push_back(struct Deque *D, void *data)
{
    struct DequeNode *node = node_construct(data, D->data_type_size);
    if(!node) return;

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
}

void node_destruct(struct DequeNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

void pop_front(struct Deque *D)
{
    if(!D->size) return;

    struct DequeNode *node = D->front;

    D->front = D->front->next;
    if(!D->front)
        D->back = NULL;

    node_destruct(node);

    D->size = D->size - 1;
}

void pop_back(struct Deque *D)
{
    if(!D->size) return;

    struct DequeNode *node = D->back;

    D->back = D->back->previous;
    if(D->back)
        D->back->next = NULL;

    node_destruct(node);

    D->size = D->size - 1;
}
