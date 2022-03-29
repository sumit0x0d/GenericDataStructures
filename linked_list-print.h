#include "deque-linked_list/deque-linked_list.h"
#include "doubly_linked_list/doubly_linked_list.h"
#include "queue-linked_list/queue-linked_list.h"
#include "singly_linked_list/singly_linked_list.h"
#include "stack-linked_list/stack-linked_list.h"

#include "data-print.h"

enum {
    DEQUE_LINKED_LIST,
    DOUBLY_LINKED_LIST,
    QUEUE_LINKED_LIST,
    SINGLY_LINKED_LIST,
    STACK_LINKED_LIST
};

void deque_linked_list_print(DequeLinkedList *D, int data_type)
{
    if(!deque_linked_list_size(D)) return;
    DequeLinkedListNode *node = D->front;

    printf("[Deque (Linked List)]");

    printf("\n[Data]: ");
    do {
        data_print(node->data, data_type);
        node = node->next;
    } while(node);

    printf("\b\n[Deque][Size]\t: %zu\n", D->size);
}

// void doubly_linked_list_print(DoublyLinkedList *DLL)
// {
//     if(!DLL->size) return;

    // printf("[Doubly Linked List]");
    // printf("\n[Data]: ");
//     linked_list_traverse(DLL->head, DOUBLY_LINKED_LIST);
//     printf("\b\nDoubly Linked List Size: %zu\n", DLL->size);
// }

void queue_linked_list_print(QueueLinkedList *Q, int data_type)
{
    if(!queue_linked_list_size(Q)) return;

    QueueLinkedListNode *node = Q->front;

    printf("[Queue (Linked List)]");

    printf("\n[Data]: ");   
    do {
        data_print(node->data, data_type);
        node = node->next;
    } while(node);

    printf("\b\n[Queue]\n[Size]\t: %zu\n", Q->size);
}

void singly_linked_list_print(SinglyLinkedList *SLL, int data_type)
{
    if(!singly_linked_list_size(SLL)) return;

    SinglyLinkedListNode *node = SLL->head;
    
    printf("[Singly Linked List]");

    printf("\n[Data]: ");
    do {
        data_print(node->data, data_type);
        node = node->next;
    } while(node);

    printf("\b\n[Singly Linked List]\n[Size]\t: %zu\n", SLL->size);
}

void stack_linked_list_print(StackLinkedList *S, int data_type)
{
    if(!stack_linked_list_size(S)) return;

    StackLinkedListNode *node = S->top;

    printf("[Stack (Linked List)]");

    printf("\n[Data]\t: ");
    do {
        data_print(node->data, data_type);
        node = node->next;
    } while(node);

    printf("\b");
    printf("\n[Size]\t: %zu\n", S->size);
}
