#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct Node {
    void* data;
    void* priority;
    struct Node* next;
} Node;

static Node* Node_Create(size_t data_size, size_t priority_size)
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

static void Node_Destroy(Node* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

#endif
