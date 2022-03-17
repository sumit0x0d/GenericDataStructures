#include "binary_search_tree.h"

#include <stdio.h>

void binary_search_tree_print(struct BinarySearchTree *tree);

struct QueueNode {
    struct BinarySearchTreeNode *data;
    struct QueueNode *next;
};

struct StackNode {
    struct BinarySearchTreeNode *data;
    struct StackNode *next;
};

struct Queue {
    struct QueueNode *front;
    struct QueueNode *back;
};

struct Stack {
    struct StackNode *top;
};

void queue_enqueue(struct Queue *Q, struct BinarySearchTreeNode *data)
{
    struct QueueNode *node = malloc(sizeof (struct QueueNode));
    if(!node) return;

    node->data = data;

    node->next = NULL;
    if(!Q->front)
        Q->front = node;
    else
        Q->back->next = node;
    Q->back = node;
}

void queue_dequeue(struct Queue *Q)
{
    if(!Q->front) return;
    
    struct QueueNode *node = Q->front;
    
    Q->front = node->next;
    if(!Q->front)
        Q->back = NULL;
    
    free(node);
    node = NULL;
}

struct Queue queue_construct()
{
    struct Queue Q;

    Q.front = NULL;
    Q.back = NULL;

    return Q;
}

void stack_push(struct Stack *S, struct BinarySearchTreeNode *data)
{
    struct StackNode *node = malloc(sizeof (struct StackNode));
    if(!node) return;
    
    node->data = data;
    
    node->next = S->top;
    S->top = node;
}

void stack_pop(struct Stack *S)
{
    if(!S->top) return;
    
    struct SinglyLinkedListNode *node = S->top;
    
    S->top = S->top->next;
    
    free(node);
    node = NULL;
}

struct Stack stack_construct()
{
    struct Stack S;

    S.top = NULL;
    
    return S;
}

void preorder_traverse(struct BinarySearchTree *tree)
{
    struct BinarySearchTreeNode *node = tree->root;
    struct Stack S = stack_construct();

    while(node || S.top)
        if(node) {
            printf("%d ", *(int *)node->data);
            stack_push(&S, node);
            node = node->left;
        }
        else {
            node = S.top->data;
            stack_pop(&S);
            node = node->right;
        }
}

void inorder_traverse(struct BinarySearchTree *tree)
{
    struct BinarySearchTreeNode *node = tree->root;
    struct Stack S = stack_construct();

    while(node || S.top)
        if(node) {
            stack_push(&S, node);
            node = node->left;
        }
        else {
            node = S.top->data;
            stack_pop(&S);
            printf("%d ", *(int *)node->data);
            node = node->right;
        }
}

void postorder_traverse(struct BinarySearchTree *tree)
{
    struct BinarySearchTreeNode *node = tree->root;
    struct Stack S = stack_construct();
    
    while(node || S.top)
        if(node) {
            stack_push(&S, node);
            node = node->left;
        }
        else {
            node = S.top->data;
            stack_pop(&S);
            printf("%d ", *(int *)node->data);
            node = node->right;
        }
}

void levelorder_traverse(struct BinarySearchTree *tree)
{
    struct BinarySearchTreeNode *node = tree->root;
    struct Queue Q = queue_construct();

    printf("%d ", *(int *)tree->root->data);
    queue_enqueue(&Q, tree->root);

    while(Q.front) {
        node = Q.front->data;
        queue_dequeue(&Q);
        if(node->left) {
            printf("%d ", *(int *)node->left->data);
            queue_enqueue(&Q, node->left);
        }
        if(node->right) {
            printf("%d ", *(int *)node->right->data);
            queue_enqueue(&Q, node->right);
        }
    }
}

void binary_search_tree_print(struct BinarySearchTree *tree)
{
    if(!tree->size) return;

    printf("Pre-order Traverse: ");
    preorder_traverse(tree);
    
    printf("\nIn-order Traverse: ");
    inorder_traverse(tree);
    
    printf("\nPost-order Traverse: ");
    postorder_traverse(tree);
    
    printf("\nLevel-order Traverse: ");
    levelorder_traverse(tree);
    
    printf("\n");
    printf("\b\nBinary Search Tree Size: %zu\n", tree->size);
}
