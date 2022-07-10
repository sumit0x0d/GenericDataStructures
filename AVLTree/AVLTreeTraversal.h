#ifndef AVL_TREE_TRAVERSAL_H
#define AVL_TREE_TRAVERSAL_H

#include "AVLTree.h"
#include "CircularQueue.h"
#include "Stack.h"

#include <stdio.h>

static void inorder_traverse(AVLTree* AVLT, Node* node, void (*function)(void* data))
{
    if(!node) {
        return;
    }
    Stack* stack = Stack_create(AVLTree_size(AVLT));
    while(node || stack->size) {
        if(node) {
            Stack_push(stack, node);
            node = node->left;
        }
        else {
            node = Stack_top(stack);
            Stack_pop(stack);
            function(node->data);
            // printf("%d(%d) ", *(int*)node->data, node->balance_factor);
            node = node->right;
        }
    }
}


// static void preorder_traverse(AVLTree* AVLT)
// {
//     if(AVLTree_empty(AVLT)) {
//         return;
//     }
//     Node* node = AVLT->root;
//     StackLL* S = StackLL_create(sizeof (AVLTreeNode));
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

// void levelorder_traversal(AVLTree* AVLT)
// {
//     CircularQueue *queue = CircularQueue_create(AVLTree_size(AVLT));
//     Node* node = (Node*)AVLTree_root(AVLT);
//     printf("%d(%d) ", *(int*)avl_tree_node_data(node), avl_tree_node_balance_factor(node));
//     QueueLL_enqueue(&Q, &node);
//     while(QueueLL_size(&Q)) {
//         node = QueueLL_front(&Q);
//         QueueLL_dequeue(&Q);
//         if(avl_tree_node_left(node)) {
//             printf("%d(%d) ", *(int*)avl_tree_node_data(node), avl_tree_node_balance_factor(node));
//             QueueLL_enqueue(&Q, avl_tree_node_left(node));
//         }
//         if( avl_tree_node_right(node)) {
//             printf("%d(%d) ", *(int*)avl_tree_node_data(node), avl_tree_node_balance_factor(node));
//             QueueLL_enqueue(&Q, avl_tree_node_right(node));
//         }
//     }
// }


#endif
