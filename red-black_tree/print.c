#include "red-black_tree.h"

#include <stdio.h>

struct LinkedListNode {
    struct RedBlackTreeNode *data;
    struct LinkedListNode *next;
};

struct Queue {
    struct LinkedListNode *front;
    struct LinkedListNode *back;
    void (*enqueue)(struct Queue *queue, struct RedBlackTreeNode *data);
    void (*dequeue)(struct Queue *queue);
};

struct Stack {
    struct LinkedListNode *top;
    void (*push)(struct Stack *stack, struct RedBlackTreeNode *data);
    void (*pop)(struct Stack *stack);
};

void enqueue(struct Queue *queue, struct RedBlackTreeNode *data)
{
    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    if(!node) return;

    node->data = data;
    
    node->next = NULL;
    if(!queue->front)
        queue->front = node;
    else
        queue->back->next = node;
    queue->back = node;
}

void dequeue(struct Queue *queue)
{
    if(!queue->front) return;
    
    struct LinkedListNode *node = queue->front;
    
    queue->front = node->next;
    if(!queue->front)
        queue->back = NULL;
    
    memset(node, 0, sizeof(struct LinkedListNode));
    free(node);
    node = NULL;
}

struct Queue queue_construct()
{
    struct Queue queue;

    queue.front = NULL;
    queue.back = NULL;

    queue.enqueue = enqueue;
    queue.dequeue = dequeue;
    
    return queue;
}

void push(struct Stack *stack, struct RedBlackTreeNode *data)
{
    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    if(!node) return;
    
    node->data = data;
    
    node->next = stack->top;
    stack->top = node;
}

void pop(struct Stack *stack)
{
    if(!stack->top) return;
    
    struct LinkedListNode *node = stack->top;
    
    stack->top = stack->top->next;
    
    memset(node, 0, sizeof(struct LinkedListNode));
    free(node);
    node = NULL;
}

struct Stack stack_construct()
{
    struct Stack stack;

    stack.top = NULL;
    
    stack.push = push;
    stack.pop = pop;
    
    return stack;
}

void preorder_traverse(struct RedBlackTree *tree)
{
    struct RedBlackTreeNode *node = tree->root;
    struct Stack stack = stack_construct();

    while(node || stack.top)
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

void inorder_traverse(struct RedBlackTree *tree)
{
    struct RedBlackTreeNode *node = tree->root;
    struct Stack stack = stack_construct();

    while(node || stack.top)
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

void postorder_traverse(struct RedBlackTree *tree)
{
    struct RedBlackTreeNode *node = tree->root;
    struct Stack stack = stack_construct();
    
    while(node || stack.top)
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

void levelorder_traverse(struct RedBlackTree *tree)
{
    struct RedBlackTreeNode *node = tree->root;
    struct Queue queue = queue_construct();

    printf("%d ", *(int *)tree->root->data);
    queue.enqueue(&queue, tree->root);

    while(queue.front) {
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

void red_black_tree_print(struct RedBlackTree *tree)
{
    if(!tree->size) return;

    printf("Pre-order Traverse: ");
    preorder_traverse(tree);
    
    printf("\nIn-order Traverse: ");
    inorder_traverse(tree);
    
    printf("\nPost-order Traverse: ");
    postorder_traverse(tree);
    
    // printf("\nLevel-order Traverse: ");
    // levelorder_traverse(tree);
    
    printf("\n");
    printf("\b\nRed Black Tree Size: %zu\n", tree->size);
}
