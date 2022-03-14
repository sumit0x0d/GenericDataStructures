#include "binary_tree.h"

struct BinaryTreeNode *insert(struct BinaryTree *bt, void *data);

struct BinaryTree binary_tree_construct(size_t data_type_size)
{
    struct BinaryTree bt;

    bt.root = NULL;
    bt.size = 0;
    
    bt.insert = insert;
    
    return bt;
}

struct BinaryTreeNode *node_construct(void *data, size_t data_type_size)
{
    struct BinaryTreeNode *node = malloc(sizeof (struct BinaryTreeNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    memcpy(node->data, data, data_type_size);

    return node;
}

struct BinaryTreeNode *insert(struct BinaryTree *bt, void *data)
{
    struct BinaryTreeNode *node = node_construct(data, bt->data_type_size);
    if(!node) return;

    node->left = NULL;
    node->right = NULL;

    bt->size = bt->size + 1;

    return node;
}

// size_t binary_tree_node_height(struct BinaryTreeNode *node)
// {
//     size_t height = 0;
//     size_t queue_size;
//     struct Queue queue = queue_construct();
//     queue.enqueue(&queue, node);
//     while(queue_size) {
//         queue_size = queue.size;
//         while(queue_size) {
//             node = queue.front->data;
//             queue.dequeue(&queue);
//             if(node->left)
//                 queue.enqueue(&queue, node->left);
//             if(node->right)
//                 queue.enqueue(&queue, node->right);
//             queue_size--;
//         }
//         height++;
//     }
//     return height;
// }

struct BinaryTreeNode *tree_node_inorder_predecessor(struct BinaryTreeNode *node)
{
    if(node->left) {
        node = node->left;
        while(node->right)
            node = node->right;
    }
    return node;
}

struct BinaryTreeNode *tree_node_inorder_successor(struct BinaryTreeNode *node)
{    
    if(node->right) {
        node = node->right;
        while(node->left)
            node = node->left;
    }
    return node;
}

// struct BinaryTree *tree_from_preorder(int preorder[], size_t preorder_size, int inorder[], size_t inorder_size)
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

// struct BinaryTree *tree_from_postorder(int *postorder, size_t postorder_size, int *inorder, size_t inorder_size)
// {
//     if(postorder_size != inorder_size)
//         return NULL;
// }
