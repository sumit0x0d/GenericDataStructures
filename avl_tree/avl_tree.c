#include "avl_tree.h"

#include <stdio.h>

typedef struct CircularQueue {
    AVLTreeNode* array;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
} CircularQueue;

AVLTree* AVLTree_create(size_t data_size, int (*compare)(void* data, void* node_data));
void AVLTree_destroy(AVLTree* AVLT);

static AVLTreeNode* AVLTreeNode_create(size_t data_size);
static void AVLTreeNode_destroy(AVLTreeNode* node);

static CircularQueue* CircularQueue_create(size_t capacity);
static inline void CircularQueue_enqueue(CircularQueue* CQ, AVLTreeNode* data);
static inline void CircularQueue_dequeue(CircularQueue* CQ);

static size_t AVLTreeNode_height(AVLTreeNode* node, CircularQueue *CQ);
static void AVLTreeNode_balance_factor(AVLTreeNode* node, CircularQueue *CQ);
static AVLTreeNode* AVLTreeNode_rotate_right(AVLTreeNode* node);
static AVLTreeNode* AVLTreeNode_rotate_left_right(AVLTreeNode* node);
static AVLTreeNode* AVLTreeNode_rotate_left(AVLTreeNode* node);
static AVLTreeNode* AVLTreeNode_rotate_right_left(AVLTreeNode* node);
static void AVLTree_rebalance(AVLTree* AVLT, AVLTreeNode* node, CircularQueue* CQ);

AVLTreeNode* AVLTreeNode_inorder_predecessor(AVLTreeNode* node);
AVLTreeNode* AVLTreeNode_inorder_successor(AVLTreeNode* node);

bool AVLTree_insert(AVLTree* AVLT, void* data);
bool AVLTree_remove(AVLTree* AVLT, void* data);

AVLTreeNode* AVLTree_search(AVLTree* AVLT, void* data);

AVLTree* AVLTree_create(size_t data_size, int (*compare)(void* data, void* node_data))
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

void AVLTree_destroy(AVLTree* AVLT)
{
    free(AVLT);
    AVLT = NULL;
}

static AVLTreeNode* AVLTreeNode_create(size_t data_size)
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

static void AVLTreeNode_destroy(AVLTreeNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

static CircularQueue* CircularQueue_create(size_t capacity)
{
    CircularQueue* CQ = malloc(sizeof (CircularQueue));
    if(!CQ) {
        return NULL;
    }
    CQ->array = malloc(sizeof (AVLTreeNode) * capacity);
    if(!CQ->array) {
        free(CQ);
        CQ = NULL;
        return NULL;
    }
    CQ->front = 0;
    CQ->back = 0;
    CQ->capacity = capacity;
    CQ->size = 0;
    return CQ;
}

static inline void CircularQueue_enqueue(CircularQueue* CQ, AVLTreeNode* data)
{
    memcpy(&CQ->array[CQ->back], data, sizeof (AVLTreeNode));
    CQ->back = (CQ->back + 1) % CQ->capacity;
    CQ->size = CQ->size + 1;
}

static inline void CircularQueue_dequeue(CircularQueue* CQ)
{
    CQ->front = (CQ->front + 1) % CQ->capacity;
    CQ->size = CQ->size - 1;
}

static size_t AVLTreeNode_height(AVLTreeNode* node, CircularQueue *CQ)
{
    size_t height = 0;
    CircularQueue_enqueue(CQ, node);
    while(CQ->size) {
        size_t queue_size = CQ->size;
        while(queue_size) {
            node = &CQ->array[CQ->front];
            CircularQueue_dequeue(CQ);
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

static void AVLTreeNode_balance_factor(AVLTreeNode* node, CircularQueue *CQ)
{
    size_t height_left = 0;
    size_t height_right = 0;
    if(node->left) {
        height_left = AVLTreeNode_height(node->left, CQ);
    }
    if(node->right) {
        height_right = AVLTreeNode_height(node->right, CQ);
    }
    node->balance_factor = (int)(height_right - height_left);
}

static AVLTreeNode* AVLTreeNode_rotate_right(AVLTreeNode* node)
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
    node->parent = node_left;
    node_left->right = node;
    return node_left;
}

static AVLTreeNode* AVLTreeNode_rotate_left_right(AVLTreeNode* node)
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
    node->parent = node_left_right;
    node_left_right->right = node;
    return node_left_right;
}

static AVLTreeNode* AVLTreeNode_rotate_left(AVLTreeNode* node)
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
    node->parent = node_right;
    node_right->left = node;
    return node_right;
}

static AVLTreeNode* AVLTreeNode_rotate_right_left(AVLTreeNode* node)
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
    node->parent = node_right_left;
    node_right_left->left = node;
    return node_right_left;
}

static void AVLTree_rebalance(AVLTree* AVLT, AVLTreeNode* node, CircularQueue* CQ)
{
    while(node) {
        AVLTreeNode_balance_factor(node, CQ);
        if(node->balance_factor == -2) {
            if(node->left->balance_factor == -1) {
                node = AVLTreeNode_rotate_right(node);
                AVLTreeNode_balance_factor(node, CQ);
                AVLTreeNode_balance_factor(node->right, CQ);
                if(!node->parent) {
                    AVLT->root = node;
                    return;
                }
            }
            else if(node->left->balance_factor == 1) {
                node = AVLTreeNode_rotate_left_right(node);
                AVLTreeNode_balance_factor(node, CQ);
                if(!node->parent) {
                    AVLT->root = node;
                    return;
                }
            }
        }
        else if(node->balance_factor == 2) {
            if(node->right->balance_factor == 1) {
                node = AVLTreeNode_rotate_left(node);
                AVLTreeNode_balance_factor(node, CQ);
                AVLTreeNode_balance_factor(node->left, CQ);
                if(!node->parent) {
                    AVLT->root = node;
                    return;
                }
            }
            else if(node->right->balance_factor == -1) {
                node = AVLTreeNode_rotate_right_left(node);
                AVLTreeNode_balance_factor(node, CQ);
                if(!node->parent) {
                    AVLT->root = node;
                    return;
                }
            }
        }
        node = node->parent;
    }
}

bool AVLTree_insert(AVLTree* AVLT, void* data)
{
    if(!AVLT->root) {
        AVLT->root = AVLTreeNode_create(AVLT->data_size);
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
    CircularQueue *CQ = CircularQueue_create((AVLT->size + 2)/2);
    if(!CQ) {
        return false;
    }
    node = AVLTreeNode_create(AVLT->data_size);
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
    AVLTree_rebalance(AVLT, node_parent, CQ);
    AVLT->size = AVLT->size + 1;
    return true;
}

AVLTreeNode* AVLTreeNode_inorder_predecessor(AVLTreeNode* node)
{
    AVLTreeNode* pointer = node->left;
    while(pointer->right) {
        pointer = pointer->right;
    }
    return pointer;
}

AVLTreeNode* AVLTreeNode_inorder_successor(AVLTreeNode* node)
{
    AVLTreeNode* pointer = node->right;
    while(pointer->left) {
        pointer = pointer->left;
    }
    return pointer;
}

bool AVLTree_remove(AVLTree* AVLT, void* data)
{
    if(!AVLT->root) {
        return false;
    }
    AVLTreeNode* pointer = AVLT->root;
    AVLTreeNode* pointer_parent = NULL; 
    int compare;
    while(pointer) {
        compare = AVLT->compare(data, pointer->data);
        if(compare == 0) {
            break;
        }
        pointer_parent = pointer;
        if(compare < 0) {
            pointer = pointer->left;
        }
        else {
            pointer = pointer->right;
        }
    }
    if(!pointer) {   
        return false;
    }
    CircularQueue *CQ = CircularQueue_create((AVLT->size + 2)/2);
    if(!CQ) {
        return false;
    }
    if(!pointer->left && !pointer->right) {
        if(pointer_parent->left == pointer) {
            pointer_parent->left = NULL;
        }
        else {
            pointer_parent->right = NULL;
        }
        AVLTreeNode_destroy(pointer);
        AVLTree_rebalance(AVLT, pointer_parent, CQ);
    }
    else if(!pointer->left) {
        if(pointer_parent->right == pointer) {
            pointer_parent->right = pointer->right;
        }
        else {
            pointer_parent->left = pointer->right;
        }
        AVLTreeNode_destroy(pointer);
        AVLTree_rebalance(AVLT, pointer_parent, CQ);
    }
    else if(!pointer->right) {
        if(pointer_parent->left == pointer) {
            pointer_parent->left = pointer->left;
        }
        else {
            pointer_parent->right = pointer->left;
        }
        AVLTreeNode_destroy(pointer);
        AVLTree_rebalance(AVLT, pointer_parent, CQ);
    }
    else {
        if(AVLT->root->balance_factor < 0) {
            AVLTreeNode* inorder_predecessor = AVLTreeNode_inorder_predecessor(pointer);
            AVLTreeNode* inorder_predecessor_parent = inorder_predecessor->parent;
            free(pointer->data);
            pointer->data = inorder_predecessor->data;
            inorder_predecessor_parent->left = inorder_predecessor->right;
            if(inorder_predecessor_parent->left) {
                inorder_predecessor_parent->left->parent = inorder_predecessor_parent;
            }
            AVLTreeNode_destroy(inorder_predecessor);
            AVLTree_rebalance(AVLT, inorder_predecessor_parent, CQ);
        }
        else {
            AVLTreeNode* inorder_successor = AVLTreeNode_inorder_successor(pointer);
            AVLTreeNode* inorder_successor_parent = inorder_successor->parent;
            free(pointer->data);
            pointer->data = inorder_successor->data;
            inorder_successor_parent->left = inorder_successor->right;
            if(inorder_successor_parent->left) {
                inorder_successor_parent->left->parent = inorder_successor_parent;
            }
            AVLTreeNode_destroy(inorder_successor);
            AVLTree_rebalance(AVLT, inorder_successor_parent, CQ);
        }
    }
    AVLT->size = AVLT->size - 1;
    return true;
}

AVLTreeNode* AVLTree_search(AVLTree* AVLT, void* data)
{
    AVLTreeNode* pointer = AVLT->root;
    int compare;
    while(pointer) {
        compare = AVLT->compare(data, pointer->data);
        if(compare == 0) {
            return pointer;
        }
        else if(compare < 0) {
            pointer = pointer->left;
        }
        else {
            pointer = pointer->right;
        }
    }
    return NULL;
}
