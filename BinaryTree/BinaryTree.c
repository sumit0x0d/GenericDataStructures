#include "BinaryTree.h"

BinaryTree* BinaryTree_create();

static BinaryTreeNode* node_create(size_t data_size);

BinaryTreeNode* BinaryTree_insert(BinaryTree* BT, void* data, size_t data_size);

BinaryTree* BinaryTree_create()
{
    BinaryTree* BT = malloc(sizeof (BinaryTree));
    if(!BT) {
        return NULL;
    }
    BT->root = NULL;
    BT->size = 0;
    return BT;
}

static BinaryTreeNode* node_create(size_t data_size)
{
    BinaryTreeNode* node = malloc(sizeof (BinaryTreeNode));
    if(!node) {
        return NULL;
    }
    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }
    node->left = NULL;
    node->right = NULL;
    return node;
}

BinaryTreeNode* BinaryTree_insert(BinaryTree* BT, void* data, size_t data_size)
{
    BinaryTreeNode* node = node_create(data_size);
    if(!node) {
        return NULL;
    }
    memcpy(node->data, data, data_size);
    BT->size = BT->size + 1;
    return node;
}

// size_t BinaryTree_node_height(BinaryTreeNode* node)
// {
//     size_t height = 0;
//     size_t queue_size;
//     Queue queue = queue_create();
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

// static BinaryTreeNode* tree_node_inorder_predecessor(BinaryTreeNode* node)
// {
//     if(node->left) {
//         node = node->left;
//         while(node->right)
//             node = node->right;
//     }

//     return node;
// }

// static BinaryTreeNode* tree_node_inorder_successor(BinaryTreeNode* node)
// {    
//     if(node->right) {
//         node = node->right;
//         while(node->left)
//             node = node->left;
//     }
//     return node;
// }

// BinaryTree* tree_from_preorder(int preorder[], size_t preorder_size, int inorder[], size_t inorder_size)
// {
//     if(preorder_size != inorder_size)
//        
        // return NULL;
//     BinaryTreeNode* root, *node;
//     root->data = preorder[0];
//     node = root;
//     for(size_t i = 1; i < preorder_size; i++)
//         for(size_t j = 0; j < inorder_size; j++) {
//             if(node->data == inorder[j])
//                 return;
//         }
//     return root;
// }

// BinaryTree* tree_from_postorder(int *postorder, size_t postorder_size, int *inorder, size_t inorder_size)
// {
//     if(postorder_size != inorder_size)
//        
        // return NULL;
// }
