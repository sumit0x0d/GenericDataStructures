#include "Queue-LinkedList/Queue-LinkedList.h"
#include "Stack-Array/Stack-Array.h"
#include "gds.h"

#include <stdio.h>

int compare(void* data1, void* data2) {
    if(*(int*)data1 < *(int*)data2)
        return -1;
    if(*(int *)data1 > *(int *)data2)
        return true;
    return false;
}

size_t hash(void* key, size_t bucket_count)
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
//     printf("\n[Size]\t: %zu\n", stack_linked_list_size(S));
// // }


// void inorder_traverse(AVLTree* AVLT)
// {
//     if(!AVLT->size) return;
//     AVLTreeNode* node = AVLT->root;
//     StackLL* S = StackLL_create(sizeof (AVLTreeNode));
//     while(node || S->size) {
//         if(node) {
//             StackLL_push(S, node);
//             node = node->left;
//         }
//         else {
//             node = StackLL_top(S);
//             printf("%d(%d) ", *(int*)node->data, node->balance_factor);
//             StackLL_pop(S);
//             node = node->right;
//         }
//     }
// }

void array_print(Array* A)
{
    for(size_t i = 0; i < A->size; i++) {
        printf("%d ", *(int*)Array_at(A, i));
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
    int a1 = 32;
    int a2 = 319;
    StackLL* S = StackLL_create(sizeof (int));
    StackLL_push(S, &a1);
    StackLL_push(S, &a2);
    printf("%d", *(int*)StackLL_top(S));
    QueueLL* Q = QueueLL_create(sizeof (int));
    QueueLL_enqueue(Q, &a1);
    QueueLL_enqueue(Q, &a2);
    printf("%d", *(int*)QueueLL_front(Q));
    // if(!avl_tree_insert(AVLT, &a)) {
    //     printf("error");
    // }
    // for(int i = 0; i < 5; i++) {
    //     if(!avl_tree_insert(AVLT, &a[i])) {
    //         break;
    //     }
    // }
    // int da = 10;
    // int pa = 0;
    // int db = 15;
    // int pb = 15;
    // PriorityQueueA* PQ = PriorityQueueA_create(sizeof (int), sizeof (int), 10, compare);
    // PriorityQueueA_enqueue(PQ, &da, &pa);
    // PriorityQueueA_enqueue(PQ, &db, &pb);
    // PriorityQueueA_dequeue(PQ);
    // printf("%d", *(int *)PriorityQueueA_front(PQ));
    // BloomFilter* BF = BloomFilter_create();
    // int b = 20;
    // int a = 21;
    // int c = 11;
    // int c1 = 12;
    // int c2 = 13;
    // int c5 = 1000;
    // Matrix* M = Matrix_create(sizeof (char), 10, 10);
    // Matrix_insert(M, 0, 1, &b);
    // QueueA_dequeue(S);
    // HashTableOA *HT = HashTableOA_create(sizeof (char), sizeof (int), 10, hash, compare);
    // HashTableOA_insert(HT, &b, &c);
    // Array* A = Array_create(sizeof (int), 10, compare);
    // Array_sorted_insert(A, &b);
    // Array_sorted_insert(A, &a);
    // Array_sorted_insert(A, &c1);
    // Array_sorted_insert(A, &c2);
    // Array_sorted_insert(A, &c);
    // Array_sorted_insert(A, &c);
    // Array_sorted_insert(A, &c5);
    // array_print(A);
    // printf("%d", *(int*)QueueA_front(S));
    // int d = 2;
    // binary_search_tree_remove(BST, &b);
    // binary_tree_preorder_traversal(AVLT);
    // HashTableSC_insert(HT, &a, &b);
    // HashTableSC_insert(HT, &c, &d);
    // int* i = HashTableSC_search(HT, &a);
    // if(i)
    // printf("%d", *i);
    // inorder_traverse(AVLT);
    // avl_tree_remove(AVLT, &a[3]);


}
