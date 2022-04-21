#include "red-black_tree.h"

struct RedBlackTreeNode {
    void* data;
    struct RedBlackTreeNode* left;
    struct RedBlackTreeNode* right;
    struct RedBlackTreeNode* parent;
    enum {RED, BLACK} color;
};

struct RedBlackTree {
    RedBlackTreeNode* root;
    size_t data_size;
    size_t size;
    int (*compare)(void* data, void* node_data);
};

RedBlackTree* red_black_tree_create(size_t data_size,
    int (*compare)(void* data, void* node_data));

void* red_black_tree_root(RedBlackTree* RedBlackT);
size_t red_black_tree_size(RedBlackTree* RedBlackT);

bool red_black_tree_insert(RedBlackTree* RBT, void* data);
bool red_black_tree_remove(RedBlackTree* RBT, void* data);

RedBlackTreeNode* red_black_tree_begin(RedBlackTree* RBT);
RedBlackTreeNode* red_black_tree_search(RedBlackTree* RBT, void* data);

void* red_black_tree_node_data(RedBlackTreeNode* node);
RedBlackTreeNode* red_black_tree_node_left(RedBlackTreeNode* node);
RedBlackTreeNode* red_black_tree_node_right(RedBlackTreeNode* node);
RedBlackTreeNode* red_black_tree_node_parent(RedBlackTreeNode* node);
int red_black_tree_node_color(RedBlackTreeNode* node);

RedBlackTree* red_black_tree_create(size_t data_size,
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

bool red_black_tree_insert(RedBlackTree* RBT, void* data)
{
    if(!RBT->size) {
        RBT->root = node_create(RBT->data_size);
        if(!RBT->root) {
            return false;
        }
        memcpy(RBT->root->data, data, RBT->data_size);
        RBT->root->parent = NULL;
        RBT->root->color = BLACK;
        RBT->size = RBT->size + 1;
        return false;
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
    node = node_create(RBT->data_size);
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

    RBT->size = RBT->size + 1;
    return true;
}

// void red_black_tree_remove(RedBlackTree* RBT, int data)
// {

// }

RedBlackTreeNode* red_black_tree_begin(RedBlackTree* RBT)
{
    return RBT->root;
}

RedBlackTreeNode* red_black_tree_search(RedBlackTree* RBT, void* data)
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


void* red_black_tree_node_data(RedBlackTreeNode* node)
{
    return node->data;
}

RedBlackTreeNode* red_black_tree_node_left(RedBlackTreeNode* node)
{
    return node->left;
}

RedBlackTreeNode* red_black_tree_node_right(RedBlackTreeNode* node)
{
    return node->right;
}

RedBlackTreeNode* red_black_tree_node_parent(RedBlackTreeNode* node)
{
    return node->parent;
}

int red_black_tree_node_color(RedBlackTreeNode* node)
{
    return node->color;
}
