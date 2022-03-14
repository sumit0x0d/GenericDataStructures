#include "binary_search_tree.h"

struct BinarySearchTreeNode *search(struct BinarySearchTree *bst, void *data);
void insert(struct BinarySearchTree *bst, void *data);
void remove(struct BinarySearchTree *bst, void *data);

struct BinarySearchTree binary_search_tree_construct(size_t data_type_size)
{
    struct BinarySearchTree bst;

    bst.root = NULL;
    bst.data_type_size = data_type_size;
    bst.size = 0;

    bst.search = search;
    bst.insert = insert;
    bst.remove = remove;

    return bst;
}

void binary_search_tree_destruct(struct BinarySearchTree *bst)
{

}

struct BinarySearchTreeNode *search(struct BinarySearchTree *bst, void *data)
{
    struct BinarySearchTreeNode *node = bst->root;
    
    while(node)
        if(data == node->data)
            return node;
        else if(data < node->data)
            node = node->left;
        else
            node = node->right;

    return NULL;
}

struct BinarySearchTreeNode *node_construct(void *data, size_t data_type_size)
{
    struct BinarySearchTreeNode *node = malloc(sizeof (struct BinarySearchTreeNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    memcpy(node->data, data, data_type_size);

    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert(struct BinarySearchTree *bst, void *data)
{
    if(!bst->size) {
        bst->root = node_construct(data, bst->data_type_size);
        if(!bst->root) return;
        
        bst->size = bst->size + 1;
        
        return;
    }

    struct BinarySearchTreeNode *node = bst->root;
    struct BinarySearchTreeNode *node_parent = NULL;
    int compare;

    while(node) {
        compare = memcmp(data, node->data, bst->data_type_size);
        if(compare == 0)
            return;
        node_parent = node;
        if(compare < 0)
            node = node->left;
        else
            node = node->right;
    }

    node = node_construct(data, bst->data_type_size);
    if(!node) return;

    if(compare < 0)
        node_parent->left = node;
    else
        node_parent->right = node;

    bst->size = bst->size + 1;
}

// void binary_search_tree_node_remove(struct BinarySearchTreeNode *node)
// {
//     if(!node->left && !node->right) {
//         node = NULL;
//         free(node);
//         return;
//     }
//     struct BinarySearchTreeNode *node_inorder_predecessor = NULL;
//     struct BinarySearchTreeNode *node_inorder_successor = NULL;
//     size_t node_left_height = 0;
//     size_t node_right_height = 0;
//     if(node->left)
//         node_left_height = binary_search_tree_node_height(node->left);
//     if(node->right)
//         node_right_height = binary_search_tree_node_height(node->right);
//     if(node_left_height < node_right_height) {
//         node_inorder_predecessor = binary_search_tree_node_inorder_predecessor(node);
//         node->data = node_inorder_predecessor->data;
//     }
//     else {
//         node_inorder_successor = binary_search_tree_node_inorder_successor(node);
//         node->data = node_inorder_successor->data;
//     }
// }

// void binary_search_tree_remove(struct BinarySearchTree *bst, int data)
// {
//     if(!bst->size)
//         return;
//     struct BinarySearchTreeNode *node = bst->root;
//     struct BinarySearchTreeNode *node_parent = NULL; 
//     while(node) {
//         if(data == node->data) {
//             break;
//             // binary_search_tree_node_remove(node);
//             // return;
//         }
//         node_parent = node;
//         if(data < node->data)
//             node = node->left;
//         else
//             node = node->right;
//     }
    
//     bst->size--;
// }
