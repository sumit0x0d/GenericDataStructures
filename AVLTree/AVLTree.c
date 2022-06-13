#include "AVLTree.h"

typedef struct CircularQueue {
    AVLTreeNode* array;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
} CircularQueue;

static AVLTreeNode* node_create(size_t data_size);
static void node_destroy(AVLTreeNode* node);

static CircularQueue* CircularQueue_create(size_t capacity);
static void CircularQueue_enqueue(CircularQueue* CQ, AVLTreeNode* data);
static void* CircularQueue_dequeue(CircularQueue* CQ);

static size_t node_height(AVLTreeNode* node, CircularQueue *CQ);
static void node_balance_factor(AVLTreeNode* node, CircularQueue *CQ);
static AVLTreeNode* node_rotate_right(AVLTreeNode* node, AVLTreeNode* node_right);
static AVLTreeNode* node_rotate_left_right(AVLTreeNode* node, AVLTreeNode* node_left,
    AVLTreeNode* node_left_right);
static AVLTreeNode* node_rotate_left(AVLTreeNode* node, AVLTreeNode* node_left);
static AVLTreeNode* node_rotate_right_left(AVLTreeNode* node, AVLTreeNode* node_right,
    AVLTreeNode* node_right_left);
static void rebalance(AVLTree* AVLT, AVLTreeNode* node, CircularQueue* CQ);

static AVLTreeNode* node_predecessor(AVLTreeNode* node, AVLTreeNode* node_left);
static AVLTreeNode* node_successor(AVLTreeNode* node, AVLTreeNode* node_right);

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

void* AVLTree_root(AVLTree* AVLT)
{
    return AVLT->root->data;
}

static AVLTreeNode* node_create(size_t data_size)
{
    AVLTreeNode* node = (AVLTreeNode*)malloc(sizeof (AVLTreeNode));
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

static CircularQueue* CircularQueue_create(size_t capacity)
{
    CircularQueue* CQ = (CircularQueue*)malloc(sizeof (CircularQueue));
    if(!CQ) {
        return NULL;
    }
    CQ->array = (AVLTreeNode*)malloc(sizeof (AVLTreeNode) * capacity);
    if(!CQ->array) {
        free(CQ);
        return NULL;
    }
    CQ->front = 0;
    CQ->back = 0;
    CQ->capacity = capacity;
    CQ->size = 0;
    return CQ;
}

static void CircularQueue_enqueue(CircularQueue* CQ, AVLTreeNode* data)
{
    memcpy(CQ->array + CQ->back, data, sizeof (AVLTreeNode));
    CQ->back = (CQ->back + 1) % CQ->capacity;
    CQ->size = CQ->size + 1;
}

static void* CircularQueue_dequeue(CircularQueue* CQ)
{
    CQ->front = (CQ->front + 1) % CQ->capacity;
    CQ->size = CQ->size - 1;
    return CQ->array + CQ->front;
}

static size_t node_height(AVLTreeNode* node, CircularQueue *CQ)
{
    size_t height = 0;
    CircularQueue_enqueue(CQ, node);
    while(CQ->size) {
        size_t queue_size = CQ->size;
        while(queue_size) {
            node = (AVLTreeNode*)CircularQueue_dequeue(CQ);
            if(node->left) {
                CircularQueue_enqueue(CQ, node->left);
            }
            if(node->right) {
                CircularQueue_enqueue(CQ, node->right);
            }
            queue_size = queue_size - 1;
        }
        height = height + 1;
    }
    return height;
}

static void node_balance_factor(AVLTreeNode* node, CircularQueue *CQ)
{
    size_t node_left_height = 0;
    size_t node_right_height = 0;
    if(node->left) {
        node_left_height = node_height(node->left, CQ);
    }
    if(node->right) {
        node_right_height = node_height(node->right, CQ);
    }
    node->balance_factor = (int)(node_right_height - node_left_height);
}

static AVLTreeNode* node_rotate_right(AVLTreeNode* node, AVLTreeNode* node_left)
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

static AVLTreeNode* node_rotate_left_right(AVLTreeNode* node, AVLTreeNode* node_left,
    AVLTreeNode* node_left_right)
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

static AVLTreeNode* node_rotate_left(AVLTreeNode* node, AVLTreeNode* node_right)
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

static AVLTreeNode* node_rotate_right_left(AVLTreeNode* node, AVLTreeNode* node_right,
    AVLTreeNode* node_right_left)
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

static void rebalance(AVLTree* AVLT, AVLTreeNode* node, CircularQueue* CQ)
{
    while(node) {
        node_balance_factor(node, CQ);
        if(node->balance_factor == -2) {
            if(node->left->balance_factor == -1) {
                node = node_rotate_right(node, node->left);
                node_balance_factor(node, CQ);
                node_balance_factor(node->right, CQ);
                if(!node->parent) {
                    AVLT->root = node;
                    return;
                }
            }
            else if(node->left->balance_factor == 1) {
                node = node_rotate_left_right(node, node->left, node->left->right);
                node_balance_factor(node, CQ);
                if(!node->parent) {
                    AVLT->root = node;
                    return;
                }
            }
        }
        else if(node->balance_factor == 2) {
            if(node->right->balance_factor == 1) {
                node = node_rotate_left(node, node->right);
                node_balance_factor(node, CQ);
                node_balance_factor(node->left, CQ);
                if(!node->parent) {
                    AVLT->root = node;
                    return;
                }
            }
            else if(node->right->balance_factor == -1) {
                node = node_rotate_right_left(node, node->right, node->right->left);
                node_balance_factor(node, CQ);
                if(!node->parent) {
                    AVLT->root = node;
                    return;
                }
            }
        }
        node = node->parent;
    }
}

int AVLTree_insert(AVLTree* AVLT, void* data)
{
    if(!AVLT->root) {
        AVLT->root = node_create(AVLT->data_size);
        if(!AVLT->root) {
            return 0;
        }
        memcpy(AVLT->root->data, data, AVLT->data_size);
        AVLT->root->parent = NULL;
        AVLT->size = AVLT->size + 1;
        return 1;
    }
    AVLTreeNode* node = AVLT->root;
    AVLTreeNode* node_parent = NULL;
    int compare;
    while(node) {
        compare = AVLT->compare(data, node->data);
        if(!compare) {
            return 0;
        }
        node_parent = node;
        if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    CircularQueue *CQ = CircularQueue_create((AVLT->size + 2) / 2);
    if(!CQ) {
        return 0;
    }
    node = node_create(AVLT->data_size);
    if(!node) {
        return 0;
    }
    memcpy(node->data, data, AVLT->data_size);
    node->parent = node_parent;
    if(compare < 0) {
        node_parent->left = node;
    }
    else {
        node_parent->right = node;
    }
    rebalance(AVLT, node_parent, CQ);
    AVLT->size = AVLT->size + 1;
    return 1;
}

static AVLTreeNode* node_predecessor(AVLTreeNode* node, AVLTreeNode* node_left)
{
    AVLTreeNode* node_parent = node;
    free(node->data);
    node = node_left;
    while(node->right) {
        node = node->right;
    }
    node_parent->data = node->data;
    node_left = node->left;
    node_parent = node->parent;
    node_parent->right = node_left;
    if(node_left) {
        node_left->parent = node_parent;
    }
    free(node);
    node = NULL;
    return node_parent;
}

static AVLTreeNode* node_successor(AVLTreeNode* node, AVLTreeNode* node_right)
{
    AVLTreeNode* node_parent = node;
    free(node->data);
    node = node_right;
    while(node->left) {
        node = node->left;
    }
    node_parent->data = node->data;
    node_right = node->right;
    node_parent = node->parent;
    node_parent->left = node_right;
    if(node_right) {
        node_right->parent = node_parent;
    }
    free(node);
    node = NULL;
    return node_parent;
}

int AVLTree_remove(AVLTree* AVLT, void* data)
{
    AVLTreeNode* node = AVLT->root;
    AVLTreeNode* node_parent = NULL; 
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
        return 1;
    }
    CircularQueue *CQ = CircularQueue_create((AVLT->size + 2) / 2);
    if(!CQ) {
        return 0;
    }
    if(!node->left && !node->right) {
        if(node_parent->left == node) {
            node_parent->left = NULL;
        }
        else {
            node_parent->right = NULL;
        }
        node_destroy(node);
        rebalance(AVLT, node_parent, CQ);
    }
    else if(!node->left) {
        if(node_parent->right == node) {
            node_parent->right = node->right;
        }
        else {
            node_parent->left = node->right;
        }
        node_destroy(node);
        rebalance(AVLT, node_parent, CQ);
    }
    else if(!node->right) {
        if(node_parent->left == node) {
            node_parent->left = node->left;
        }
        else {
            node_parent->right = node->left;
        }
        node_destroy(node);
        rebalance(AVLT, node_parent, CQ);
    }
    else {
        if(AVLT->root->balance_factor < 0) {
            node = node_predecessor(node, node->left);
        }
        else {
            node = node_successor(node, node->right);
        }
        rebalance(AVLT, node, CQ);
    }
    AVLT->size = AVLT->size - 1;
    return 1;
}

AVLTreeNode* AVLTree_search(AVLTree* AVLT, void* data)
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
