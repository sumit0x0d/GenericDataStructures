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
    int (*compare)(void* data1, void* data2);
};

BinarySearchTree* BinarySearchTree_create(size_t data_size,
    int (*compare)(void* data1, void* data2))
{
    BinarySearchTree* BST = (BinarySearchTree*)malloc(sizeof (BinarySearchTree));
    if(!BST) {
        return NULL;
    }
    BST->root = NULL;
    BST->data_size = data_size;
    BST->size = 0;
    BST->compare = compare;
    return BST;
}

// void BinarySearchTree_destroy(BinarySearchTree* BST)
// {

// }

size_t BinarySearchTree_size(BinarySearchTree* BST)
{
    return BST->size;
}

bool BinarySearchTree_empty(BinarySearchTree* BST)
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

void* BinarySearchTree_search(BinarySearchTree* BST, void* data)
{
    Node* node = BST->root;
    while(node) {
        int compare = BST->compare(data, node->data);
        if(compare == 0) {
            return node;
        }
        if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return NULL;
}

bool BinarySearchTree_insert(BinarySearchTree* BST, void* data)
{
    if(!BST->root) {
        BST->root = Node_create(BST->data_size);
        if(!BST->root) {
            return false;
        }
        memcpy(BST->root->data, data, BST->data_size);
        BST->size = BST->size + 1;
        return true;
    }
    Node* node = BST->root;
    Node* node_parent = NULL;
    int compare;
    while(node) {
        compare = BST->compare(data, node->data);
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
    node = Node_create(BST->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, BST->data_size);
    if(compare < 0) {
        node_parent->left = node;
    }
    else {
        node_parent->right = node;
    }
    BST->size = BST->size + 1;
    return true;
}

bool BinarySearchTree_remove(BinarySearchTree* BST, void* data)
{
    if(!BST->root) {
        return false;
    }
    Node* node = BST->root;
    Node* node_parent = NULL; 
    int compare;
    while(node) {
        compare = BST->compare(data, node->data);
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
        Node_destroy(node);
    }
    else if(!node->left) {
        if(node_parent->right == node) {
            node_parent->right = node->right;
        }
        else {
            node_parent->left = node->right;
        }
        Node_destroy(node);
    }
    else if(!node->right) {
        if(node_parent->left == node) {
            node_parent->left = node->left;
        }
        else {
            node_parent->right = node->left;
        }
        Node_destroy(node);
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
        Node_destroy(node_successor);
    }
    BST->size = BST->size - 1;
    return true;
}

void BinarySearchTree_traverse_preorder(BinarySearchTree* BST, void (*function)(void* data))
{
    Node* node = BST->root;
    Stack* stack = Stack_create(BST->size);
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

void BinarySearchTree_traverse_inorder(BinarySearchTree* BST, void (*function)(void* data))
{
    Node* node = BST->root;
    Stack* stack = Stack_create(BST->size);
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

// static void preorder_traverse(BinarySearchTree* BST)
// {
//     if(BinarySearchTree_empty(BST)) {
//         return;
//     }
//     Node* node = BST->root;
//     StackLL* S = StackLL_create(sizeof (BinarySearchTreeNode));
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

void BinarySearchTree_traverse_levelorder(BinarySearchTree* BST, void (*function)(void* data))
{
    CircularQueue* circular_queue = CircularQueue_create(BST->size);
    Node* node = BST->root;
    function(node->data);
    CircularQueue_enqueue(circular_queue, node);
    while(circular_queue->size) {
        node = CircularQueue_front(circular_queue);
        CircularQueue_dequeue(circular_queue);
        if(node->left) {
            function(node->data);
            CircularQueue_enqueue(circular_queue, node->left);
        }
        if(node->right) {
            function(node->data);
            CircularQueue_enqueue(circular_queue, node->right);
        }
    }
    CircularQueue_destroy(circular_queue);
}
