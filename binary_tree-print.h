#include "data_structures.h"

#include <stdio.h>

void binary_search_tree_print(BinarySearchTree *tree);

typedef struct QueueNode {
    BinarySearchTreeNode *data;
    QueueNode *next;
} QueueNode;

typedef struct StackNode {
    BinarySearchTreeNode *data;
    StackNode *next;
};

typedef struct Queue {
    QueueNode *front;
    QueueNode *back;
};

typedef struct Stack {
    StackNode *top;
};

void queue_enqueue(Queue *Q, BinarySearchTreeNode *data)
{
    QueueNode *node = malloc(sizeof (QueueNode));
    if(!node) return;

    node->data = data;

    node->next = NULL;
    if(!Q->front)
        Q->front = node;
    else
        Q->back->next = node;
    Q->back = node;
}

void queue_dequeue(Queue *Q)
{
    if(!Q->front) return;
    
    QueueNode *node = Q->front;
    
    Q->front = node->next;
    if(!Q->front)
        Q->back = NULL;
    
    free(node);
    node = NULL;
}

Queue queue_construct()
{
    Queue Q;

    Q.front = NULL;
    Q.back = NULL;

    return Q;
}

void stack_push(Stack *S, BinarySearchTreeNode *data)
{
    StackNode *node = malloc(sizeof (StackNode));
    if(!node) return;
    
    node->data = data;
    
    node->next = S->top;
    S->top = node;
}

void stack_pop(Stack *S)
{
    if(!S->top) return;
    
    StackNode *node = S->top;
    
    S->top = S->top->next;
    
    free(node);
    node = NULL;
}

Stack stack_construct()
{
    Stack S;

    S.top = NULL;
    
    return S;
}

void preorder_traverse(BinarySearchTree *tree)
{
    BinarySearchTreeNode *node = tree->root;
    Stack S = stack_construct();

    while(node || S.top)
        if(node) {
            data_print(node->data, tree->data_type_size);
            stack_push(&S, node);
            node = node->left;
        }
        else {
            node = S.top->data;
            stack_pop(&S);
            node = node->right;
        }
}

void inorder_traverse(BinarySearchTree *tree)
{
    BinarySearchTreeNode *node = tree->root;
    Stack S = stack_construct();

    while(node || S.top)
        if(node) {
            stack_push(&S, node);
            node = node->left;
        }
        else {
            node = S.top->data;
            stack_pop(&S);
            data_print(node->data, tree->data_type_size);
            node = node->right;
        }
}

void postorder_traverse(BinarySearchTree *tree)
{
    BinarySearchTreeNode *node = tree->root;
    Stack S = stack_construct();
    
    while(node || S.top)
        if(node) {
            stack_push(&S, node);
            node = node->left;
        }
        else {
            node = S.top->data;
            stack_pop(&S);
            data_print(node->data, tree->data_type_size);
            node = node->right;
        }
}

void levelorder_traverse(void *node, size_t data_type_size)
{
    // BinarySearchTreeNode *node = tree->root;
    Queue Q = queue_construct();

    data_print(node->left->data, data_type_size);
    queue_enqueue(&Q, tree->root);

    while(Q.front) {
        node = Q.front->data;
        queue_dequeue(&Q);
        if(node->left) {
            data_print(node->left->data, data_type_size);
            queue_enqueue(&Q, node->left);
        }
        if(node->right) {
            data_print(node->right->data, data_type_size);
            queue_enqueue(&Q, node->right);
        }
    }
}

static void binary_tree_traverse(void *node, int binary_tree)
{
    switch (binary_tree) {
        case BINARY_SEARCH_TREE:
            levelorder_traverse((BinarySearchTreeNode *)node, ((BinarySearchTreeNode *)node)->data_type_size);
            break;
        case AVL_TREE:
            /* code */
            break;
        case RED_BLACK_TREE:
            /* code */
            break;
        default:
            break;
    }
}

void avl_tree_print(AVLTree *AVLT)
{
    if(!AVLT->size) return;


    // printf("Pre-order Traverse: ");
    // preorder_traverse(AVLT);
    
    // printf("\nIn-order Traverse: ");
    // inorder_traverse(AVLT);
    
    // printf("\nPost-order Traverse: ");
    // postorder_traverse(AVLT);
    
    // printf("\nLevel-order Traverse: ");
    // levelorder_traverse(AVLT);
    binary_tree_traverse(AVLT->root, AVL_TREE);
    printf("\b\nBinary Search Tree Size: %zu\n", AVLT->size);
}

void binary_search_tree_print(BinarySearchTree *BST)
{
    if(!BST->size) return;

    binary_tree_traverse(BST->root, AVL_TREE);
    printf("\b\nBinary Search Tree Size: %zu\n", BST->size);
}

void red_black_tree_print(RedBlackTree *RBT)
{
    if(!RBT->size) return;

    binary_tree_traverse(RBT->root, AVL_TREE);
    printf("\b\nBinary Search Tree Size: %zu\n", RBT->size);
}
