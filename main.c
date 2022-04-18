#include "generic_data_structures.h"

#include <stdio.h>

int compare(void* data, void* node_data) {
    if(*(int*)data < *(int*)node_data)
        return -1;
    if(*(int *)data > *(int *)node_data)
        return 1;
    return 0;
}

size_t hash(void* key, size_t buckets)
{
    return *(size_t *)key % buckets;
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

void binary_tree_preorder_traversal(AVLTree* AVLT)
{
    if(!avl_tree_size(AVLT)) return;
    printf("[Binary Tree]");
    printf("\n[Pre-Order] : ");
    AVLTreeNode* node = avl_tree_begin(AVLT);
    StackLinkedList* S = stack_linked_list_create(sizeof (AVLTreeNode*));
    while(node || stack_linked_list_size(S)) {
        if(node) {
            printf("%d(%d) ", *(int*)avl_tree_node_data(node), avl_tree_node_balance_factor(node));
            stack_linked_list_push(S, &node);
            node = avl_tree_node_left(node);
        }
        else {
            node = *(AVLTreeNode **)stack_linked_list_peek(S);
            stack_linked_list_pop(S);
            node = avl_tree_node_right(node);
        }
    }
    printf("\b\n[Size]\t: %zu\n", avl_tree_size(AVLT));
}

void binary_tree_inorder_traversal(AVLTree* AVLT)
{
    if(!avl_tree_size(AVLT)) return;
    printf("[Binary Tree]");
    printf("\n[In-Order] : ");
    AVLTreeNode* node = avl_tree_begin(AVLT);
    StackLinkedList* S = stack_linked_list_create(sizeof (AVLTreeNode*));
    while(node || stack_linked_list_size(S)) {
        if(node) {
            stack_linked_list_push(S, &node);
            node = avl_tree_node_left(node);
        }
        else {
            node = *(AVLTreeNode **)stack_linked_list_peek(S);
            stack_linked_list_pop(S);
            printf("%d(%d) ", *(int*)avl_tree_node_data(node), avl_tree_node_balance_factor(node));
            node = avl_tree_node_right(node);
        }
    }
    printf("\b\n[Size]\t: %zu\n", avl_tree_size(AVLT));
}

// void binary_tree_levelorder_traversal(AVLTree* AVLT)
// {
//     QueueLinkedList *Q = queue_linked_list_create(sizeof (AVLTreeNode*));
//     AVLTreeNode* node = avl_tree_begin(AVLT);
//     printf("%d(%d) ", *(int*)avl_tree_node_data(node), avl_tree_node_balance_factor(node));
//     queue_linked_list_enqueue(&Q, &node);
//     while(queue_linked_list_size(&Q)) {
//         node = queue_linked_list_front(&Q);
//         queue_linked_list_dequeue(&Q);
//         if(avl_tree_node_left(node)) {
//             printf("%d(%d) ", *(int*)avl_tree_node_data(node), avl_tree_node_balance_factor(node));
//             queue_linked_list_enqueue(&Q, avl_tree_node_left(node));
//         }
//         if( avl_tree_node_right(node)) {
//             printf("%d(%d) ", *(int*)avl_tree_node_data(node), avl_tree_node_balance_factor(node));
//             queue_linked_list_enqueue(&Q, avl_tree_node_right(node));
//         }
//     }
// }

// void binary_tree_postorder_traversal(AVLTree* AVLT)
// {
//     if(!avl_tree_size(AVLT)) return;
//     printf("[Binary Tree]");
//     printf("\n[In-Order] : ");
//     AVLTreeNode* node = avl_tree_begin(AVLT);
//     StackLinkedList* S = stack_linked_list_create(sizeof (AVLTreeNode*));
//     while(node || stack_linked_list_size(S)) {
//         if(node) {
//             stack_linked_list_push(S, &node);
//             node = avl_tree_node_left(node);
//         }
//         else {
//             node = *(AVLTreeNode **)stack_linked_list_peek(S);
//             stack_linked_list_pop(S);
//             printf("%d(%d) ", *(int*)avl_tree_node_data(node), avl_tree_node_balance_factor(node));
//             node = avl_tree_node_right(node);
//         }
//     }
//     printf("\b\n[Size]\t: %zu\n", avl_tree_size(AVLT));
// }

// void linked_list_print(void* begin, void* end)
// {
//     if(!head) return;
//     printf("\n[Data]\t: ");
//     do {
//         printf("%d", *(int*)linked_list_node_data(node));
//         node = linked_list_node_next(node);
//     } while(node);

//     printf("\b");
//     printf("\n[Size]\t: %zu\n", stack_linked_list_size(S));
// // }

int main()
{
    int a[10] = {10, 3, 15, 5, 50, 40, 25, 35, 95, 55};
    AVLTree *AVLT = avl_tree_create(sizeof (int), compare);
    for(int i = 0; i < 10; i++) {
        avl_tree_insert(AVLT, &a[i]);
    }
    // int b = 40;
    // binary_search_tree_remove(BST, &b);
    binary_tree_preorder_traversal(AVLT);
    binary_tree_inorder_traversal(AVLT);
    avl_tree_remove(AVLT, &a[3]);
    binary_tree_preorder_traversal(AVLT);
    binary_tree_inorder_traversal(AVLT);
    // binary_tree_postorder_traversal(AVLT);
    // binary_tree_levelorder_traversal(AVLT);
}
