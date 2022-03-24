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

static void linked_list_traverse(void *head, int linked_list_type)
{
    switch (linked_list_type) {
        case DEQUE_LINKED_LIST:
            {
                DequeLinkedListNode *node = head;
                do {
                    data_print(node->data, node->data_type_size);
                    node = node->next;
                } while(node);
            }
            break;
        case DOUBLY_LINKED_LIST:
            {
                DoublyLinkedListNode *node = head;
                do {
                    data_print(node->data, node->data_type_size);
                    node = node->next;
                } while(node);
            }
            break;
        case QUEUE_LINKED_LIST:
            {
                QueueLinkedListNode *node = head;
                do {
                    data_print(node->data, node->data_type_size);
                    node = node->next;
                } while(node);
            }
            break;
        case SINGLY_LINKED_LIST:
            {
                SinglyLinkedListNode *node = head;
                do {
                    data_print(node->data, node->data_type_size);
                    node = node->next;
                } while(node);
            }
            break;
        case STACK_LINKED_LIST:
            {
                StackLinkedListNode *node = head;
                do {
                    data_print(node->data, node->data_type_size);
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
    if(!D->size) return;

    printf("Deque: ");
    linked_list_traverse(D->front, DEQUE_LINKED_LIST);
    printf("\b\nDeque Size: %zu\n", D->size);
}

void doubly_linked_list_print(DoublyLinkedList *DLL)
{
    if(!DLL->size) return;

    printf("Doubly Linked List: ");
    linked_list_traverse(DLL->head, DOUBLY_LINKED_LIST);
    printf("\b\nDoubly Linked List Size: %zu\n", DLL->size);
}

void queue_linked_list_print(QueueLinkedList *Q)
{
    if(!Q->size) return;

    printf("Queue: ");   
    linked_list_traverse(Q->front, QUEUE_LINKED_LIST);
    printf("\b\nQueue Size: %zu\n", Q->size);
}

void singly_linked_list_print(SinglyLinkedList *SLL)
{
    if(!SLL->size) return;

    printf("Singly Linked List: ");
    linked_list_traverse(SLL->head, SINGLY_LINKED_LIST);
    printf("\b\nSingly Linked List Size: %zu\n", SLL->size);
}

void stack_linked_list_print(StackLinkedList *S)
{
    if(!S->size) return;

    printf("Stack: ");
    linked_list_traverse(S->top, STACK_LINKED_LIST);
    printf("\b\nStack Size: %zu\n", S->size);
}
