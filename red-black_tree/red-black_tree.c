#include "red-black_tree.h"

RedBlackTree* RedBlackTree_create(size_t data_size,
    int (*compare)(void* data, void* node_data));

void* RedBlackTree_root(RedBlackTree* RedBlackT);
size_t RedBlackTree_size(RedBlackTree* RedBlackT);

static RedBlackTreeNode* RedBlackTreeNode_rotate_right(RedBlackTreeNode* node);
static RedBlackTreeNode* RedBlackTreeNode_rotate_left_right(RedBlackTreeNode* node);
static RedBlackTreeNode* RedBlackTreeNode_rotate_left(RedBlackTreeNode* node);
static RedBlackTreeNode* RedBlackTreeNode_rotate_right_left(RedBlackTreeNode* node);
static void RedBlackTree_rebalance(RedBlackTree* RBT, RedBlackTreeNode* node);

bool RedBlackTree_insert(RedBlackTree* RBT, void* data);
bool RedBlackTree_remove(RedBlackTree* RBT, void* data);

RedBlackTreeNode* RedBlackTree_search(RedBlackTree* RBT, void* data);

RedBlackTree* RedBlackTree_create(size_t data_size,
    int (*compare)(void* data, void* node_data))
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

static RedBlackTreeNode* RedBlackTreeNode_create(size_t data_size)
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

static RedBlackTreeNode* RedBlackTreeNode_rotate_right(RedBlackTreeNode* node)
{
    RedBlackTreeNode* node_left = node->left;
    node->left = node_left->right;
    if(node->left) {
        node_left->right->parent = node;
    }
    node_left->parent = node->parent;
    if(node->parent) {
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

static RedBlackTreeNode* RedBlackTreeNode_rotate_left_right(RedBlackTreeNode* node)
{
    RedBlackTreeNode* node_left = node->left;
    RedBlackTreeNode* node_left_right = node_left->right;
    node_left->right = node_left_right->left;
    if(node_left_right->left) {
        node_left_right->left->parent = node_left;
    }
    node->left = node_left_right->right;
    if(node_left_right->right) {
        node_left_right->right->parent = node;
    }
    node_left->right = node_left_right->left;
    if(node_left->right) {
        node_left_right->left->parent = node_left;
    }
    node_left_right->left = node_left;
    node_left->parent = node_left_right;
    node_left_right->right = node;
    node_left_right->parent = node->parent;
    if(node->parent) {
        if(node_left_right->parent->left == node) {
            node_left_right->parent->left = node_left_right;
        }
        else {
            node_left_right->parent->right = node_left_right;
        }
    }
    return node_left_right;
}

static RedBlackTreeNode* RedBlackTreeNode_rotate_left(RedBlackTreeNode* node)
{
    RedBlackTreeNode* node_right = node->right;
    node->right = node_right->left;
    if(node->right) {
        node_right->left->parent = node;
    }
    node_right->parent = node->parent;
    if(node->parent) {
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

static RedBlackTreeNode* RedBlackTreeNode_rotate_right_left(RedBlackTreeNode* node)
{
    RedBlackTreeNode* node_right = node->right;
    RedBlackTreeNode* node_right_left = node_right->left;
    node_right->left = node_right_left->right;
    if(node_right_left->right) {
        node_right_left->right->parent = node_right;
    }
    node->right = node_right_left->left;
    if(node_right_left->left) {
        node_right_left->left->parent = node;
    }
    node_right->left = node_right_left->right;
    if(node_right->left) {
        node_right_left->right->parent = node_right;
    }
    node_right_left->right = node_right;
    node_right->parent = node_right_left;
    node_right_left->left = node;
    node_right_left->parent = node->parent;
    if(node->parent) {
        if(node_right_left->parent->left == node) {
            node_right_left->parent->left = node_right_left;
        }
        else {
            node_right_left->parent->right = node_right_left;
        }
    }
    return node_right_left;
}

static void RedBlackTree_rebalance(RedBlackTree* RBT, RedBlackTreeNode* node)
{
    while(node) {
        if(node->parent->left == node) {
            if(node->color == RED && (!node->parent->right || node->parent->right->color == BLACK)) {
                node = RedBlackTreeNode_rotate_left(node);
            }
            if(node->color == RED && (node->parent->right && node->parent->right->color == RED)) {
                node->parent->color = BLACK;
            }
        }
        else {
            if(node->color == RED && (!node->parent->left || node->parent->left->color == BLACK)) {
                node = RedBlackTreeNode_rotate_left(node);
                node = RedBlackTreeNode_rotate_right_left(node);
                node = RedBlackTreeNode_rotate_left_right(node);
                node = RedBlackTreeNode_rotate_right(node);
            }
            if(node->color == RED && (node->parent->left && node->parent->left->color == RED)) {
                node->parent->color = BLACK;
            }
        }
        RBT->root = node->parent;
    }
}

bool RedBlackTree_insert(RedBlackTree* RBT, void* data)
{
    if(!RBT->size) {
        RBT->root = RedBlackTreeNode_create(RBT->data_size);
        if(!RBT->root) {
            return false;
        }
        memcpy(RBT->root->data, data, RBT->data_size);
        RBT->root->parent = NULL;
        RBT->root->color = BLACK;
        RBT->size = RBT->size + 1;
        return true;
    }
    RedBlackTreeNode* node = RBT->root;
    RedBlackTreeNode* node_parent = NULL;
    int compare;
    while(node) {
        compare = RBT->compare(data, node->data);
        if(compare == 0) {
            return node;
        }
        node_parent = node;
        if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    node = RedBlackTreeNode_create(RBT->data_size);
    if(!node) {
        return false;
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
    RedBlackTree_rebalance(RBT, node_parent);
    RBT->size = RBT->size + 1;
    return true;
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
