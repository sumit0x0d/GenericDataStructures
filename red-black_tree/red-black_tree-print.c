#include "red-black_tree.h"

#include <stdio.h>

QueueNode {
    RedBlackTreeNode *data;
    QueueNode *next;
};

StackNode {
    RedBlackTreeNode *data;
    StackNode *next;
};

Queue {
    QueueNode *front;
    QueueNode *back;
    void (*enqueue)(Queue *Q, RedBlackTreeNode *data);
    void (*dequeue)(Queue *Q);
};

Stack {
    StackNode *top;
    void (*push)(Stack *S, RedBlackTreeNode *data);
    void (*pop)(Stack *S);
};

void enqueue(Queue *Q, RedBlackTreeNode *data)
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

void push(Stack *S, RedBlackTreeNode *data)
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

void preorder_traverse(RedBlackTree *RBT)
{
    RedBlackTreeNode *node = RBT->root;
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

void inorder_traverse(RedBlackTree *RBT)
{
    RedBlackTreeNode *node = RBT->root;
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

void postorder_traverse(RedBlackTree *RBT)
{
    RedBlackTreeNode *node = RBT->root;
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

void levelorder_traverse(RedBlackTree *RBT)
{
    RedBlackTreeNode *node = RBT->root;
    Queue Q = queue_construct();

    printf("%d ", *(int *)RBT->root->data);
    Q.enqueue(&Q, RBT->root);

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

void red_black_tree_print(RedBlackTree *RBT)
{
    if(!RBT->size) return;

    printf("Pre-order Traverse: ");
    preorder_traverse(RBT);
    
    printf("\nIn-order Traverse: ");
    inorder_traverse(RBT);
    
    printf("\nPost-order Traverse: ");
    postorder_traverse(RBT);
    
    // printf("\nLevel-order Traverse: ");
    // levelorder_traverse(tree);
    
    printf("\n");
    printf("\b\nRed Black Tree Size: %zu\n", RBT->size);
}
