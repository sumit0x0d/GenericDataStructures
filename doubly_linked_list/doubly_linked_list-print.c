#include "doubly_linked_list.h"

#include <stdio.h>

void doubly_linked_list_print(DoublyLinkedList *DLL)
{DLL
    if(!DLL->size) return;

    DoublyLinkedListNode *node = DLL->head;
    printf("Doubly Linked List: ");
    do {
        printf("%d ", node->data);
        node = node->next;
    } while(node);
    printf("\b\nDoubly Linked List Size: %zu\n", DLL->size);
}
