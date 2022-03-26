#include "avl_tree/avl_tree.h"
#include "binary_search_tree/binary_search_tree.h"
#include "red-black_tree/red-black_tree.h"

#include "queue-linked_list/queue-linked_list.h"
#include "stack-linked_list/stack-linked_list.h"

#include "data-print.h"

enum {
    AVL_TREE,
    BINARY_SEARCH_TREE,
    RED_BLACK_TREE,
};

void preorder_traverse(void *root, int binary_tree_type, int data_type);
void inorder_traverse(void *root, int binary_tree_type, int data_type);
void postorder_traverse(void *root, int binary_tree_type, int data_type);
void levelorder_traverse(void *root, int binary_tree_type, int data_type);

void avl_tree_print(AVLTree *AVLT);
void binary_search_tree_print(BinarySearchTree *BST);
void red_black_tree_print(RedBlackTree *RBT);

void preorder_traverse(void *root, int binary_tree_type, int data_type)
{
    StackLinkedList S = stack_linked_list_construct();
    
    switch (binary_tree_type) {
        case AVL_TREE:
            {
                AVLTreeNode *node = root;
                while(node || stack_linked_list_size(&S))
                    if(node) {
                        data_print(node->data, data_type);
                        stack_linked_list_push(&S, node, STRUCT, sizeof (AVLTreeNode));
                        node = node->left;
                    }
                    else {
                        node = stack_linked_list_peek(&S)->data;
                        stack_linked_list_pop(&S);
                        node = node->right;
                    }
            }
            break;
        case BINARY_SEARCH_TREE:
            {
                BinarySearchTreeNode *node = root;
                while(node || stack_linked_list_size(&S))
                    if(node) {
                        data_print(node->data, data_type);
                        stack_linked_list_push(&S, node, STRUCT, sizeof (BinarySearchTreeNode));
                        node = node->left;
                    }
                    else {
                        node = stack_linked_list_peek(&S)->data;
                        stack_linked_list_pop(&S);
                        node = node->right;
                    }
            }
            break;
        case RED_BLACK_TREE:
            {
                RedBlackTreeNode *node = root;
                while(node || stack_linked_list_size(&S))
                    if(node) {
                        data_print(node->data, data_type);
                        stack_linked_list_push(&S, node, STRUCT, sizeof (RedBlackTreeNode));
                        node = node->left;
                    }
                    else {
                        node = stack_linked_list_peek(&S)->data;
                        stack_linked_list_pop(&S);
                        node = node->right;
                }
            }
            break;
        default:
            break;
    }
}

void inorder_traverse(void *root, int binary_tree_type, int data_type)
{
    StackLinkedList S = stack_linked_list_construct();

    switch (binary_tree_type) {
        case AVL_TREE:
            {
                AVLTreeNode *node = root;
                while(node || stack_linked_list_size(&S))
                    if(node) {
                        stack_linked_list_push(&S, node, STRUCT, sizeof (AVLTreeNode));
                        node = node->left;
                    }
                    else {
                        node = stack_linked_list_peek(&S)->data;
                        stack_linked_list_pop(&S);
                        data_print(node->data, data_type);
                        node = node->right;
                    }
            }
            break;
        case BINARY_SEARCH_TREE:
            {
                BinarySearchTreeNode *node = root;
                while(node || stack_linked_list_size(&S))
                    if(node) {
                        stack_linked_list_push(&S, node, STRUCT, sizeof (BinarySearchTreeNode));
                        node = node->left;
                    }
                    else {
                        node = stack_linked_list_peek(&S)->data;
                        stack_linked_list_pop(&S);
                        data_print(node->data, data_type);
                        node = node->right;
                    }
            }
            break;
        case RED_BLACK_TREE:
            {
                RedBlackTreeNode *node = root;
                while(node || stack_linked_list_size(&S))
                    if(node) {
                        stack_linked_list_push(&S, node, STRUCT, sizeof (RedBlackTreeNode));
                        node = node->left;
                    }
                    else {
                        node = stack_linked_list_peek(&S)->data;
                        stack_linked_list_pop(&S);
                        data_print(node->data, data_type);
                        node = node->right;
                }
            }
            break;
        default:
            break;
    }
}

// void postorder_traverse(BinarySearchTree *tree)
// {
//     BinarySearchTreeNode *node = tree->root;
//     Stack S = stack_construct();
    
//     while(node || S.top)
//         if(node) {
//             stack_push(&S, node);
//             node = node->left;
//         }
//         else {
//             node = S.top->data;
//             stack_pop(&S);
//             data_print(node->data, tree->data_type_size);
//             node = node->right;
//         }
// }

void levelorder_traverse(void *root, int binary_tree_type, int data_type)
{
    QueueLinkedList Q = queue_linked_list_construct();

    switch (binary_tree_type) {
        case AVL_TREE:
            {
                AVLTreeNode *node = root;
                data_print(node->data, data_type);
                queue_linked_list_enqueue(&Q, node, STRUCT, sizeof (AVLTreeNode));
                while(queue_linked_list_size(&Q)) {
                    node = queue_linked_list_front(&Q)->data;
                    queue_linked_list_dequeue(&Q);
                    if(node->left) {
                        data_print(node->left->data, data_type);
                        queue_linked_list_enqueue(&Q, node->left, STRUCT, sizeof (AVLTreeNode));
                    }
                    if(node->right) {
                        data_print(node->right->data, data_type);
                        queue_linked_list_enqueue(&Q, node->right, STRUCT, sizeof (AVLTreeNode));
                    }
                }
            }
            break;
        case BINARY_SEARCH_TREE:
            {
                BinarySearchTreeNode *node = root;
                data_print(node->data, data_type);
                queue_linked_list_enqueue(&Q, node, STRUCT, sizeof (BinarySearchTreeNode));
                while(queue_linked_list_size(&Q)) {
                    node = queue_linked_list_front(&Q)->data;
                    queue_linked_list_dequeue(&Q);
                    if(node->left) {
                        data_print(node->left->data, data_type);
                        queue_linked_list_enqueue(&Q, node->left, STRUCT, sizeof (BinarySearchTreeNode));
                    }
                    if(node->right) {
                        data_print(node->right->data, data_type);
                        queue_linked_list_enqueue(&Q, node->right, STRUCT, sizeof (BinarySearchTreeNode));
                    }
                }
            }
            break;
        case RED_BLACK_TREE:
            {
                RedBlackTreeNode *node = root;
                data_print(node->data, data_type);
                queue_linked_list_enqueue(&Q, node, STRUCT, sizeof (RedBlackTreeNode));
                while(queue_linked_list_size(&Q)) {
                    node = queue_linked_list_front(&Q)->data;
                    queue_linked_list_dequeue(&Q);
                    if(node->left) {
                        data_print(node->left->data, data_type);
                        queue_linked_list_enqueue(&Q, node->left, STRUCT, sizeof (RedBlackTreeNode));
                    }
                    if(node->right) {
                        data_print(node->right->data, data_type);
                        queue_linked_list_enqueue(&Q, node->right, STRUCT, sizeof (RedBlackTreeNode));
                    }
                }
            }
            break;
        default:
            break;
    }
}

void avl_tree_print(AVLTree *AVLT)
{
    // if(!avl_tree_size(AVLT)) return;

    printf("[AVL Tree]");

    printf("\n[Pre-Order]\t: ");
    preorder_traverse(AVLT->root, AVL_TREE, AVLT->data_type);

    printf("\n[In-Order]\t: ");
    preorder_traverse(AVLT->root, AVL_TREE, AVLT->data_type);

    printf("\n[Lever-Order]\t: ");
    levelorder_traverse(AVLT->root, AVL_TREE, AVLT->data_type);
    
    printf("\b\n[Size]\t: %zu\n", AVLT->size, AVLT->data_type);
}

void binary_search_tree_print(BinarySearchTree *BST)
{
    // if(!binary_search_tree_size(BST)) return;

    printf("[Binary Search Tree]");

    printf("\n[Pre-Order]\t: ");
    preorder_traverse(BST->root, BINARY_SEARCH_TREE, BST->data_type);

    printf("\n[In-Order]\t: ");
    preorder_traverse(BST->root, BINARY_SEARCH_TREE, BST->data_type);
    
    printf("\n[Lever-Order]\t: ");
    levelorder_traverse(BST->root, BINARY_SEARCH_TREE, BST->data_type);

    printf("\b\n[Size]\t: %zu\n", BST->size);
}

void red_black_tree_print(RedBlackTree *RBT)
{
    // if(!red_black_tree_size(RBT)) return;

    printf("[Red-Black Tree]");

    printf("\n[Pre-Order]\t: ");
    preorder_traverse(RBT->root, RED_BLACK_TREE, RBT->data_type);

    printf("\n[In-Order]\t: ");
    preorder_traverse(RBT->root, RED_BLACK_TREE, RBT->data_type);

    printf("\n[Lever-Order]\t: ");
    levelorder_traverse(RBT->root, RED_BLACK_TREE, RBT->data_type);
    
    printf("\b\nRed-Black Tree Size: %zu\n", RBT->size);
}
