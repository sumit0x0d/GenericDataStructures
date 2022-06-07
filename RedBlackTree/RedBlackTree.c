#include "RedBlackTree.h"

static RedBlackTreeNode* node_create(size_t data_size);
void node_destroy(RedBlackTree* RBT);

static RedBlackTreeNode* node_rotate_right(RedBlackTreeNode* node, RedBlackTreeNode* node_right);
static RedBlackTreeNode* node_rotate_left_right(RedBlackTreeNode* node,
    RedBlackTreeNode* node_left, RedBlackTreeNode* node_left_right);
static RedBlackTreeNode* node_rotate_left(RedBlackTreeNode* node, RedBlackTreeNode* node_left);
static RedBlackTreeNode* node_rotate_right_left(RedBlackTreeNode* node,
    RedBlackTreeNode* node_right, RedBlackTreeNode* node_right_left);
static void tree_rebalance(RedBlackTree* RBT, RedBlackTreeNode* node);

RedBlackTree* RedBlackTree_create(size_t data_size,
    int (*compare)(void* data1, void* data2))
{
    RedBlackTree* RBT = malloc(sizeof (RedBlackTree));
    if(!RBT) {
        return NULL;
    }
    RBT->root = NULL;
    RBT->size = 0;
    RBT->data_size = data_size;
    RBT->compare = compare;
    return RBT;
}

static RedBlackTreeNode* node_create(size_t data_size)
{
    RedBlackTreeNode* node = malloc(sizeof (RedBlackTreeNode));
    if(!node) {
        return NULL;
    }
    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }
    node->left = NULL;
    node->right = NULL;
    return node;
}

static RedBlackTreeNode* node_rotate_right(RedBlackTreeNode* node, RedBlackTreeNode* node_left)
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

static RedBlackTreeNode* node_rotate_left_right(RedBlackTreeNode* node,
    RedBlackTreeNode* node_left, RedBlackTreeNode* node_left_right)
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

static RedBlackTreeNode* node_rotate_left(RedBlackTreeNode* node,
    RedBlackTreeNode* node_right)
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

static RedBlackTreeNode* node_rotate_right_left(RedBlackTreeNode* node,
    RedBlackTreeNode* node_right, RedBlackTreeNode* node_right_left)
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

// void node_recolor(RedBlackTreeNode* node)
// {

// }

static void tree_rebalance(RedBlackTree* RBT, RedBlackTreeNode* node)
{
    while(node) {
        if(node->color == RED) {
            if(node->parent->left == node) {
                if(!node->parent->right || node->parent->right->color == BLACK) {
                    node = node_rotate_right(node, node->left);
                }
                else if(node->parent->right || node->parent->right->color == RED) {

                }
            }
        }
        if(node->parent->left == node) {
            if(node->color == RED && (!node->parent->right || node->parent->right->color == BLACK)) {
                
            }
            if(node->color == RED && (node->parent->right && node->parent->right->color == RED)) {
                node->parent->color = BLACK;
            }
        }
        else {
            if(node->color == RED && (!node->parent->left || node->parent->left->color == BLACK)) {
                node = node_rotate_left(node, node->right);
                node = node_rotate_right_left(node, node->right, node->right->left);
                node = node_rotate_left_right(node, node->left, node->left->right);
                node = node_rotate_right(node, node->left);
            }
            if(node->color == RED && (node->parent->left && node->parent->left->color == RED)) {
                node->parent->color = BLACK;
            }
        }
        RBT->root = node->parent;
    }
}

int RedBlackTree_insert(RedBlackTree* RBT, void* data)
{
    if(!RBT->size) {
        RBT->root = node_create(RBT->data_size);
        if(!RBT->root) {
            return 0;
        }
        memcpy(RBT->root->data, data, RBT->data_size);
        RBT->root->parent = NULL;
        RBT->root->color = BLACK;
        RBT->size = RBT->size + 1;
        return 1;
    }
    RedBlackTreeNode* node = RBT->root;
    RedBlackTreeNode* node_parent = NULL;
    int compare;
    while(node) {
        compare = RBT->compare(data, node->data);
        if(compare == 0) {
            return 1;
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
        return 0;
    }
    memcpy(node->data, data, RBT->data_size);
    node->parent = node_parent;
    node->color = RED;
    if(node->data < node_parent->data) {
        node_parent->left = node;
    }
    else {
        node_parent->right = node;
    }
    tree_rebalance(RBT, node_parent);
    RBT->size = RBT->size + 1;
    return 1;
}

// void RedBlackTree_remove(RedBlackTree* RBT, int data)
// {

// }

RedBlackTreeNode* RedBlackTree_search(RedBlackTree* RBT, void* data)
{
    RedBlackTreeNode* node = RBT->root;
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
