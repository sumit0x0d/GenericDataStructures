#include "avl_tree.h"

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

typedef struct QueueNode {
    AVLTreeNode *data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    struct QueueNode *front;
    struct QueueNode *back;
    size_t size;
} Queue;

AVLTree* avl_tree_create(size_t data_size, int (*compare)(void* data, void* node_data));
void avl_tree_destroy(AVLTree* AVLT);

void* avlt_tree_root(AVLTree* AVLT);
size_t avl_tree_size(AVLTree* AVLT);

static AVLTreeNode* node_create(size_t data_size);
static void node_destroy(AVLTreeNode* node);

static Queue* queue_create();
static bool queue_enqueue(Queue* Q, AVLTreeNode* data);
static bool queue_dequeue(Queue* Q);

static size_t node_height(AVLTreeNode* node);
static int node_balance_factor(AVLTreeNode* node);
static void node_rotate_right(AVLTreeNode* node);
static void node_rotate_left(AVLTreeNode* node);
static void node_rotate_right_left(AVLTreeNode* node);
static void node_rotate_left_right(AVLTreeNode* node);
static void node_rebalance(AVLTreeNode* node);

bool avl_tree_insert(AVLTree* AVLT, void* data);
bool avl_tree_remove(AVLTree* AVLT, void* data);

AVLTreeNode* avl_tree_search(AVLTree* AVLT, void* data);
AVLTreeNode* avl_tree_begin(AVLTree* AVLT);

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

static Queue* queue_create()
{
    Queue* Q = malloc(sizeof (Queue*));
    if(!Q) {
        return NULL;
    }
    Q->front = NULL;
    Q->back = NULL;
    Q->size = 0;
    return Q;
}

static bool queue_enqueue(Queue* Q, AVLTreeNode* data)
{
    QueueNode *node = malloc(sizeof (QueueNode));
    if(!node) {
        return false;
    }
    node->data = data;
    if(Q->front) {
        Q->back->next = node;
    }
    else {
        Q->front = node;
    }
    Q->back = node;
    Q->size = Q->size + 1;
    return true;
}

static bool queue_dequeue(Queue* Q)
{
    if(!Q->front) {
        return false;
    }
    QueueNode* node = Q->front;
    Q->front = Q->front->next;
    if(!Q->front) {
        Q->back = NULL;
    }
    free(node);
    node = NULL;
    Q->size = Q->size - 1;
    return true;
}

static size_t node_height(AVLTreeNode* node)
{
    size_t height = 0;
    Queue *Q = queue_create();
    queue_enqueue(Q, node);
    while(Q->size) {
        size_t queue_size = Q->size;
        while(queue_size) {
            node = Q->front->data;
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

static int node_balance_factor(AVLTreeNode* node)
{
    size_t node_left_height = 0;
    size_t node_right_height = 0;
    if(node->left) {
        node_left_height = node_height(node->left);
    }
    if(node->right) {
        node_right_height = node_height(node->right);
    }
    return (int)(node_right_height - node_left_height);
}

static void node_rotate_left(AVLTreeNode* node)
{
    AVLTreeNode* node_right = node->right;
    AVLTreeNode* node_right_left = node_right->left;
    node_right->left = node;
    node_right->parent = node->parent;
    if(node_right->parent) {
        if(node_right->parent->left == node) {
            node_right->parent->left = node_right;
        }
        else {
            node_right->parent->left = node_right;
        }
    }
    node->parent = node_right;
    node->right = node_right_left;
    if(node_right_left) {
        node_right_left->parent = node;
    }
    node->balance_factor = node_balance_factor(node);
    node_right->balance_factor = node_balance_factor(node_right);
}

static void node_rotate_right(AVLTreeNode* node)
{
    AVLTreeNode* node_left = node->left;
    AVLTreeNode* node_left_right = node_left->right;
    node_left->right = node;
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
    node->left = node_left_right;
    if(node_left_right) {
        node_left_right->parent = node;
    }
    node->balance_factor = node_balance_factor(node);
    node_left->balance_factor = node_balance_factor(node_left);
}


static void node_rotate_left_right(AVLTreeNode* node)
{
    AVLTreeNode* node_left = node->left;
    AVLTreeNode* node_left_right = node_left->right;
    node_left->right = node_left_right->left;
    if(node_left_right->left) {
        node_left_right->left->parent = node_left;
    }
    node->left = node_left_right->right;
    if(node_left_right->right) {
        node_left_right->right->parent = node;
    }
    node_left_right->left = node_left;
    node_left->parent = node_left_right;
    node_left_right->right = node;
    node_left_right->parent = node->parent;
    if(node->parent) {
        node->parent = node_left_right;
    }
    node_left_right->parent->left = node_left_right;
    node->balance_factor = node_balance_factor(node);
    node_left->balance_factor = node_balance_factor(node_left);
    node_left_right->balance_factor = node_balance_factor(node_left_right);
}

static void node_rotate_right_left(AVLTreeNode* node)
{
    AVLTreeNode* node_right = node->right;
    AVLTreeNode* node_right_left = node_right->left;
    node_right->left = node_right_left->right;
    if(node_right_left->right) {
        node_right_left->right->parent = node_right;
    }
    node->right = node_right_left->left;
    if(node_right_left->left) {
        node_right_left->left->parent = node;
    }
    node_right_left->right = node_right;
    node_right->parent = node_right_left;
    node_right_left->left = node;
    node_right_left->parent = node->parent;
    if(node->parent) {
        node->parent = node_right_left;
    }
    node_right_left->parent->right = node_right_left;
    node->balance_factor = node_balance_factor(node);
    node_right->balance_factor = node_balance_factor(node_right);
    node_right_left->balance_factor = node_balance_factor(node_right_left);
}

static void node_rebalance(AVLTreeNode* node)
{
    if(node->balance_factor == 2 && node->right->balance_factor == 1) {
        node_rotate_left(node);
        return;
    }
    if(node->balance_factor == -2 && node->left->balance_factor == -1) {
        node_rotate_right(node);
        return;
    }
    if(node->balance_factor == -2 && node->left->balance_factor == 1) {
        node_rotate_left_right(node);
        return;
    }
    if(node->balance_factor == 2 && node->right->balance_factor == -1) {
        node_rotate_right_left(node);
        return;
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
    while(node_parent) {
        node_parent->balance_factor = node_balance_factor(node_parent);
        if(node_parent->balance_factor == 2 || node_parent->balance_factor == -2) {
            node_rebalance(node_parent);
        }
        if(!node_parent->parent) {
            AVLT->root = node_parent;
        }
        node_parent = node_parent->parent;
    }
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
    if(!node->left && !node->right) {
        if(node_parent->left == node) {
            node_parent->left = NULL;
        }
        else {
            node_parent->right = NULL;
        }
        node_destroy(node);
        node_parent->balance_factor = node_balance_factor(node_parent);
    }
    else if(!node->left) {
        if(node_parent->right == node) {
            node_parent->right = node->right;
        }
        else {
            node_parent->left = node->right;
        }
        node_destroy(node);
        node_parent->balance_factor = node_balance_factor(node_parent);
    }
    else if(!node->right) {
        if(node_parent->left == node) {
            node_parent->left = node->left;
        }
        else {
            node_parent->right = node->left;
        }
        node_destroy(node);
        node_parent->balance_factor = node_balance_factor(node_parent);
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
        node_parent->balance_factor = node_balance_factor(node_inorder_successor_parent);
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
