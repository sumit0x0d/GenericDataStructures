#include "RedBlackTree.h"

typedef struct Node {
    void* data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    // int color; // RED = 0 BLACK = 1
    enum {RED, BLAC} color;
} Node;

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

static Node* node_create(size_t data_size)
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
    node->left = NULL;
    node->right = NULL;
    return node;
}

static Node* node_rotate_right(Node* node, Node* node_left)
{
    node->left = node_left->right;
    if(node->left) {
        node->left->parent = node;
    }
    node_left->parent = node->parent;
    if(node_left->parent) {
        if(node_left->parent->left == node) {
            node_left->parent->left = node_left;
        }
        else {
            node_left->parent->right = node_left;
        }
    }
    node->parent = node_left;
    node_left->right = node;
    return node_left;
}

static Node* node_rotate_left_right(Node* node,
    Node* node_left, Node* node_left_right)
{
    node_left->right = node_left_right->left;
    if(node_left->right) {
        node_left->right->parent = node_left;
    }
    node->left = node_left_right->right;
    if(node->left) {
        node->left->parent = node;
    }
    node_left_right->left = node_left;
    node_left->parent = node_left_right;
    node_left_right->parent = node->parent;
    if(node_left_right->parent) {
        if(node_left_right->parent->left == node) {
            node_left_right->parent->left = node_left_right;
        }
        else {
            node_left_right->parent->right = node_left_right;
        }
    }
    node->parent = node_left_right;
    node_left_right->right = node;
    return node_left_right;
}

static Node* node_rotate_left(Node* node, Node* node_right)
{
    node->right = node_right->left;
    if(node->right) {
        node->right->parent = node;
    }
    node_right->parent = node->parent;
    if(node_right->parent) {
        if(node_right->parent->left == node) {
            node_right->parent->left = node_right;
        }
        else {
            node_right->parent->right = node_right;
        }
    }
    node->parent = node_right;
    node_right->left = node;
    return node_right;
}

static Node* node_rotate_right_left(Node* node,
    Node* node_right, Node* node_right_left)
{
    node_right->left = node_right_left->right;
    if(node_right->left) {
        node_right->left->parent = node_right;
    }
    node->right = node_right_left->left;
    if(node->right) {
        node->right->parent = node;
    }
    node_right_left->right = node_right;
    node_right->parent = node_right_left;
    node_right_left->parent = node->parent;
    if(node_right_left->parent) {
        if(node_right_left->parent->left == node) {
            node_right_left->parent->left = node_right_left;
        }
        else {
            node_right_left->parent->right = node_right_left;
        }
    }
    node->parent = node_right_left;
    node_right_left->left = node;
    return node_right_left;
}

// void node_recolor(Node* node)
// {

// }

static void rebalance(RedBlackTree* RBT, Node* node)
{
    while(node) {
        if(node->color == 0) {
            if(node->parent->left == node) {
                if(!node->parent->right || node->parent->right->color == 1) {
                    node = node_rotate_right(node, node->left);
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
                node = node_rotate_left(node, node->right);
                node = node_rotate_right_left(node, node->right, node->right->left);
                node = node_rotate_left_right(node, node->left, node->left->right);
                node = node_rotate_right(node, node->left);
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
        RBT->root = node_create(RBT->data_size);
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
    node = node_create(RBT->data_size);
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
    rebalance(RBT, node_parent);
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
