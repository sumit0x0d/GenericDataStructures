#include "Node.h"

RedBlackTree* RedBlackTree_create(size_t data_size,
    int (*compare)(void* data1, void* data2))
{
    RedBlackTree* RBT = (RedBlackTree*)malloc(sizeof (RedBlackTree));
    if(!RBT) {
        return NULL;
    }
    RBT->root = NULL;
    RBT->size = 0;
    RBT->data_size = data_size;
    RBT->compare = compare;
    return RBT;
}

// void node_recolor(Node* node)
// {

// }

static void RedBlackTree_rebalance(RedBlackTree* RBT, Node* node)
{
    while(node) {
        if(node->color == 0) {
            if(node->parent->left == node) {
                if(!node->parent->right || node->parent->right->color == 1) {
                    node = Node_rotate_right(node, node->left);
                }
                else if(node->parent->right || node->parent->right->color == 0) {

                }
            }
        }
        if(node->parent->left == node) {
            if(node->color == 0 && (!node->parent->right || node->parent->right->color == 1)) {
                
            }
            if(node->color == 0 && (node->parent->right && node->parent->right->color == 0)) {
                node->parent->color = 1;
            }
        }
        else {
            if(node->color == 0 && (!node->parent->left || node->parent->left->color == 1)) {
                node = Node_rotate_left(node, node->right);
                node = Node_rotate_right_left(node, node->right, node->right->left);
                node = Node_rotate_left_right(node, node->left, node->left->right);
                node = Node_rotate_right(node, node->left);
            }
            if(node->color == 0 && (node->parent->left && node->parent->left->color == 0)) {
                node->parent->color = 1;
            }
        }
        RBT->root = node->parent;
    }
}

bool RedBlackTree_insert(RedBlackTree* RBT, void* data)
{
    if(!RBT->size) {
        RBT->root = Node_create(RBT->data_size);
        if(!RBT->root) {
            return false;
        }
        memcpy(RBT->root->data, data, RBT->data_size);
        RBT->root->parent = NULL;
        RBT->root->color = 1;
        RBT->size = RBT->size + 1;
        return true;
    }
    Node* node = RBT->root;
    Node* node_parent = NULL;
    int compare;
    while(node) {
        compare = RBT->compare(data, node->data);
        if(compare == 0) {
            return true;
        }
        node_parent = node;
        if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    node = Node_create(RBT->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, RBT->data_size);
    node->parent = node_parent;
    node->color = 0;
    if(node->data < node_parent->data) {
        node_parent->left = node;
    }
    else {
        node_parent->right = node;
    }
    RedBlackTree_rebalance(RBT, node_parent);
    RBT->size = RBT->size + 1;
    return true;
}

// void RedBlackTree_remove(RedBlackTree* RBT, int data)
// {

// }

void* RedBlackTree_search(RedBlackTree* RBT, void* data)
{
    Node* node = RBT->root;
    int compare;
    while(node) {
        compare = RBT->compare(data, node->data);
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

void* RedBlackTree_root(RedBlackTree* RBT)
{
    return RBT->root->data;
}
