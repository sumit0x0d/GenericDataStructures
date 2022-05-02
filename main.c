#include "GenericDataStructures.h"

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
        printf("%d ", *(int *)((char* )A + (data_size * i)));
    }
    printf("\n[Size]\t: %zu\n", size);
}

void binary_tree_preorder_traversal(AVLTree* AVLT)
{
    if(!AVLT->size) return;
    printf("[Binary Tree]");
    printf("\n[Pre-Order] : ");
    AVLTreeNode* node = AVLT->root;
    StackLL* S = StackLL_create(sizeof (AVLTreeNode));
    while(node || S->size) {
        if(node) {
            StackLL_push(S, node);
            printf("%d(%d) ", *(int*)node->data, node->balance_factor);
            node = node->left;
        }
        else {
            node = S->top->data;
            StackLL_pop(S);
            node = node->right;
        }
    }
    printf("\b\n[Size]\t: %zu\n", AVLT->size);
}

void binary_tree_inorder_traversal(AVLTree* AVLT)
{
    if(!AVLT->size) return;
    printf("[Binary Tree]");
    printf("\n[In-Order] : ");
    AVLTreeNode* node = AVLT->root;
    StackLL* S = StackLL_create(sizeof (AVLTreeNode));
    while(node || S->size) {
        if(node) {
            StackLL_push(S, node);
            node = node->left;
        }
        else {
            node = S->top->data;
            StackLL_pop(S);
            printf("%d(%d) ", *(int*)node->data, node->balance_factor);
            node = node->right;
        }
    }
    printf("\b\n[Size]\t: %zu\n", AVLT->size);
}

// void binary_tree_levelorder_traversal(AVLTree* AVLT)
// {
//     QueueLL *Q = QueueLL_create(sizeof (AVLTreeNode*));
//     AVLTreeNode* node = avl_tree_begin(AVLT);
//     printf("%d(%d) ", *(int*)avl_tree_node_data(node), avl_tree_node_balance_factor(node));
//     QueueLL_enqueue(&Q, &node);
//     while(QueueLL_size(&Q)) {
//         node = QueueLL_front(&Q);
//         QueueLL_dequeue(&Q);
//         if(avl_tree_node_left(node)) {
//             printf("%d(%d) ", *(int*)avl_tree_node_data(node), avl_tree_node_balance_factor(node));
//             QueueLL_enqueue(&Q, avl_tree_node_left(node));
//         }
//         if( avl_tree_node_right(node)) {
//             printf("%d(%d) ", *(int*)avl_tree_node_data(node), avl_tree_node_balance_factor(node));
//             QueueLL_enqueue(&Q, avl_tree_node_right(node));
//         }
//     }
// }

// void binary_tree_postorder_traversal(AVLTree* AVLT)
// {
//     if(!avl_tree_size(AVLT)) return;
//     printf("[Binary Tree]");
//     printf("\n[In-Order] : ");
//     AVLTreeNode* node = avl_tree_begin(AVLT);
//     StackLL* S = stack_linked_list_create(sizeof (AVLTreeNode*));
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
    // int a[24] = {10, 20, 30, 40, 50, 60, 70, 80, 930, 31100, 1010, 1024, 145, 25, 465, 1723, 536, 6404, 8013, 330, 9230, 31011, 1011, 12};
    // int a[24] = {10, 20, 15, 40, 50, 60, 70, 80, 930, 31100, 1010, 1024, 145, 25, 465, 1723, 536, 6404, 8013, 330, 9230, 31011, 1011, 12};
    // AVLTree *AVLT = AVLTree_create(sizeof (int), compare);
    // for(int i = 1; i <= 80; i++) {
    //     if(!AVLTree_insert(AVLT, &i)) {
    //         break;
    //     }
    // }
    // int a = 39;
    // if(!avl_tree_insert(AVLT, &a)) {
    //     printf("error");
    // }
    // for(int i = 0; i < 5; i++) {
    //     if(!avl_tree_insert(AVLT, &a[i])) {
    //         break;
    //     }
    // }
    char a = 'I';
    int b = 1;
    // binary_search_tree_remove(BST, &b);
    // binary_tree_preorder_traversal(AVLT);
    HashTableSC *HT = HashTableSC_create(sizeof (char), sizeof (int), 100, hash, compare);
    HashTableSC_insert(HT, &a, &b);
    // binary_tree_inorder_traversal(AVLT);
    // avl_tree_remove(AVLT, &a[3]);

}
