#include "data_structures.h"

#include <stdio.h>

static void data_print(void *data, size_t data_type_size)
{
    switch (data_type_size) {
        case SIZE_CHAR:
            printf("%c ", *(char *)data);
            break;
        case SIZE_SHORT:
            printf("%u ", *(int *)data);
            break;
        case SIZE_INT:
            printf("%f ", *(float *)data);
            break;
        // case SIZE_FLOAT:
        //     printf("%ld ", *(long *)data);
        //     break;
        // case SIZE_LONG:
        //     printf("%ld ", *(long *)data);
        //     break;
        case SIZE_DOUBLE:
            printf("%ld ", *(long *)data);
            break;
        default:
            break;
    }
} 

static void node_traverse(void *node, int node_type)
{   
    switch (node_type) {
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
    DequeLinkedListNode *node = D->front;

    printf("Linked List: ");

    node_traverse(node, DEQUE_LINKED_LIST);

    printf("\b\nLinked List Size: %zu\n", D->size);
}

void doubly_linked_list_print(DoublyLinkedList *DLL)
{
    DoublyLinkedListNode *node = DLL->head;

    printf("Linked List: ");

    node_traverse(node, DOUBLY_LINKED_LIST);

    printf("\b\nLinked List Size: %zu\n", DLL->size);
}

void queue_linked_list_print(QueueLinkedList *Q)
{
    QueueLinkedListNode *node = Q->front;

    printf("Queue: ");
    
    node_traverse(node, QUEUE_LINKED_LIST);

    printf("\b\nQueue Size: %zu\n", Q->size);
}

void singly_linked_list_print(SinglyLinkedList *SLL)
{
    SinglyLinkedListNode *node = SLL->head;

    printf("Singly Linked List: ");

    node_traverse(node, SINGLY_LINKED_LIST);

    printf("\b\nSingly Linked List Size: %zu\n", SLL->size);
}

void stack_linked_list_print(StackLinkedList *S)
{
    StackLinkedListNode *node = S->top;

    printf("Stack: ");

    node_traverse(node, STACK_LINKED_LIST);

    printf("\b\nStack Size: %zu\n", S->size);
}
