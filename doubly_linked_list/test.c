// #include "doubly_linked_list.h"
#include "singly_linked_list.h"

#include <time.h>

int main()
{
    srand(time(0));
    int random;
    // struct DoublyLinkedList *doubly_linked_list = doubly_linked_list_construct();
    struct SinglyLinkedList *singly_linked_list = singly_linked_list_construct();
    for(size_t i = 0; i < 10; i++) {
        random = rand() % 1000;
    //     // doubly_linked_list_push_front(doubly_linked_list, random);
        singly_linked_list_sorted_insert(singly_linked_list, random);
    }
    // doubly_linked_list_print(doubly_linked_list);
    singly_linked_list_print(singly_linked_list);
}
