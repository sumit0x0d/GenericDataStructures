#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct Node {
    void* data;
    void* priority;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

static Node* Node_create(size_t data_size, size_t priority_size)
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
    node->left = NULL;
    node->right = NULL;
    return node;
}

// static void node_destroy(Node* node)
// {
    
// }

#endif
