#include "binary_search_tree.h"

#include <stdlib.h>
#include <string.h>

struct BinarySearchTreeNode *search(struct BinarySearchTree *binary_search_tree, void *data, size_t data_tyep_size);
void insert(struct BinarySearchTree *binary_search_tree, void *data, size_t data_type_size);
void remove(struct BinarySearchTree *binary_search_tree, void *data, size_t data_type_size);

struct BinarySearchTree binary_search_tree_construct()
{
    struct BinarySearchTree binary_search_tree;
    
    binary_search_tree.root = NULL;
    binary_search_tree.size = 0;

    binary_search_tree.search = search;
    binary_search_tree.insert = insert;
    binary_search_tree.remove = remove;

    return binary_search_tree;
}

void binary_search_tree_distruct(struct BinarySearchTree *binary_search_tree)
{

}

struct BinarySearchTreeNode *search(struct BinarySearchTree *binary_search_tree, void *data, size_t data_tyep_size)
{
    struct BinarySearchTreeNode *node = binary_search_tree->root;
    
    while(node)
        if(data == node->data)
            return node;
        else if(data < node->data)
            node = node->left;
        else
            node = node->right;

    return NULL;
}

struct BinarySearchTreeNode *node_construct(struct BinarySearchTree *binary_search_tree, void *data, size_t data_type_size)
{
    struct BinarySearchTreeNode *node = malloc(sizeof(struct BinarySearchTreeNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    memcpy(node->data, data, data_type_size);

    node->data_type_size = data_type_size;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert(struct BinarySearchTree *binary_search_tree, void *data, size_t data_type_size)
{
    if(!binary_search_tree->size) {
        binary_search_tree->root = node_construct(binary_search_tree, data, data_type_size);
        ++binary_search_tree->size;
        return;
    }

    struct BinarySearchTreeNode *node = binary_search_tree->root;
    struct BinarySearchTreeNode *node_parent = NULL;
    int compare;

    while(node) {
        compare = memcmp(data, node->data, node->data_type_size);
        if(compare == 0)
            return;
        node_parent = node;
        if(compare < 0)
            node = node->left;
        else
            node = node->right;
    }

    node = node_construct(binary_search_tree, data, data_type_size);
    // compare = memcmp(data, node_parent->data, node->data_type_size);
    if(compare < 0)
        node_parent->left = node;
    else
        node_parent->right = node;
    ++binary_search_tree->size;
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

// void binary_search_tree_remove(struct BinarySearchTree *binary_search_tree, int data)
// {
//     if(!binary_search_tree->size)
//         return;
//     struct BinarySearchTreeNode *node = binary_search_tree->root;
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
    
//     binary_search_tree->size--;
// }
