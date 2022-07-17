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
//     printf("\n[Size]\t: %zu\n", stack_linked_listSize(S));
// // }


// void inorderTraverse(AVLTree* AVLT)
// {
//     if(!AVLT->size) return;
//     AVLTreeNode* node = AVLT->root;
//     StackLL* S = StackLLCreate(sizeof (AVLTreeNode));
//     while(node || S->size) {
//         if(node) {
//             StackLLPush(S, node);
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
//         printf("%d ", *(int*)ArrayAt(A, i));
//     }
// }

int main()
{
    // int a[24] = {10, 20, 30, 40, 50, 60, 70, 80, 930, 31100, 1010, 1024, 145, 25, 465, 1723, 536, 6404, 8013, 330, 9230, 31011, 1011, 12};
    // int a[24] = {10, 20, 15, 40, 50, 60, 70, 80, 930, 31100, 1010, 1024, 145, 25, 465, 1723, 536, 6404, 8013, 330, 9230, 31011, 1011, 12};
    // AVLTree *AVLT = AVLTreeCreate(sizeof (int), compare_function);
    // for(int i = 1; i <= 100; i++) {
    //     if(!AVLTreeInsert(AVLT, &i)) {
    //         break;
    //     }
    // }
    int a1 = 32;
    int a2 = 319;
    StackLL* S = StackLLCreate(sizeof (int));
    StackLLPush(S, &a1);
    StackLLPush(S, &a2);
    printf("%d", *(int*)StackLL_top(S));
    QueueLL* Q = QueueLLCreate(sizeof (int));
    QueueLLEnqueue(Q, &a1);
    QueueLLEnqueue(Q, &a2);
    printf("%d", *(int*)QueueLLFront(Q));
    // if(!avl_treeInsert(AVLT, &a)) {
    //     printf("error");
    // }
    // for(int i = 0; i < 5; i++) {
    //     if(!avl_treeInsert(AVLT, &a[i])) {
    //         break;
    //     }
    // }
    // int da = 10;
    // int pa = 0;
    // int db = 15;
    // int pb = 15;
    // PriorityQueueA* PQ = PriorityQueueACreate(sizeof (int), sizeof (int), 10, compare_function);
    // PriorityQueueAEnqueue(PQ, &da, &pa);
    // PriorityQueueAEnqueue(PQ, &db, &pb);
    // PriorityQueueADequeue(PQ);
    // printf("%d", *(int *)PriorityQueueAFront(PQ));
    // BloomFilter* BF = BloomFilterCreate();
    // int b = 20;
    // int a = 21;
    // int c = 11;
    // int c1 = 12;
    // int c2 = 13;
    // int c5 = 1000;
    // Matrix* M = MatrixCreate(sizeof (char), 10, 10);
    // MatrixInsert(M, 0, 1, &b);
    // QueueADequeue(S);
    // HashTableOA *HT = HashTableOACreate(sizeof (char), sizeof (int), 10, hash_function, compare_function);
    // HashTableOAInsert(HT, &b, &c);
    // Array* A = ArrayCreate(sizeof (int), 10, compare_function);
    // ArraySortedInsert(A, &b);
    // ArraySortedInsert(A, &a);
    // ArraySortedInsert(A, &c1);
    // ArraySortedInsert(A, &c2);
    // ArraySortedInsert(A, &c);
    // ArraySortedInsert(A, &c);
    // ArraySortedInsert(A, &c5);
    // array_print(A);
    // printf("%d", *(int*)QueueAFront(S));
    // int d = 2;
    // binarySearch_treeRemove(BST, &b);
    // binary_tree_preorder_traversal(AVLT);
    // HashTableSCInsert(HT, &a, &b);
    // HashTableSCInsert(HT, &c, &d);
    // int* i = HashTableSCSearch(HT, &a);
    // if(i)
    // printf("%d", *i);
    // inorderTraverse(AVLT);
    // avl_treeRemove(AVLT, &a[3]);


}
