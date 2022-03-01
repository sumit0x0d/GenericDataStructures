#include "deque-linked_list.h"

void push_front(struct Deque *deque, void *data, size_t data_type_size);
void push_back(struct Deque *deque, void *data, size_t data_type_size);
void pop_front(struct Deque *deque);
void pop_back(struct Deque *deque);

struct Deque *deque_construct()
{
    struct Deque *deque = malloc(sizeof(struct Deque));
    if(!deque) return;

    deque->front = NULL;
    deque->back = NULL;
    deque->size = 0;
    
    deque->push_front = push_front;
    deque->push_back = push_back;
    deque->pop_front = pop_front;
    deque->pop_back = pop_back;

    return deque;
}

struct LinkedListNode *node_construct(void *data, size_t data_type_size)
{
    struct LinkedListNode *node = malloc(sizeof (struct LinkedListNode));
    if(!node) return;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    memcpy(node->data, data, data_type_size);

    node->data_type_size = data_type_size;

    return node;
}

void push_front(struct Deque *deque, void *data, size_t data_type_size)
{
    struct LinkedListNode *node = node_construct(data, data_type_size);

    node->previous = NULL;
    if(deque->size) {
        deque->front->previous = node;
        node->next = deque->front;
    }
    else {
        node->next = NULL;
        deque->back = node;
    }
    deque->front = node;

    ++deque->size;
}

void push_back(struct Deque *deque, void *data, size_t data_type_size)
{
    struct LinkedListNode *node = node_construct(data, data_type_size);

    node->next = NULL;
    if(deque->size) {
        node->previous = deque->back;
        deque->back->next = node;
        deque->back = node;
    }
    else {
        node->previous = NULL;
        deque->front = node;
        deque->back = node;
    }

    ++deque->size;
}

void node_distruct(struct LinkedListNode *node)
{
    memset(node->data, 0, node->data_type_size);
    free(node->data);
    node->data = NULL;

    memset(node, 0, sizeof (struct LinkedListNode));
    free(node);
    node = NULL;
}

void pop_front(struct Deque *deque)
{
    if(!deque->size) return;

    struct LinkedListNode *node = deque->front;

    deque->front = deque->front->next;
    if(!deque->front)
        deque->back = NULL;

    node_distruct(node);

    --deque->size;
}

void pop_back(struct Deque *deque)
{
    if(!deque->size) return;

    struct LinkedListNode *node = deque->back;

    node->
}
