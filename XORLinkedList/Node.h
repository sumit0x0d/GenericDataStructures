#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct Node {
    void* data;
    struct Node* XOR;
} Node;

static Node* NodeCreate(size_t data_size)
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

static void NodeDestroy(Node* N)
{
    free(N->data);
    N->data = NULL;
    free(N);
    N = NULL;
}

#endif
