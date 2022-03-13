#include "deque.h"

void push_front(struct Deque *deque, void *data);
void push_back(struct Deque *deque, void *data);
void pop_front(struct Deque *deque);
void pop_back(struct Deque *deque);

struct Deque deque_construct(size_t data_type_size)
{
    struct Deque deque;

    deque.front = NULL;
    deque.back = NULL;
    deque.data_type_size = data_type_size;
    deque.size = 0;

    deque.push_front = push_front;
    deque.push_back = push_back;
    deque.pop_front = pop_front;
    deque.pop_back = pop_back;

    return deque;
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

void push_front(struct Deque *deque, void *data)
{
    struct DequeNode *node = node_construct(data, deque->data_type_size);

    node->previous = NULL;
    if(deque->size) {
        deque->front->previous = node;
        node->next = deque->front;
    }
    else {
        deque->back = node;
        node->next = NULL;
    }
    deque->front = node;

    deque->size = deque->size + 1;
}

void push_back(struct Deque *deque, void *data)
{
    struct DequeNode *node = node_construct(data, deque->data_type_size);

    node->next = NULL;
    if(deque->size) {
        deque->back->next = node;
        node->previous = deque->back;
    }
    else {
        deque->front = node;
        node->previous = NULL;
    }
    
    deque->back = node;
    
    deque->size = deque->size + 1;
}

void node_destruct(struct DequeNode *node, size_t data_type_size)
{
    memset(node->data, 0, data_type_size);
    free(node->data);
    node->data = NULL;

    memset(node, 0, sizeof (struct DequeNode));
    free(node);
    node = NULL;
}

void pop_front(struct Deque *deque)
{
    if(!deque->size) return;

    struct DequeNode *node = deque->front;

    deque->front = deque->front->next;
    if(!deque->front)
        deque->back = NULL;

    node_destruct(node, deque->data_type_size);

    deque->size = deque->size - 1;
}

void pop_back(struct Deque *deque)
{
    if(!deque->size) return;

    struct DequeNode *node = deque->back;

    deque->back = deque->back->previous;
    deque->back->next = NULL;

    node_destruct(node, deque->data_type_size);

    deque->size = deque->size - 1;
}
