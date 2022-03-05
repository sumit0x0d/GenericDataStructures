#include "binary_search_tree.h"

#include <stdio.h>

void binary_search_tree_print(struct BinarySearchTree *tree);

struct SinglyLinkedListNode {
    struct BinarySearchTreeNode *data;
    struct SinglyLinkedListNode *next;
};

struct Queue {
    struct SinglyLinkedListNode *front;
    struct SinglyLinkedListNode *back;
    void (*enqueue)(struct Queue *queue, struct BinarySearchTreeNode *data);
    void (*dequeue)(struct Queue *queue);
};

struct Stack {
    struct SinglyLinkedListNode *top;
    void (*push)(struct Stack *stack, struct BinarySearchTreeNode *data);
    void (*pop)(struct Stack *stack);
};

void enqueue(struct Queue *queue, struct BinarySearchTreeNode *data)
{
    struct SinglyLinkedListNode *node = malloc(sizeof(struct SinglyLinkedListNode));
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
    
    struct SinglyLinkedListNode *node = queue->front;
    
    queue->front = node->next;
    if(!queue->front)
        queue->back = NULL;
    
    memset(node, 0, sizeof(struct SinglyLinkedListNode));
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

void push(struct Stack *stack, struct BinarySearchTreeNode *data)
{
    struct SinglyLinkedListNode *node = malloc(sizeof(struct SinglyLinkedListNode));
    if(!node) return;
    
    node->data = data;
    
    node->next = stack->top;
    stack->top = node;
}

void pop(struct Stack *stack)
{
    if(!stack->top) return;
    
    struct SinglyLinkedListNode *node = stack->top;
    
    stack->top = stack->top->next;
    
    memset(node, 0, sizeof(struct SinglyLinkedListNode));
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

void preorder_traverse(struct BinarySearchTree *tree)
{
    struct BinarySearchTreeNode *node = tree->root;
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

void inorder_traverse(struct BinarySearchTree *tree)
{
    struct BinarySearchTreeNode *node = tree->root;
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

void postorder_traverse(struct BinarySearchTree *tree)
{
    struct BinarySearchTreeNode *node = tree->root;
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

void levelorder_traverse(struct BinarySearchTree *tree)
{
    struct BinarySearchTreeNode *node = tree->root;
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
