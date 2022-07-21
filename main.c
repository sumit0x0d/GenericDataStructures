#include "GenericDataStructures.h"

#include <stdio.h>

int compare_function(void* data1, void* data2) {
    if(*(int*)data1 < *(int*)data2)
        return -1;
    if(*(int *)data1 > *(int *)data2)
        return true;
    return false;
}

size_t hash_function(void* key, size_t bucket_count)
{
    return *(size_t *)key % bucket_count;
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
//     printf("\n[_Size]\t: %zu\n", stack_linked_list_Size(S));
// // }


// void inorder_Traverse(AVLTree* AVLT)
// {
//     if(!AVLT->size) return;
//     AVLTreeNode* node = AVLT->root;
//     StackLL* S = StackLL_Create(sizeof (AVLTreeNode));
//     while(node || S->size) {
//         if(node) {
//             StackLL_Push(S, node);
//             node = node->left;
//         }
//         else {
//             node = StackLL_top(S);
//             printf("%d(%d) ", *(int*)node->data, node->balance_factor);
//             StackLLPop(S);
//             node = node->right;
//         }
//     }
// }

// void array_print(Array* A)
// {
//     for(size_t i = 0; i < A->size; i++) {
//         printf("%d ", *(int*)Array_At(A, i));
//     }
// }

int main()
{
    // int a[24] = {10, 20, 30, 40, 50, 60, 70, 80, 930, 31100, 1010, 1024, 145, 25, 465, 1723, 536, 6404, 8013, 330, 9230, 31011, 1011, 12};
    // int a[24] = {10, 20, 15, 40, 50, 60, 70, 80, 930, 31100, 1010, 1024, 145, 25, 465, 1723, 536, 6404, 8013, 330, 9230, 31011, 1011, 12};
    // AVLTree *AVLT = AVLTree_Create(sizeof (int), compare_function);
    // for(int i = 1; i <= 100; i++) {
    //     if(!AVLTree_Insert(AVLT, &i)) {
    //         break;
    //     }
    // }
    int a1 = 32;
    int a2 = 319;
    StackLL* S = StackLL_Create(sizeof (int));
    StackLL_Push(S, &a1);
    StackLL_Push(S, &a2);
    printf("%d", *(int*)StackLL_top(S));
    QueueLL* Q = QueueLL_Create(sizeof (int));
    QueueLL_Enqueue(Q, &a1);
    QueueLL_Enqueue(Q, &a2);
    printf("%d", *(int*)QueueLL_Front(Q));
    // if(!avl_tree_Insert(AVLT, &a)) {
    //     printf("error");
    // }
    // for(int i = 0; i < 5; i++) {
    //     if(!avl_tree_Insert(AVLT, &a[i])) {
    //         break;
    //     }
    // }
    // int da = 10;
    // int pa = 0;
    // int db = 15;
    // int pb = 15;
    // PriorityQueueA* PQ = PriorityQueueA_Create(sizeof (int), sizeof (int), 10, compare_function);
    // PriorityQueueA_Enqueue(PQ, &da, &pa);
    // PriorityQueueA_Enqueue(PQ, &db, &pb);
    // PriorityQueueA_Dequeue(PQ);
    // printf("%d", *(int *)PriorityQueueA_Front(PQ));
    // BloomFilter* BF = BloomFilter_Create();
    // int b = 20;
    // int a = 21;
    // int c = 11;
    // int c1 = 12;
    // int c2 = 13;
    // int c5 = 1000;
    // Matrix* M = Matrix_Create(sizeof (char), 10, 10);
    // Matrix_Insert(M, 0, 1, &b);
    // QueueA_Dequeue(S);
    // HashTableOA *HT = HashTableOA_Create(sizeof (char), sizeof (int), 10, hash_function, compare_function);
    // HashTableOA_Insert(HT, &b, &c);
    // Array* A = Array_Create(sizeof (int), 10, compare_function);
    // Array_SortedInsert(A, &b);
    // Array_SortedInsert(A, &a);
    // Array_SortedInsert(A, &c1);
    // Array_SortedInsert(A, &c2);
    // Array_SortedInsert(A, &c);
    // Array_SortedInsert(A, &c);
    // Array_SortedInsert(A, &c5);
    // array_print(A);
    // printf("%d", *(int*)QueueA_Front(S));
    // int d = 2;
    // binary_Search_tree_Remove(BST, &b);
    // binary_tree_preorder_traversal(AVLT);
    // HashTableSC_Insert(HT, &a, &b);
    // HashTableSC_Insert(HT, &c, &d);
    // int* i = HashTableSC_Search(HT, &a);
    // if(i)
    // printf("%d", *i);
    // inorder_Traverse(AVLT);
    // avl_tree_Remove(AVLT, &a[3]);


}
