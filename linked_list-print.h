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

static void linked_list_traverse(void *head, int data_structure, int data_type)
{
    switch (data_structure) {
        case DEQUE_LINKED_LIST:
            {
                DequeLinkedListNode *node = head;
                do {
                    data_print(node->data, data_type);
                    node = node->next;
                } while(node);
            }
            break;
        // case DOUBLY_LINKED_LIST:
        //     {
        //         DoublyLinkedListNode *node = head;
        //         do {
        //             data_print(node->data, node->data_type);
        //             node = node->next;
        //         } while(node);
        //     }
        //     break;
        case QUEUE_LINKED_LIST:
            {
                QueueLinkedListNode *node = head;
                do {
                    data_print(node->data, data_type);
                    node = node->next;
                } while(node);
            }
            break;
        case SINGLY_LINKED_LIST:
            {
                SinglyLinkedListNode *node = head;
                do {
                    data_print(node->data, data_type);
                    node = node->next;
                } while(node);
            }
            break;
        case STACK_LINKED_LIST:
            {
                StackLinkedListNode *node = head;
                do {
                    data_print(node->data, data_type);
                    node = node->next;
                } while(node);
                break;
            }
        default:
            break;
    }
}

void deque_linked_list_print(DequeLinkedList *D)
{
    if(!deque_linked_list_size(&D)) return;

    printf("[Deque (Linked List)]");

    printf("\n[Data]: ");
    linked_list_traverse(D->front, DEQUE_LINKED_LIST, D->data_type);

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

void queue_linked_list_print(QueueLinkedList *Q)
{
    if(!queue_linked_list_size(&Q)) return;

    printf("[Queue (Linked List)]");

    printf("\n[Data]: ");   
    linked_list_traverse(Q->front, QUEUE_LINKED_LIST, Q->data_type);

    printf("\b\n[Queue]\n[Size]\t: %zu\n", Q->size);
}

void singly_linked_list_print(SinglyLinkedList *SLL)
{
    if(!singly_linked_list_size(&SLL)) return;

    printf("[Singly Linked List]");

    printf("\n[Data]: ");
    linked_list_traverse(SLL->head, SINGLY_LINKED_LIST, SLL->data_type);

    printf("\b\n[Singly Linked List]\n[Size]\t: %zu\n", SLL->size);
}

void stack_linked_list_print(StackLinkedList *S)
{
    if(!stack_linked_list_size(&S)) return;

    printf("[Stack (Linked List)]");

    printf("\n[Data]\t: ");
    linked_list_traverse(S->top, STACK_LINKED_LIST, S->data_type);

    printf("\b");
    printf("\n[Size]\t: %zu\n", S->size);
}
