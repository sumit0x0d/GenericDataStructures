#include "RedBlackTree.h"
#include "CircularQueue.h"
#include "Stack.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct RedBlackTree {
    Node* root;
    size_t data_size;
    size_t size;
    int (*compare)(void* data1, void* data2);
};

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

// void RedBlackTree_destroy(RedBlackTree* RBT)
// {

// }

size_t RedBlackTree_size(RedBlackTree* RBT)
{
    return RBT->size;
}

bool RedBlackTree_empty(RedBlackTree* RBT)
{
    if(RBT->size) {
        return false;
    }
    return true;
}

void* RedBlackTree_root(RedBlackTree* RBT)
{
    return RBT->root->data;
}

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


void RedBlackTree_traverse_preorder(RedBlackTree* RBT, void (*function)(void* data))
{
    Node* node = RBT->root;
    Stack* stack = Stack_create(RBT->size);
    while(node || stack->size) {
        if(node) {
            Stack_push(stack, node);
            function(node->data);
            node = node->left;
        }
        else {
            node = Stack_top(stack);
            Stack_pop(stack);
            node = node->right;
        }
    }
    Stack_destroy(stack);
}

void RedBlackTree_traverse_inorder(RedBlackTree* RBT, void (*function)(void* data))
{
    Node* node = RBT->root;
    Stack* stack = Stack_create(RBT->size);
    while(node || stack->size) {
        if(node) {
            Stack_push(stack, node);
            node = node->left;
        }
        else {
            node = Stack_top(stack);
            Stack_pop(stack);
            function(node->data);
            node = node->right;
        }
    }
    Stack_destroy(stack);
}

// static void preorder_traverse(RedBlackTree* RBT)
// {
//     if(RedBlackTree_empty(RBT)) {
//         return;
//     }
//     Node* node = RBT->root;
//     StackLL* S = StackLL_create(sizeof (RedBlackTreeNode));
//     while(node || S->size) {
//         if(node) {
//             StackLL_push(S, node);
//             printf("%d(%d) ", *(int*)node->data, node->balance_factor);
//             node = node->left;
//         }
//         else {
//             node = S->top->data;
//             StackLL_pop(S);
//             node = node->right;
//         }
//     }
// }

void RedBlackTree_traverse_levelorder(RedBlackTree* RBT, void (*function)(void* data))
{
    CircularQueue* circular_queue = CircularQueue_create(RBT->size);
    Node* node = RBT->root;
    function(node->data);
    CircularQueue_enqueue(circular_queue, node);
    while(circular_queue->size) {
        node = CircularQueue_front(circular_queue);
        CircularQueue_dequeue(circular_queue);
        if(node->left) {
            function(node->data);
            CircularQueue_enqueue(circular_queue, node->left);
        }
        if( node->right) {
            function(node->data);
            CircularQueue_enqueue(circular_queue, node->right);
        }
    }
    CircularQueue_destroy(circular_queue);
}
