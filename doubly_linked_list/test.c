#include "doubly_linked_list.h"


int main()
{
    struct DoublyLinkedList *linked_list = doubly_linked_list_construct();
    for(size_t i = 0; i < 10; i++) {
        doubly_linked_list_push_front(linked_list, &i);
    }
    doubly_linked_list_print(linked_list);
}
