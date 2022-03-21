#include "binary_tree.h"

#include <stdio.h>

QueueNode {
    BinaryTreeNode *data;
    QueueNode *next;
};

StackNode {
    BinaryTreeNode *data;
    StackNode *next;
};

Queue {
    QueueNode *front;
    QueueNode *back;
    void (*enqueue)(Queue *Q, BinaryTreeNode *data);
    void (*dequeue)(Queue *Q);
};

Stack {
    StackNode *top;
    void (*push)(Stack *S, BinaryTreeNode *data);
    void (*pop)(Stack *S);
};

void enqueue(Queue *Q, BinaryTreeNode *data)
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

void dequeue(Queue *Q)
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

    Q.enqueue = enqueue;
    Q.dequeue = dequeue;
    
    return Q;
}

void push(Stack *S, BinaryTreeNode *data)
{
    StackNode *node = malloc(sizeof (StackNode));
    if(!node) return;
    
    node->data = data;
    
    node->next = S->top;
    S->top = node;
}

void pop(Stack *S)
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
    
    S.push = push;
    S.pop = pop;
    
    return S;
}

void preorder_traverse(BinaryTree *bt)
{
    BinaryTreeNode *node = bt->root;
    Stack S = stack_construct();

    while(node || S.top)
        if(node) {
            printf("%d ", *(int *)node->data);
            S.push(&S, node);
            node = node->left;
        }
        else {
            node = S.top->data;
            S.pop(&S);
            node = node->right;
        }
}

void inorder_traverse(BinaryTree *bt)
{
    BinaryTreeNode *node = bt->root;
    Stack S = stack_construct();

    while(node || S.top)
        if(node) {
            S.push(&S, node);
            node = node->left;
        }
        else {
            node = S.top->data;
            S.pop(&S);
            printf("%d ", *(int *)node->data);
            node = node->right;
        }
}

void postorder_traverse(BinaryTree *bt)
{
    BinaryTreeNode *node = bt->root;
    Stack S = stack_construct();
    
    while(node || S.top)
        if(node) {
            S.push(&S, node);
            node = node->left;
        }
        else {
            node = S.top->data;
            S.pop(&S);
            printf("%d ", *(int *)node->data);
            node = node->right;
        }
}

void levelorder_traverse(BinaryTree *bt)
{
    BinaryTreeNode *node = bt->root;
    Queue Q = queue_construct();

    printf("%d ", *(int *)bt->root->data);
    Q.enqueue(&Q, bt->root);

    while(Q.front) {
        node = Q.front->data;
        Q.dequeue(&Q);
        if(node->left) {
            printf("%d ", *(int *)node->left->data);
            Q.enqueue(&Q, node->left);
        }
        if(node->right) {
            printf("%d ", *(int *)node->right->data);
            Q.enqueue(&Q, node->right);
        }
    }
}

void binary_tree_print(BinaryTree *bt)
{
    if(!bt->size) return;

    printf("Pre-order Traverse: ");
    preorder_traverse(bt);
    
    printf("\nIn-order Traverse: ");
    inorder_traverse(bt);
    
    printf("\nPost-order Traverse: ");
    postorder_traverse(bt);
    
    // printf("\nLevel-order Traverse: ");
    // levelorder_traverse(tree);
    
    printf("\n");
    printf("\b\nBinary Tree Size: %zu\n", bt->size);
}
