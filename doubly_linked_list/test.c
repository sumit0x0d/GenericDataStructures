#include "doubly_linked_list.h"

extern void doubly_linked_list_print(struct DoublyLinkedList *linked_list);

int main()
{
    struct DoublyLinkedList linked_list = doubly_linked_list_construct();
    for(size_t i = 0; i < 10; i++) {
        linked_list.push_front(&linked_list, &i, sizeof i);
    }
    doubly_linked_list_print(&linked_list);
}
