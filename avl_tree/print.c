#include "avl_tree.h"

#include <stdio.h>

struct QueueNode {
    struct AVLTreeNode *data;
    struct QueueNode *next;
};

struct StackNode {
    struct AVLTreeNode *data;
    struct StackNode *next;
};

struct Queue {
    struct QueueNode *front;
    struct QueueNode *back;
    void (*enqueue)(struct Queue *queue, struct AVLTreeNode *data);
    void (*dequeue)(struct Queue *queue);
};

struct Stack {
    struct StackNode *top;
    void (*push)(struct Stack *stack, struct AVLTreeNode *data);
    void (*pop)(struct Stack *stack);
};

void enqueue(struct Queue *queue, struct AVLTreeNode *data)
{
    struct QueueNode *node = malloc(sizeof (struct QueueNode));
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
    
    struct QueueNode *node = queue->front;
    
    queue->front = node->next;
    if(!queue->front)
        queue->back = NULL;
    
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

void push(struct Stack *stack, struct AVLTreeNode *data)
{
    struct StackNode *node = malloc(sizeof (struct StackNode));
    if(!node) return;
    
    node->data = data;
    
    node->next = stack->top;
    stack->top = node;
}

void pop(struct Stack *stack)
{
    if(!stack->top) return;
    
    struct StackNode *node = stack->top;
    
    stack->top = stack->top->next;
    
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

void preorder_traverse(struct AVLTree *avlt)
{
    struct AVLTreeNode *node = avlt->root;
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

void inorder_traverse(struct AVLTree *avlt)
{
    struct AVLTreeNode *node = avlt->root;
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

void postorder_traverse(struct AVLTree *avlt)
{
    struct AVLTreeNode *node = avlt->root;
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

void levelorder_traverse(struct AVLTree *avlt)
{
    struct AVLTreeNode *node = avlt->root;
    struct Queue queue = queue_construct();

    printf("%d ", *(int *)avlt->root->data);
    queue.enqueue(&queue, avlt->root);

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

void avl_tree_print(struct AVLTree *avlt)
{
    if(!avlt->size) return;

    printf("Pre-order Traverse: ");
    preorder_traverse(avlt);
    
    printf("\nIn-order Traverse: ");
    inorder_traverse(avlt);
    
    printf("\nPost-order Traverse: ");
    postorder_traverse(avlt);

    // printf("\nLevel-order Traverse: ");
    // levelorder_traverse(tree);

    printf("\n");
    printf("\b\nAVL Tree Size: %zu\n", avlt->size);
}
