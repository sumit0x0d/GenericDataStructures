#include "BinarySearchTree.h"
#include "CircularQueue.h"
#include "Stack.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct BinarySearchTree {
    Node* root;
    size_t data_size;
    size_t size;
    int (*compare_function)(void* data1, void* data2);
};

BinarySearchTree* BinarySearchTreeCreate(size_t data_size,
    int (*compare_function)(void* data1, void* data2))
{
    BinarySearchTree* BST = (BinarySearchTree*)malloc(sizeof (BinarySearchTree));
    if(!BST) {
        return NULL;
    }
    BST->root = NULL;
    BST->data_size = data_size;
    BST->size = 0;
    BST->compare_function = compare_function;
    return BST;
}

// void BinarySearchTreeDestroy(BinarySearchTree* BST)
// {

// }

size_t BinarySearchTreeSize(BinarySearchTree* BST)
{
    return BST->size;
}

bool BinarySearchTreeEmpty(BinarySearchTree* BST)
{
    if(BST->size) {
        return false;
    }
    return true;
}

void* BinarySearchTree_root(BinarySearchTree* BST)
{
    return BST->root->data;
}

void* BinarySearchTreeSearch(BinarySearchTree* BST, void* data)
{
    Node* node = BST->root;
    while(node) {
        int compare_function = BST->compare_function(data, node->data);
        if(compare_function == 0) {
            return node;
        }
        if(compare_function < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return NULL;
}

bool BinarySearchTreeInsert(BinarySearchTree* BST, void* data)
{
    if(!BST->root) {
        BST->root = NodeCreate(BST->data_size);
        if(!BST->root) {
            return false;
        }
        memcpy(BST->root->data, data, BST->data_size);
        BST->size = BST->size + 1;
        return true;
    }
    Node* node = BST->root;
    Node* node_parent = NULL;
    int compare_function;
    while(node) {
        compare_function = BST->compare_function(data, node->data);
        if(compare_function == 0) {
            return false;
        }
        node_parent = node;
        if(compare_function < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    node = NodeCreate(BST->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, BST->data_size);
    if(compare_function < 0) {
        node_parent->left = node;
    }
    else {
        node_parent->right = node;
    }
    BST->size = BST->size + 1;
    return true;
}

bool BinarySearchTreeRemove(BinarySearchTree* BST, void* data)
{
    if(!BST->root) {
        return false;
    }
    Node* node = BST->root;
    Node* node_parent = NULL; 
    int compare_function;
    while(node) {
        compare_function = BST->compare_function(data, node->data);
        if(compare_function == 0) {
            break;
        }
        node_parent = node;
        if(compare_function < 0) {
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
        NodeDestroy(node);
    }
    else if(!node->left) {
        if(node_parent->right == node) {
            node_parent->right = node->right;
        }
        else {
            node_parent->left = node->right;
        }
        NodeDestroy(node);
    }
    else if(!node->right) {
        if(node_parent->left == node) {
            node_parent->left = node->left;
        }
        else {
            node_parent->right = node->left;
        }
        NodeDestroy(node);
    }
    else {
        Node* node_successor = node->right;
        Node* node_successor_parent = node;
        while(node_successor->left) {
            node_successor_parent = node_successor;
            node_successor = node_successor->left;
        }
        if(node_successor_parent == node) {
            node_successor_parent->right = node_successor->right;
        }
        else {
            node_successor_parent->left = node_successor->right;
        }
        memcpy(node->data, node_successor->data, BST->data_size);
        NodeDestroy(node_successor);
    }
    BST->size = BST->size - 1;
    return true;
}

void BinarySearchTreeTraverse_preorder(BinarySearchTree* BST, void (*function)(void* data))
{
    Node* node = BST->root;
    Stack* stack = StackCreate(BST->size);
    while(node || stack->size) {
        if(node) {
            StackPush(stack, node);
            function(node->data);
            node = node->left;
        }
        else {
            node = Stack_top(stack);
            StackPop(stack);
            node = node->right;
        }
    }
    StackDestroy(stack);
}

void BinarySearchTreeTraverse_inorder(BinarySearchTree* BST, void (*function)(void* data))
{
    Node* node = BST->root;
    Stack* stack = StackCreate(BST->size);
    while(node || stack->size) {
        if(node) {
            StackPush(stack, node);
            node = node->left;
        }
        else {
            node = Stack_top(stack);
            StackPop(stack);
            function(node->data);
            node = node->right;
        }
    }
    StackDestroy(stack);
}

// static void preorderTraverse(BinarySearchTree* BST)
// {
//     if(BinarySearchTreeEmpty(BST)) {
//         return;
//     }
//     Node* node = BST->root;
//     StackLL* S = StackLLCreate(sizeof (BinarySearchTreeNode));
//     while(node || S->size) {
//         if(node) {
//             StackLLPush(S, node);
//             printf("%d(%d) ", *(int*)node->data, node->balance_factor);
//             node = node->left;
//         }
//         else {
//             node = S->top->data;
//             StackLLPop(S);
//             node = node->right;
//         }
//     }
// }

void BinarySearchTreeTraverse_levelorder(BinarySearchTree* BST, void (*function)(void* data))
{
    CircularQueue* circular_queue = CircularQueueCreate(BST->size);
    Node* node = BST->root;
    function(node->data);
    CircularQueueEnqueue(circular_queue, node);
    while(circular_queue->size) {
        node = CircularQueueFront(circular_queue);
        CircularQueueDequeue(circular_queue);
        if(node->left) {
            function(node->data);
            CircularQueueEnqueue(circular_queue, node->left);
        }
        if(node->right) {
            function(node->data);
            CircularQueueEnqueue(circular_queue, node->right);
        }
    }
    CircularQueueDestroy(circular_queue);
}
