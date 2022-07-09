#include "AVLTree.h"
#include "CircularQueue.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct AVLTree {
    Node* root;
    size_t data_size;
    size_t size;
    int (*compare)(void* data1, void* data2);
};

AVLTree* AVLTree_create(size_t data_size, int (*compare)(void* data1, void* data2))
{
    AVLTree* AVLT = (AVLTree*)malloc(sizeof (AVLTree));
    if(!AVLT) {
        return NULL;
    }
    AVLT->root = NULL;
    AVLT->data_size = data_size;
    AVLT->size = 0;
    AVLT->compare = compare;
    return AVLT;
}

void AVLTree_destroy(AVLTree* AVLT)
{
    free(AVLT);
    AVLT = NULL;
}

size_t AVLTree_size(AVLTree* AVLT)
{
    return AVLT->size;
}

bool AVLTree_empty(AVLTree* AVLT)
{
    if(AVLT->size) {
        return false;
    }
    return true;
}

void* AVLTree_root(AVLTree* AVLT)
{
    return AVLT->root->data;
}

static size_t AVLTree_height_at(Node* node, CircularQueue *circular_queue)
{
    if(!node) {
        return 0;
    }
    size_t height = 0;
    CircularQueue_enqueue(circular_queue, node);
    while(circular_queue->size) {
        size_t queue_size = circular_queue->size;
        while(queue_size) {
            node = CircularQueue_dequeue(circular_queue);
            if(node->left) {
                CircularQueue_enqueue(circular_queue, node->left);
            }
            if(node->right) {
                CircularQueue_enqueue(circular_queue, node->right);
            }
            queue_size = queue_size - 1;
        }
        height = height + 1;
    }
    return height;
}

static void AVLTree_rebalance(AVLTree* AVLT, Node* node, CircularQueue* circular_queue)
{
    size_t node_left_height;
    size_t node_right_height;
    while(node) {
        node_left_height = AVLTree_height_at(node->left, circular_queue);
        node_right_height = AVLTree_height_at(node->right, circular_queue);
        node->balance_factor = (int)(node_right_height - node_left_height);
        if(node->balance_factor == -2) {
            if(node->left->balance_factor == -1) {
                node = Node_rotate_right(node, node->left);
                // node_balance_factor(node, circular_queue);
                // node_balance_factor(node->right, circular_queue);
                if(!node->parent) {
                    AVLT->root = node;
                    return;
                }
            }
            else if(node->left->balance_factor == 1) {
                node = Node_rotate_left_right(node, node->left, node->left->right);
                // node_balance_factor(node, circular_queue);
                if(!node->parent) {
                    AVLT->root = node;
                    return;
                }
            }
        }
        else if(node->balance_factor == 2) {
            if(node->right->balance_factor == 1) {
                node = Node_rotate_left(node, node->right);
                // node_balance_factor(node, circular_queue);
                // node_balance_factor(node->left, circular_queue);
                if(!node->parent) {
                    AVLT->root = node;
                    return;
                }
            }
            else if(node->right->balance_factor == -1) {
                node = Node_rotate_right_left(node, node->right, node->right->left);
                // node_balance_factor(node, circular_queue);
                if(!node->parent) {
                    AVLT->root = node;
                    return;
                }
            }
        }
        node = node->parent;
    }
}

void* AVLTree_search(AVLTree* AVLT, void* data)
{
    Node* node = AVLT->root;
    int compare;
    while(node) {
        compare = AVLT->compare(data, node->data);
        if(compare == 0) {
            return node;
        }
        else if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return NULL;
}

bool AVLTree_insert(AVLTree* AVLT, void* data)
{
    if(!AVLT->root) {
        AVLT->root = Node_create(AVLT->data_size);
        if(!AVLT->root) {
            return false;
        }
        memcpy(AVLT->root->data, data, AVLT->data_size);
        AVLT->root->parent = NULL;
        AVLT->size = AVLT->size + 1;
        return true;
    }
    Node* node = AVLT->root;
    Node* node_parent = NULL;
    int compare;
    while(node) {
        compare = AVLT->compare(data, node->data);
        if(!compare) {
            return false;
        }
        node_parent = node;
        if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    CircularQueue *circular_queue = CircularQueue_create((AVLT->size + 2) / 2);
    if(!circular_queue) {
        return false;
    }
    node = Node_create(AVLT->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, AVLT->data_size);
    node->parent = node_parent;
    if(compare < 0) {
        node_parent->left = node;
    }
    else {
        node_parent->right = node;
    }
    AVLTree_rebalance(AVLT, node_parent, circular_queue);
    AVLT->size = AVLT->size + 1;
    return true;
}

bool AVLTree_remove(AVLTree* AVLT, void* data)
{
    Node* node = AVLT->root;
    Node* node_parent = NULL; 
    int compare;
    while(node) {
        compare = AVLT->compare(data, node->data);
        if(!compare) {
            break;
        }
        node_parent = node;
        if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    if(!node) {   
        return true;
    }
    CircularQueue *circular_queue = CircularQueue_create((AVLT->size + 2) / 2);
    if(!circular_queue) {
        return false;
    }
    if(!node->left && !node->right) {
        if(node_parent->left == node) {
            node_parent->left = NULL;
        }
        else {
            node_parent->right = NULL;
        }
        Node_destroy(node);
        AVLTree_rebalance(AVLT, node_parent, circular_queue);
    }
    else if(!node->left) {
        if(node_parent->right == node) {
            node_parent->right = node->right;
        }
        else {
            node_parent->left = node->right;
        }
        Node_destroy(node);
        AVLTree_rebalance(AVLT, node_parent, circular_queue);
    }
    else if(!node->right) {
        if(node_parent->left == node) {
            node_parent->left = node->left;
        }
        else {
            node_parent->right = node->left;
        }
        Node_destroy(node);
        AVLTree_rebalance(AVLT, node_parent, circular_queue);
    }
    else {
        if(AVLT->root->balance_factor < 0) {
            node = Node_predecessor(node, node->left);
        }
        else {
            node = Node_successor(node, node->right);
        }
        AVLTree_rebalance(AVLT, node, circular_queue);
    }
    AVLT->size = AVLT->size - 1;
    return true;
}
