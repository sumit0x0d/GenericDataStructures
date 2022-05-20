#include "gds.h"

#include <stdio.h>

int compare(void* data1, void* data2) {
    if(*(int*)data1 < *(int*)data2)
        return -1;
    if(*(int *)data1 > *(int *)data2)
        return 1;
    return 0;
}

size_t hash(void* key, size_t buckets)
{
    return *(size_t *)key % buckets;
}

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


void inorder_traverse(AVLTree* AVLT)
{
    if(!AVLT->size) return;
    AVLTreeNode* node = AVLT->root;
    StackLL* S = StackLL_create(sizeof (AVLTreeNode));
    while(node || S->size) {
        if(node) {
            StackLL_push(S, node);
            node = node->left;
        }
        else {
            node = StackLL_top(S);
            printf("%d(%d) ", *(int*)node->data, node->balance_factor);
            StackLL_pop(S);
            node = node->right;
        }
    }
}

int main()
{
    // int a[24] = {10, 20, 30, 40, 50, 60, 70, 80, 930, 31100, 1010, 1024, 145, 25, 465, 1723, 536, 6404, 8013, 330, 9230, 31011, 1011, 12};
    // int a[24] = {10, 20, 15, 40, 50, 60, 70, 80, 930, 31100, 1010, 1024, 145, 25, 465, 1723, 536, 6404, 8013, 330, 9230, 31011, 1011, 12};
    // AVLTree *AVLT = AVLTree_create(sizeof (int), compare);
    // for(int i = 1; i <= 100; i++) {
    //     if(!AVLTree_insert(AVLT, &i)) {
    //         break;
    //     }
    // }
    // StackA *S = StackA_create(sizeof (int), 10);
    // int a = 39;
    // int a1 = 32;
    // int a2 = 319;
    
    // StackA_push(S, &a);
    // StackA_push(S, &a1);
    // StackA_push(S, &a2);
    // printf("%d", *(int*)StackA_top(S));
    // if(!avl_tree_insert(AVLT, &a)) {
    //     printf("error");
    // }
    // for(int i = 0; i < 5; i++) {
    //     if(!avl_tree_insert(AVLT, &a[i])) {
    //         break;
    //     }
    // }
    int b = 1;
    Matrix* M = Matrix_create(sizeof (int), 10, 10);
    Matrix_insert(M, 0, 1, &b);
    // char a = 'I';
    // char c = 'A';
    // int d = 2;
    // binary_search_tree_remove(BST, &b);
    // binary_tree_preorder_traversal(AVLT);
    // HashTableSC *HT = HashTableSC_create(sizeof (char), sizeof (int), 10, hash, compare);
    // HashTableSC_insert(HT, &a, &b);
    // HashTableSC_insert(HT, &c, &d);
    // int* i = HashTableSC_search(HT, &a);
    // if(i)
    // printf("%d", *i);
    // inorder_traverse(AVLT);
    // avl_tree_remove(AVLT, &a[3]);


}
