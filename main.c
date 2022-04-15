#include "deque-linked_list/deque-linked_list.h"
#include "doubly_linked_list/doubly_linked_list.h"
#include "queue-linked_list/queue-linked_list.h"
#include "singly_linked_list/singly_linked_list.h"
#include "stack-linked_list/stack-linked_list.h"
#include "avl_tree/avl_tree.h"
#include "binary_search_tree/binary_search_tree.h"
#include "red-black_tree/red-black_tree.h"
#include "deque-array/deque-array.h"
#include "dynamic_array/dynamic_array.h"
#include "queue-array/queue-array.h"
#include "stack-array/stack-array.h"
#include "hash_table-separate_chaining/hash_table-separate_chaining.h"

#include <stdio.h>

int compare(void* data, void* node_data) {
    if(*(int*)data < *(int*)node_data)
        return -1;
    else if(*(int *)data > *(int *)node_data)
        return 1;
    return 0;
}

size_t hash(void* key, size_t buckets)
{
    return (*(size_t *)key % buckets);
}

void array_print(void* A, size_t data_size, size_t begin, size_t end, size_t size)
{
    if(!A) return;
    printf("\n[Data]\t: ");
    for(size_t i = begin; i < end; i++) {
        printf("%d ", *(int *)((char *)A + (data_size * i)));
    }
    printf("\n[Size]\t: %zu\n", size);
}

void binary_search_tree_print(BinarySearchTree* BST)
{
    // if(!binary_search_tree_size(BST)) return;

    printf("[Binary Search Tree]");

    printf("\n[Pre-Order]\t: ");
    StackLinkedList* S = stack_linked_list_create(sizeof (BinarySearchTreeNode*));
    BinarySearchTreeNode* node = binary_search_tree_root(BST);
    while(node || stack_linked_list_size(S))
        if(node) {
            printf("%d", *(int*)binary_search_tree_data(node));
            stack_linked_list_push(S, node);
            node = binary_search_tree_left(node);
        }
        else {
            node = stack_linked_list_peek(S);
            stack_linked_list_pop(&S);
            node = binary_search_tree_right(node);
        }

    printf("\n[In-Order]\t: ");
    // inorder_traverse(BST->root, BINARY_SEARCH_TREE, data_type);
    
    // printf("\n[Lever-Order]\t: ");
    // levelorder_traverse(BST->root, BINARY_SEARCH_TREE, data_type);

    // printf("\b\n[Size]\t: %zu\n", BST->size);
}

// void linked_list_print(void* head, void* tail, void *next)
// {
//     if(!head) return;
//     printf("\n[Data]\t: ");
//     do {
//         printf("%d", *(int*)linked_list_node_data(node));
//         node = linked_list_node_next(node);
//     } while(node);

//     printf("\b");
//     printf("\n[Size]\t: %zu\n", stack_linked_list_size(S));
// }
int main()
{
    int a[10] = {10, 20, 15, 5, 50, 40, 25, 35, 95, 55};
    BinarySearchTree *BST = binary_search_tree_create(sizeof (int), compare);
    for(int i = 0; i < 10; i++) {
        binary_search_tree_insert(BST, &a[i]);
    }
}
