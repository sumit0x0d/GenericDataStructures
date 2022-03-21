#include "singly_linked_list.h"

extern void singly_linked_list_print(SinglyLinkedList *linked_list);

int main()
{
    int random;
    SinglyLinkedList linked_list = singly_linked_list_construct();
    for(size_t i = 0; i < 10; i++) {
        random = rand() % 1000;
        linked_list_sorted_insert(&linked_list, &random, sizeof random);
    }
}
