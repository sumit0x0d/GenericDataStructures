#include "generic_data_structures.h"

#include <stdio.h>

int compare(void* data1, void* data2) {
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
    // char c = 'A';
    // int d = 2;
    // binary_search_tree_remove(BST, &b);
    // binary_tree_preorder_traversal(AVLT);
    HashTableSC *HT = HashTableSC_create(sizeof (char), sizeof (int), 10, hash, compare);
    HashTableSC_insert(HT, &a, &b);
    // HashTableSC_insert(HT, &c, &d);
    int* i = HashTableSC_search(HT, &a);
    if(i)
    printf("%d", *i);
    // binary_tree_inorder_traversal(AVLT);
    // avl_tree_remove(AVLT, &a[3]);


}
