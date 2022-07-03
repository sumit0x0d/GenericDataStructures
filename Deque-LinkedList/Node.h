#ifndef NODE_H
#define NODE_H

#include "Deque-LinkedList.h"

typedef struct Node {
    void* data;
    struct Node* previous;
    struct Node* next;
} Node;

static inline Node* Node_create(size_t data_size)
{
    Node* N = (Node*)malloc(sizeof (Node));
    if(!N) {
        return NULL;
    }
    N->data = malloc(data_size);
    if(!N->data) {
        free(N);
        return NULL;
    }
    return N;
}

static inline void Node_destroy(Node* N)
{
    free(N->data);
    N->data = NULL;
    free(N);
    N = NULL;
}

#endif
