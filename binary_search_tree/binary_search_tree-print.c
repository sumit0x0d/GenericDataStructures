#include "binary_search_tree.h"

#include <stdio.h>

void binary_search_tree_print(BinarySearchTree *tree);

QueueNode {
    BinarySearchTreeNode *data;
    QueueNode *next;
};

StackNode {
    BinarySearchTreeNode *data;
    StackNode *next;
};

Queue {
    QueueNode *front;
    QueueNode *back;
};

Stack {
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
    
    SinglyLinkedListNode *node = S->top;
    
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
            printf("%d ", *(int *)node->data);
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
            printf("%d ", *(int *)node->data);
            node = node->right;
        }
}

void levelorder_traverse(BinarySearchTree *tree)
{
    BinarySearchTreeNode *node = tree->root;
    Queue Q = queue_construct();

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

void binary_search_tree_print(BinarySearchTree *tree)
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