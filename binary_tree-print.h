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

void preorder_traverse(void *root, int binary_tree_type);
void inorder_traverse(void *root, int binary_tree_type);
void postorder_traverse(void *root, int binary_tree_type);
void levelorder_traverse(void *root, int binary_tree_type);

void avl_tree_print(AVLTree *AVLT);
void binary_search_tree_print(BinarySearchTree *BST);
void red_black_tree_print(RedBlackTree *RBT);

void preorder_traverse(void *root, int binary_tree_type)
{
    StackLinkedList S = stack_linked_list_construct();
    
    switch (binary_tree_type) {
        case AVL_TREE:
            {
                AVLTreeNode *node = root;
                while(node || stack_linked_list_size(&S))
                    if(node) {
                        data_print(node->data, node->data_type_size);
                        stack_linked_list_push(&S, node, sizeof (AVLTreeNode));
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
                        data_print(node->data, node->data_type_size);
                        stack_linked_list_push(&S, node, sizeof (BinarySearchTreeNode));
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
                        data_print(node->data, node->data_type_size);
                        stack_linked_list_push(&S, node, sizeof (RedBlackTreeNode));
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

void inorder_traverse(void *root, int binary_tree_type)
{
    StackLinkedList S = stack_linked_list_construct();

    switch (binary_tree_type) {
        case AVL_TREE:
            {
                AVLTreeNode *node = root;
                while(node || stack_linked_list_size(&S))
                    if(node) {
                        stack_linked_list_push(&S, node, sizeof (AVLTreeNode));
                        node = node->left;
                    }
                    else {
                        node = stack_linked_list_peek(&S)->data;
                        stack_linked_list_pop(&S);
                        data_print(node->data, node->data_type_size);
                        node = node->right;
                    }
            }
            break;
        case BINARY_SEARCH_TREE:
            {
                BinarySearchTreeNode *node = root;
                while(node || stack_linked_list_size(&S))
                    if(node) {
                        stack_linked_list_push(&S, node, sizeof (BinarySearchTreeNode));
                        node = node->left;
                    }
                    else {
                        node = stack_linked_list_peek(&S)->data;
                        stack_linked_list_pop(&S);
                        data_print(node->data, node->data_type_size);
                        node = node->right;
                    }
            }
            break;
        case RED_BLACK_TREE:
            {
                RedBlackTreeNode *node = root;
                while(node || stack_linked_list_size(&S))
                    if(node) {
                        stack_linked_list_push(&S, node, sizeof (RedBlackTreeNode));
                        node = node->left;
                    }
                    else {
                        node = stack_linked_list_peek(&S)->data;
                        stack_linked_list_pop(&S);
                        data_print(node->data, node->data_type_size);
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

void levelorder_traverse(void *root, int binary_tree_type)
{
    QueueLinkedList Q = queue_linked_list_construct();

    switch (binary_tree_type) {
        case AVL_TREE:
            {
                AVLTreeNode *node = root;
                data_print(node->data, node->data_type_size);
                queue_linked_list_enqueue(&Q, node, sizeof (AVLTreeNode));
                while(queue_linked_list_size(&Q)) {
                    node = queue_linked_list_front(&Q)->data;
                    queue_linked_list_dequeue(&Q);
                    if(node->left) {
                        data_print(node->left->data, node->left->data_type_size);
                        queue_linked_list_enqueue(&Q, node->left, sizeof (AVLTreeNode));
                    }
                    if(node->right) {
                        data_print(node->right->data, node->right->data_type_size);
                        queue_linked_list_enqueue(&Q, node->right, sizeof (AVLTreeNode));
                    }
                }
            }
            break;
        case BINARY_SEARCH_TREE:
            {
                BinarySearchTreeNode *node = root;
                data_print(node->data, node->data_type_size);
                queue_linked_list_enqueue(&Q, node, sizeof (BinarySearchTreeNode));
                while(queue_linked_list_size(&Q)) {
                    node = queue_linked_list_front(&Q)->data;
                    queue_linked_list_dequeue(&Q);
                    if(node->left) {
                        data_print(node->left->data, node->left->data_type_size);
                        queue_linked_list_enqueue(&Q, node->left, sizeof (BinarySearchTreeNode));
                    }
                    if(node->right) {
                        data_print(node->right->data, node->right->data_type_size);
                        queue_linked_list_enqueue(&Q, node->right, sizeof (BinarySearchTreeNode));
                    }
                }
            }
            break;
        case RED_BLACK_TREE:
            {
                RedBlackTreeNode *node = root;
                data_print(node->data, node->data_type_size);
                queue_linked_list_enqueue(&Q, node, sizeof (RedBlackTreeNode));
                while(queue_linked_list_size(&Q)) {
                    node = queue_linked_list_front(&Q)->data;
                    queue_linked_list_dequeue(&Q);
                    if(node->left) {
                        data_print(node->left->data, node->left->data_type_size);
                        queue_linked_list_enqueue(&Q, node->left, sizeof (RedBlackTreeNode));
                    }
                    if(node->right) {
                        data_print(node->right->data, node->right->data_type_size);
                        queue_linked_list_enqueue(&Q, node->right, sizeof (RedBlackTreeNode));
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
    if(!avl_tree_size(AVLT)) return;

    printf("AVL Tree Pre-Order: ");
    preorder_traverse(AVLT->root, AVL_TREE);

    printf("\nAVL Tree In-Order: ");
    preorder_traverse(AVLT->root, AVL_TREE);

    printf("\nAVL Tree Lever-Order: ");
    levelorder_traverse(AVLT->root, AVL_TREE);
    
    printf("\b\nAVL Tree Size: %zu\n", AVLT->size);
}

void binary_search_tree_print(BinarySearchTree *BST)
{
    if(!binary_search_tree_size(BST)) return;

    printf("Binary Search Tree Pre-Order: ");
    preorder_traverse(BST->root, BINARY_SEARCH_TREE);

    printf("\nBinary Search Tree In-Order: ");
    preorder_traverse(BST->root, BINARY_SEARCH_TREE);
    
    printf("\nBinary Search Tree Lever-Order: ");
    levelorder_traverse(BST->root, BINARY_SEARCH_TREE);

    printf("\b\nBinary Search Tree Size: %zu\n", BST->size);
}

void red_black_tree_print(RedBlackTree *RBT)
{
    if(!red_black_tree_size(RBT)) return;

    printf("Red-Black Tree Pre-Order: ");
    preorder_traverse(RBT->root, RED_BLACK_TREE);

    printf("\nRed-Black Tree In-Order: ");
    preorder_traverse(RBT->root, RED_BLACK_TREE);

    printf("\nRed-Black Tree Lever Order: ");
    levelorder_traverse(RBT->root, RED_BLACK_TREE);
    
    printf("\b\nRed-Black Tree Size: %zu\n", RBT->size);
}
