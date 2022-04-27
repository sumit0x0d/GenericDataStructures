#include "avl_tree.h"

#include <stdio.h>

struct AVLTreeNode {
    void* data;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
    struct AVLTreeNode* parent;
    int balance_factor;
};

struct AVLTree {
    AVLTreeNode* root;
    size_t data_size;
    size_t size;
    int (*compare)(void* data, void* node_data);
};

typedef struct Queue {
    AVLTreeNode* array;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
} Queue;

AVLTree* avl_tree_create(size_t data_size, int (*compare)(void* data, void* node_data));
void avl_tree_destroy(AVLTree* AVLT);

void* avlt_tree_root(AVLTree* AVLT);
size_t avl_tree_size(AVLTree* AVLT);

static AVLTreeNode* node_create(size_t data_size);
static void node_destroy(AVLTreeNode* node);

static Queue* queue_create(size_t capacity);
static inline AVLTreeNode* queue_front(Queue* Q);
static void queue_enqueue(Queue* Q, AVLTreeNode* data);
static void queue_dequeue(Queue* Q);

static size_t avl_subtree_height(AVLTreeNode* node, Queue *Q);
static void node_balance_factor(AVLTreeNode* node, Queue *Q);
static void avl_subtree_rotate_right(AVLTree* AVLT, AVLTreeNode* node);
static void avl_subtree_rotate_left_right(AVLTree* AVLT, AVLTreeNode* node);
static void avl_subtree_rotate_left(AVLTree* AVLT, AVLTreeNode* node);
static void avl_subtree_rotate_right_left(AVLTree* AVLT, AVLTreeNode* node);
static void avl_tree_rebalance(AVLTree* AVLT, AVLTreeNode* node, Queue* Q);

bool avl_tree_insert(AVLTree* AVLT, void* data);
bool avl_tree_remove(AVLTree* AVLT, void* data);

AVLTreeNode* avl_tree_begin(AVLTree* AVLT);
AVLTreeNode* avl_tree_search(AVLTree* AVLT, void* data);

void* avl_tree_node_data(AVLTreeNode* node);
AVLTreeNode* avl_tree_node_left(AVLTreeNode* node);
AVLTreeNode* avl_tree_node_right(AVLTreeNode* node);
AVLTreeNode* avl_tree_node_parent(AVLTreeNode* node);
int avl_tree_node_balance_factor(AVLTreeNode* node);

AVLTree* avl_tree_create(size_t data_size, int (*compare)(void* data, void* node_data))
{
    AVLTree* AVLT = malloc(sizeof (AVLTree));
    if(!AVLT) {
        return NULL;
    }
    AVLT->root = NULL;
    AVLT->data_size = data_size;
    AVLT->size = 0;
    AVLT->compare = compare;
    return AVLT;
}

void avl_tree_destroy(AVLTree* AVLT)
{
    free(AVLT);
    AVLT = NULL;
}

void* avlt_tree_root(AVLTree* AVLT)
{
    if(!AVLT->root) {
        return NULL;
    }
    return AVLT->root->data;
}

size_t avl_tree_size(AVLTree* AVLT)
{
    return AVLT->size;
}

static AVLTreeNode* node_create(size_t data_size)
{
    AVLTreeNode* node = malloc(sizeof (AVLTreeNode));
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
    node->balance_factor = 0;
    return node;
}

static void node_destroy(AVLTreeNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

static Queue* queue_create(size_t capacity)
{
    Queue* Q = malloc(sizeof (Queue));
    if(!Q) {
        return NULL;
    }
    Q->array = malloc(sizeof (AVLTreeNode) * capacity);
    if(!Q->array) {
        free(Q);
        Q = NULL;
        return NULL;
    }
    Q->front = 0;
    Q->back = 0;
    Q->capacity = capacity;
    Q->size = 0;
    return Q;
}

static inline AVLTreeNode* queue_front(Queue* Q)
{
    return Q->array + Q->front;
}

static void queue_enqueue(Queue* Q, AVLTreeNode* data)
{
    memcpy(Q->array + Q->back, data, sizeof (AVLTreeNode));
    Q->back = (Q->back + 1) % Q->capacity;
    Q->size = Q->size + 1;
}

static void queue_dequeue(Queue* Q)
{
    Q->front = (Q->front + 1) % Q->capacity;
    Q->size = Q->size - 1;
}

static size_t avl_subtree_height(AVLTreeNode* node, Queue *Q)
{
    size_t height = 0;
    queue_enqueue(Q, node);
    while(Q->size) {
        size_t queue_size = Q->size;
        while(queue_size) {
            node = queue_front(Q);
            queue_dequeue(Q);
            if(node->left) {
                queue_enqueue(Q, node->left);
            }
            if(node->right) {
                queue_enqueue(Q, node->right);
            }
            queue_size = queue_size - 1;
        }
        height = height + 1;
    }
    return height;
}

static void node_balance_factor(AVLTreeNode* node, Queue *Q)
{
    size_t avl_subtree_height_left = 0;
    size_t avl_subtree_height_right = 0;
    if(node->left) {
        avl_subtree_height_left = avl_subtree_height(node->left, Q);
    }
    if(node->right) {
        avl_subtree_height_right = avl_subtree_height(node->right, Q);
    }
    node->balance_factor = (int)(avl_subtree_height_right - avl_subtree_height_left);
}

static void avl_subtree_rotate_right(AVLTree* AVLT, AVLTreeNode* node)
{
    AVLTreeNode* node_left = node->left;
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
    else {
        AVLT->root = node_left;
    }
    node->parent = node_left;
    node_left->right = node;
}

static void avl_subtree_rotate_left_right(AVLTree* AVLT, AVLTreeNode* node)
{
    AVLTreeNode* node_left = node->left;
    AVLTreeNode* node_left_right = node_left->right;
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
    else {
        AVLT->root = node_left_right;
    }
    node->parent = node_left_right;
    node_left_right->right = node;
}

static void avl_subtree_rotate_left(AVLTree* AVLT, AVLTreeNode* node)
{
    AVLTreeNode* node_right = node->right;
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
    else {
        AVLT->root = node_right;
    }
    node->parent = node_right;
    node_right->left = node;
}

static void avl_subtree_rotate_right_left(AVLTree* AVLT, AVLTreeNode* node)
{
    AVLTreeNode* node_right = node->right;
    AVLTreeNode* node_right_left = node_right->left;
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
    else {
        AVLT->root = node_right_left;
    }
    node->parent = node_right_left;
    node_right_left->left = node;
}

static void avl_tree_rebalance(AVLTree* AVLT, AVLTreeNode* node, Queue* Q)
{
    while(node) {
        node_balance_factor(node, Q);
        if(node->balance_factor == -2) {
            if(node->left->balance_factor == -1) {
                avl_subtree_rotate_right(AVLT, node);
                node_balance_factor(node, Q);
            }
            else if(node->left->balance_factor == 1) {
                avl_subtree_rotate_left_right(AVLT, node);
                node_balance_factor(node, Q);
            }
        }
        else if(node->balance_factor == 2) {
            if(node->right->balance_factor == 1) {
                avl_subtree_rotate_left(AVLT, node);
                node_balance_factor(node, Q);
            }
            else if(node->right->balance_factor == -1) {
                avl_subtree_rotate_right_left(AVLT, node);
                node_balance_factor(node, Q);
            }
        }
        node = node->parent;
    }
}

bool avl_tree_insert(AVLTree* AVLT, void* data)
{
    if(!AVLT->root) {
        AVLT->root = node_create(AVLT->data_size);
        if(!AVLT->root) {
            return false;
        }
        memcpy(AVLT->root->data, data, AVLT->data_size);
        AVLT->root->parent = NULL;
        AVLT->size = AVLT->size + 1;
        return true;
    }
    AVLTreeNode* node = AVLT->root;
    AVLTreeNode* node_parent = NULL;
    int compare;
    while(node) {
        compare = AVLT->compare(data, node->data);
        if(compare == 0) {
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
    Queue *Q = queue_create((AVLT->size + 2)/2);
    if(!Q) {
        return false;
    }
    node = node_create(AVLT->data_size);
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
    avl_tree_rebalance(AVLT, node_parent, Q);
    AVLT->size = AVLT->size + 1;
    return true;
}

bool avl_tree_remove(AVLTree* AVLT, void* data)
{
    if(!AVLT->root) {
        return false;
    }
    AVLTreeNode* node = AVLT->root;
    AVLTreeNode* node_parent = NULL; 
    int compare;
    while(node) {
        compare = AVLT->compare(data, node->data);
        if(compare == 0) {
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
        return false;
    }
    Queue *Q = queue_create((AVLT->size + 1)/2);
    if(!Q) {
        return false;
    }
    if(!node->left && !node->right) {
        if(node_parent->left == node) {
            node_parent->left = NULL;
        }
        else {
            node_parent->right = NULL;
        }
        node_destroy(node);
        avl_tree_rebalance(AVLT, node_parent, Q);
    }
    else if(!node->left) {
        if(node_parent->right == node) {
            node_parent->right = node->right;
        }
        else {
            node_parent->left = node->right;
        }
        node_destroy(node);
        avl_tree_rebalance(AVLT, node_parent, Q);
    }
    else if(!node->right) {
        if(node_parent->left == node) {
            node_parent->left = node->left;
        }
        else {
            node_parent->right = node->left;
        }
        node_destroy(node);
        avl_tree_rebalance(AVLT, node_parent, Q);
    }
    else {
        AVLTreeNode* node_inorder_successor = node->right;
        AVLTreeNode* node_inorder_successor_parent = node;
        while(node_inorder_successor->left) {
            node_inorder_successor_parent = node_inorder_successor;
            node_inorder_successor = node_inorder_successor->left;
        }
        if(node_inorder_successor_parent == node) {
            node_inorder_successor_parent->right = node_inorder_successor->right;
        }
        else {
            node_inorder_successor_parent->left = node_inorder_successor->right;
        }
        memcpy(node->data, node_inorder_successor->data, AVLT->data_size);
        node_destroy(node_inorder_successor);
        avl_tree_rebalance(AVLT, node_inorder_successor_parent, Q);
    }
    AVLT->size = AVLT->size - 1;
    return true;
}

AVLTreeNode* avl_tree_begin(AVLTree* AVLT)
{
    return AVLT->root;
}

AVLTreeNode* avl_tree_search(AVLTree* AVLT, void* data)
{
    AVLTreeNode* node = AVLT->root;
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

void* avl_tree_node_data(AVLTreeNode* node)
{
    return node->data;
}

AVLTreeNode* avl_tree_node_left(AVLTreeNode* node)
{
    return node->left;
}

AVLTreeNode* avl_tree_node_right(AVLTreeNode* node)
{
    return node->right;
}

AVLTreeNode* avl_tree_node_parent(AVLTreeNode* node)
{
    return node->parent;
}

int avl_tree_node_balance_factor(AVLTreeNode* node)
{
    return node->balance_factor;
}
