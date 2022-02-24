#ifndef TRAVERSAL
#define TRAVERSAL

#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedListNode {
    struct BinaryTreeNode *data;
    struct LinkedListNode *next;
};

struct Queue {
    struct LinkedListNode *front;
    struct LinkedListNode *back;
    size_t size;
    void (*enqueue)(struct Queue *queue, struct BinaryTreeNode *data);
    void (*dequeue)(struct Queue *queue);
};

struct Stack {
    struct LinkedListNode *top;
    size_t size;
    void (*push)(struct Stack *stack, struct BinaryTreeNode *data);
    void (*pop)(struct Stack *stack);
};

void enqueue(struct Queue *queue, struct BinaryTreeNode *data)
{
    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    if(!node) return;

    node->data = data;
    
    node->next = NULL;
    if(!queue->size)
        queue->front = node;
    else
        queue->back->next = node;
    queue->back = node;
    
    ++queue->size;
}

void dequeue(struct Queue *queue)
{
    if(!queue->size) return;
    
    struct LinkedListNode *node = queue->front;
    
    queue->front = node->next;
    if(!queue->front)
        queue->back = NULL;
    
    memset(node, 0, sizeof(struct LinkedListNode));
    free(node);
    node = NULL;
    
    --queue->size;
}

struct Queue queue_construct()
{
    struct Queue queue;

    queue.front = NULL;
    queue.back = NULL;
    queue.size = 0;

    queue.enqueue = enqueue;
    queue.dequeue = dequeue;
    return queue;
}

void push(struct Stack *stack, struct BinaryTreeNode *data)
{
    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    if(!node) return;
    
    node->data = data;
    
    node->next = stack->top;
    stack->top = node;
    
    ++stack->size;
}

void pop(struct Stack *stack)
{
    if(!stack->size) return;
    
    struct LinkedListNode *node = stack->top;
    
    stack->top = stack->top->next;
    
    memset(node, 0, sizeof(struct LinkedListNode));
    free(node);
    node = NULL;
    
    stack->size;
}

struct Stack stack_construct()
{
    struct Stack stack;
    stack.top = NULL;
    stack.size = 0;
    stack.push = push;
    stack.pop = pop;
    return stack;
}

void preorder_traverse(struct BinaryTree *binary_tree)
{
    struct BinaryTreeNode *node = binary_tree->root;
    struct Stack stack = stack_construct();

    while(node || stack.size)
        if(node) {
            printf("%d ", *(int *)node->data);
            stack.push(&stack, node);
            node = node->left;
        }
        else {
            node = stack.top->data;
            stack.pop(&stack);
            node = node->right;
        }
}

void inorder_traverse(struct BinaryTree *binary_tree)
{
    struct BinaryTreeNode *node = binary_tree->root;
    struct Stack stack = stack_construct();

    while(node || stack.size)
        if(node) {
            stack.push(&stack, node);
            node = node->left;
        }
        else {
            node = stack.top->data;
            stack.pop(&stack);
            printf("%d ", *(int *)node->data);
            node = node->right;
        }
}

void postorder_traverse(struct BinaryTree *binary_tree)
{
    struct BinaryTreeNode *node = binary_tree->root;
    struct Stack stack = stack_construct();
    
    while(node || stack.size)
        if(node) {
            stack.push(&stack, node);
            node = node->left;
        }
        else {
            node = stack.top->data;
            stack.pop(&stack);
            printf("%d ", *(int *)node->data);
            node = node->right;
        }
}

void levelorder_traverse(struct BinaryTree *binary_tree)
{
    struct BinaryTreeNode *node = binary_tree->root;
    struct Queue queue = queue_construct();

    printf("%d ", *(int *)binary_tree->root->data);
    queue.enqueue(&queue, binary_tree->root);

    while(&queue.size) {
        node = queue.front->data;
        queue.dequeue(&queue);
        if(node->left) {
            printf("%d ", *(int *)node->left->data);
            queue.enqueue(&queue, node->left);
        }
        if(node->right) {
            printf("%d ", *(int *)node->right->data);
            queue.enqueue(&queue, node->right);
        }
    }
}

void print(struct BinaryTree *binary_tree)
{
    if(!binary_tree->size) return;

    printf("Pre-order Traverse: ");
    preorder_traverse(binary_tree);
    
    printf("\nIn-order Traverse: ");
    inorder_traverse(binary_tree);
    
    printf("\nPost-order Traverse: ");
    postorder_traverse(binary_tree);
    
    // printf("\nLevel-order Traverse: ");
    // levelorder_traverse(binary_tree);
    
    printf("\n");
    printf("\b\nBinary Tree Size: %zu\n", binary_tree->size);
}

#endif
