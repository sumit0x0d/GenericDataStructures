#include "binary_tree.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(struct BinaryTree *binary_tree);
struct BinaryTreeNode *insert(struct BinaryTree *binary_tree, void *data, size_t data_type_size);

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
    queue->size++;
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
    queue->size--;
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
}

void pop(struct Stack *stack)
{
    if(!stack->size) return;
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
    stack.size = 0;
    stack.push = push;
    stack.pop = pop;
    return stack;
}

void binary_tree_preorder_traverse(struct BinaryTree *binary_tree)
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

void binary_tree_inorder_traverse(struct BinaryTree *binary_tree)
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

void binary_tree_postorder_traverse(struct BinaryTree *binary_tree)
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

void binary_tree_levelorder_traverse(struct BinaryTree *binary_tree)
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

struct BinaryTree binary_tree_construct()
{
    struct BinaryTree binary_tree;
    binary_tree.root = NULL;
    binary_tree.size = 0;
    binary_tree.insert = insert;
    return binary_tree;
}

void binary_tree_print(struct BinaryTree *binary_tree)
{
    if(!binary_tree->size) return;
    printf("Pre-order Traverse: ");
    binary_tree_preorder_traverse(binary_tree);
    printf("\nIn-order Traverse: ");
    binary_tree_inorder_traverse(binary_tree);
    printf("\nPost-order Traverse: ");
    binary_tree_postorder_traverse(binary_tree);
    // printf("\nLevel-order Traverse: ");
    // binary_tree_levelorder_traverse(binary_tree);
    printf("\n");
    printf("\b\nBinary Tree Size: %zu\n", binary_tree->size);
}

struct BinaryTreeNode *insert(struct BinaryTree *binary_tree, void *data, size_t data_type_size)
{
    struct BinaryTreeNode *node = malloc(sizeof(struct BinaryTreeNode));
    if(!node) return NULL;
    node->data = malloc(data_type_size);
    memcpy(node->data, data, data_type_size);
    node->data_type_size = data_type_size;
    node->left = NULL;
    node->right = NULL;
    binary_tree->size++;
    return node;
}

size_t binary_tree_node_height(struct BinaryTreeNode *node)
{
    size_t height = 0;
    size_t queue_size;
    struct Queue queue = queue_construct();
    queue.enqueue(&queue, node);
    while(queue_size) {
        queue_size = queue.size;
        while(queue_size) {
            node = queue.front->data;
            queue.dequeue(&queue);
            if(node->left)
                queue.enqueue(&queue, node->left);
            if(node->right)
                queue.enqueue(&queue, node->right);
            queue_size--;
        }
        height++;
    }
    return height;
}

struct BinaryTreeNode *binary_tree_node_inorder_predecessor(struct BinaryTreeNode *node)
{
    if(node->left) {
        node = node->left;
        while(node->right)
            node = node->right;
    }
    return node;
}

struct BinaryTreeNode *binary_tree_node_inorder_successor(struct BinaryTreeNode *node)
{    
    if(node->right) {
        node = node->right;
        while(node->left)
            node = node->left;
    }
    return node;
}

// struct BinaryTree *binary_tree_from_preorder(int preorder[], size_t preorder_size, int inorder[], size_t inorder_size)
// {
//     if(preorder_size != inorder_size)
//         return NULL;
//     struct BinaryTreeNode *root, *node;
//     root->data = preorder[0];
//     node = root;
//     for(size_t i = 1; i < preorder_size; i++)
//         for(size_t j = 0; j < inorder_size; j++) {
//             if(node->data == inorder[j])
//                 return;
//         }
//     return root;
// }

// struct BinaryTree *binary_tree_from_postorder(int *postorder, size_t postorder_size, int *inorder, size_t inorder_size)
// {
//     if(postorder_size != inorder_size)
//         return NULL;
// }
