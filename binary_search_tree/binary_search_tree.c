#include "binary_search_tree.h"

typedef struct BinarySearchTreeNode {
    void* data;
    struct BinarySearchTreeNode* left;
    struct BinarySearchTreeNode* right;
} BinarySearchTreeNode;

typedef struct BinarySearchTree {
    BinarySearchTreeNode* root;
    size_t data_size;
    size_t size;
    int (*compare)(void* data, void* node_data);
} BinarySearchTree;

typedef struct StackNode {
    BinarySearchTreeNode* data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

BinarySearchTree* binary_search_tree_create(size_t data_size,
    int (*compare)(void* data, void* node_data));
void binary_search_tree_destroy(BinarySearchTree* BST);

static BinarySearchTreeNode* node_create(size_t data_size);
static void node_destroy(BinarySearchTreeNode* node);

BinarySearchTreeNode* binary_search_tree_root(BinarySearchTree* BST);
size_t binary_search_tree_size(BinarySearchTree* BST);

BinarySearchTreeNode* binary_search_tree_search(BinarySearchTree* BST, void* data);
bool binary_search_tree_insert(BinarySearchTree* BST, void* data);
bool binary_search_tree_remove(BinarySearchTree* BST, void* data);

static Stack* stack_create();
static BinarySearchTreeNode* stack_peek(Stack* S);
static bool stack_push(Stack* S, BinarySearchTreeNode* data);
static bool stack_pop(Stack* S);

void binary_search_tree_preorder_traverse(BinarySearchTree *BST,
    void (*function)(void *data));
void binary_search_tree_inorder_traverse(BinarySearchTree *BST,
    void (*function)(void *data));
void binary_search_tree_postorder_traverse(BinarySearchTree *BST,
    void (*function)(void *data));
void binary_search_tree_levelorder_traverse(BinarySearchTree *BST,
    void (*function)(void *data));

BinarySearchTree* binary_search_tree_create(size_t data_size,
    int (*compare)(void* data, void* node_data))
{
    BinarySearchTree* BST = malloc(sizeof (BinarySearchTree));
    if(!BST) {
        return NULL;
    }
    BST->root = NULL;
    BST->data_size = data_size;
    BST->size = 0;
    BST->compare = compare;
    return BST;
}

// void binary_search_tree_destroy(BinarySearchTree* BST)
// {

// }

BinarySearchTreeNode* binary_search_tree_root(BinarySearchTree* BST)
{
    if(!BST->root) {
        return NULL;
    }
    return BST->root;
}

size_t binary_search_tree_size(BinarySearchTree* BST)
{
    return BST->size;
}

BinarySearchTreeNode* binary_search_tree_search(BinarySearchTree* BST, void* data)
{
    BinarySearchTreeNode* node = BST->root;
    while(node) {
        int compare = BST->compare(data, node->data);
        if(compare == 0) {
            return node;
        }
        if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return NULL;
}

static BinarySearchTreeNode* node_create(size_t data_size)
{
    BinarySearchTreeNode* node = malloc(sizeof (BinarySearchTreeNode));
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

static void node_destroy(BinarySearchTreeNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

bool binary_search_tree_insert(BinarySearchTree* BST, void* data)
{
    if(!BST->root) {
        BST->root = node_create(BST->data_size);
        if(!BST->root) {
            return false;
        }
        memcpy(BST->root->data, data, BST->data_size);
        BST->size = BST->size + 1;
        return true;
    }
    BinarySearchTreeNode* node = BST->root;
    BinarySearchTreeNode* node_parent = NULL;
    int compare;
    while(node) {
        compare = BST->compare(data, node->data);
        if(compare == 0) {
            return false;
        }
        node_parent = node;
        if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    node = node_create(BST->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, BST->data_size);
    if(compare < 0) {
        node_parent->left = node;
    }
    else {
        node_parent->right = node;
    }
    BST->size = BST->size + 1;

    return true;
}

bool binary_search_tree_remove(BinarySearchTree* BST, void* data)
{
    if(!BST->root) {
        return false;
    }
    BinarySearchTreeNode* node = BST->root;
    BinarySearchTreeNode* node_parent = NULL; 
    int compare;
    while(node) {
        compare = BST->compare(data, node->data);
        if(compare == 0) {
            break;
        }
        node_parent = node;
        if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    if(!node) {   
        return false;
    }
    if(!node->left && !node->right) {
        if(node_parent->left == node) {
            node_parent->left = NULL;
        }
        else {
            node_parent->right = NULL;
        }
        node_destroy(node);
    }
    else if(!node->left) {
        if(node_parent->right == node) {
            node_parent->right = node->right;
        }
        else {
            node_parent->left = node->right;
        }
        node_destroy(node);
    }
    else if(!node->right) {
        if(node_parent->left == node) {
            node_parent->left = node->left;
        }
        else {
            node_parent->right = node->left;
        }
        node_destroy(node);
    }
    else {
        BinarySearchTreeNode* node_inorder_successor = node->right;
        BinarySearchTreeNode* node_inorder_successor_parent = node;
        while(node_inorder_successor->left) {
            node_inorder_successor_parent = node_inorder_successor;
            node_inorder_successor = node_inorder_successor->left;
        }
        if(node_inorder_successor_parent == node) {
            node_inorder_successor_parent->right = node_inorder_successor->right;
        }
        else {
            node_inorder_successor_parent->left = node_inorder_successor->right;
        }
        memcpy(node->data, node_inorder_successor->data, BST->data_size);
        node_destroy(node_inorder_successor);
    }
    BST->size = BST->size - 1;
    return true;
}

void* binary_search_tree_node_data(BinarySearchTreeNode* node)
{
    if(!node) {
        return NULL;
    }
    return node->data;
}

BinarySearchTreeNode* binary_search_tree_node_left(BinarySearchTreeNode* node)
{
    if(!node) {
        return NULL;
    }
    return node->left;
}

BinarySearchTreeNode* binary_search_tree_node_right(BinarySearchTreeNode* node)
{
    if(!node) {
        return NULL;
    }
    return node->right;
}

static Stack* stack_create()
{
    Stack* S = malloc(sizeof (Stack));
    if(!S) {
        return NULL;
    }
    S->top = NULL;
    return S;
}

static BinarySearchTreeNode* stack_peek(Stack* S)
{
    if(!S->top) {
        return NULL;
    }
    return S->top->data;
}

static bool stack_push(Stack* S, BinarySearchTreeNode* data)
{
    StackNode *node = malloc(sizeof (StackNode));
    if(!node) {
        return false;
    }
    node->data = malloc(sizeof (BinarySearchTreeNode));
    if(!node->data) {
        free(node);
        node = NULL;
        return false;
    }
    memcpy(node->data, data, sizeof(BinarySearchTreeNode));
    node->next = S->top;
    S->top = node;
    return true;
}

static bool stack_pop(Stack* S)
{
    if(!S->top) {
        return false;
    }
    StackNode* node = S->top;
    S->top = S->top->next;
    free(node);
    node = NULL;
    return true;
}

void binary_search_tree_preorder_traverse(BinarySearchTree *BST,
    void (*function)(void *data))
{
    BinarySearchTreeNode* node = BST->root;
    Stack* S = stack_create();
    while(node || S->top) {
        if(node) {
            stack_push(S, node);
            node = node->left;
        }
        else {
            node = stack_peek(S);
            stack_pop(S);
            function(node->data);
            node = node->right;
        }
    }
}