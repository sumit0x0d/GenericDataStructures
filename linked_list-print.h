#include "data_structures.h"

#include <stdio.h>

static void linked_list_traverse(void *node, int linked_list)
{   
    switch (linked_list) {
        case DEQUE_LINKED_LIST:
            do {
                data_print(((DequeLinkedListNode *)node)->data, ((DequeLinkedListNode *)node)->data_type_size);
                node = ((DequeLinkedListNode *)node)->next;
            } while(node);
            break;
        case DOUBLY_LINKED_LIST:
            do {
                data_print(((DoublyLinkedListNode *)node)->data, ((DoublyLinkedListNode *)node)->data_type_size);
                node = ((DoublyLinkedListNode *)node)->next;
            } while(node);
            break;
        case QUEUE_LINKED_LIST:
            do {
                data_print(((QueueLinkedListNode *)node)->data, ((QueueLinkedListNode *)node)->data_type_size);
                node = ((QueueLinkedListNode *)node)->next;
            } while(node);
            break;
        case SINGLY_LINKED_LIST:
            do {
                data_print(((SinglyLinkedListNode *)node)->data, ((SinglyLinkedListNode *)node)->data_type_size);
                node = ((SinglyLinkedListNode *)node)->next;
            } while(node);
            break;
        case STACK_LINKED_LIST:
            do {
                data_print(((StackLinkedListNode *)node)->data, ((StackLinkedListNode *)node)->data_type_size);
                node = ((StackLinkedListNode *)node)->next;
            } while(node);
            break;
        default:
            break;
    }
}

void deque_linked_list_print(DequeLinkedList *D)
{
    if(!D->size) return;

    printf("Linked List: ");
    linked_list_traverse(D->front, DEQUE_LINKED_LIST);
    printf("\b\nLinked List Size: %zu\n", D->size);
}

void doubly_linked_list_print(DoublyLinkedList *DLL)
{
    if(!DLL->size) return;

    printf("Linked List: ");
    linked_list_traverse(DLL->head, DOUBLY_LINKED_LIST);
    printf("\b\nLinked List Size: %zu\n", DLL->size);
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
