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

BinarySearchTree* BinarySearchTree_Create(size_t data_size,
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

// void BinarySearchTree_Destroy(BinarySearchTree* BST)
// {

// }

size_t BinarySearchTree_Size(BinarySearchTree* BST)
{
    return BST->size;
}

bool BinarySearchTree_Empty(BinarySearchTree* BST)
{
    if(BST->size) {
        return false;
    }
    return true;
}

void* BinarySearchTree_Root(BinarySearchTree* BST)
{
    return BST->root->data;
}

void* BinarySearchTree_Search(BinarySearchTree* BST, void* data)
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

bool BinarySearchTree_Insert(BinarySearchTree* BST, void* data)
{
    if(!BST->root) {
        BST->root = Node_Create(BST->data_size);
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
    node = Node_Create(BST->data_size);
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

bool BinarySearchTree_Remove(BinarySearchTree* BST, void* data)
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
        Node_Destroy(node);
    }
    else if(!node->left) {
        if(node_parent->right == node) {
            node_parent->right = node->right;
        }
        else {
            node_parent->left = node->right;
        }
        Node_Destroy(node);
    }
    else if(!node->right) {
        if(node_parent->left == node) {
            node_parent->left = node->left;
        }
        else {
            node_parent->right = node->left;
        }
        Node_Destroy(node);
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
        Node_Destroy(node_successor);
    }
    BST->size = BST->size - 1;
    return true;
}

void BinarySearchTree_TraversePreorder(BinarySearchTree* BST, void (*function)(void* data))
{
    Node* node = BST->root;
    Stack* stack = Stack_Create(BST->size);
    while(node || stack->size) {
        if(node) {
            Stack_Push(stack, node);
            function(node->data);
            node = node->left;
        }
        else {
            node = Stack_top(stack);
            StackPop(stack);
            node = node->right;
        }
    }
    Stack_Destroy(stack);
}

void BinarySearchTree_TraverseInorder(BinarySearchTree* BST, void (*function)(void* data))
{
    Node* node = BST->root;
    Stack* stack = Stack_Create(BST->size);
    while(node || stack->size) {
        if(node) {
            Stack_Push(stack, node);
            node = node->left;
        }
        else {
            node = Stack_top(stack);
            StackPop(stack);
            function(node->data);
            node = node->right;
        }
    }
    Stack_Destroy(stack);
}

// static void preorder_Traverse(BinarySearchTree* BST)
// {
//     if(BinarySearchTree_Empty(BST)) {
//         return;
//     }
//     Node* node = BST->root;
//     StackLL* S = StackLL_Create(sizeof (BinarySearchTreeNode));
//     while(node || S->size) {
//         if(node) {
//             StackLL_Push(S, node);
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

void BinarySearchTree_TraverseLevelorder(BinarySearchTree* BST, void (*function)(void* data))
{
    CircularQueue* circular_queue = CircularQueue_Create(BST->size);
    Node* node = BST->root;
    function(node->data);
    CircularQueue_Enqueue(circular_queue, node);
    while(circular_queue->size) {
        node = CircularQueueFront(circular_queue);
        CircularQueue_Dequeue(circular_queue);
        if(node->left) {
            function(node->data);
            CircularQueue_Enqueue(circular_queue, node->left);
        }
        if(node->right) {
            function(node->data);
            CircularQueue_Enqueue(circular_queue, node->right);
        }
    }
    CircularQueue_Destroy(circular_queue);
}
