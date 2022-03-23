#include "data_structures.h"

union LinkedList {
    DequeLinkedList D;
    DoublyLinkedList DLL;
    QueueLinkedList Q;
    SinglyLinkedList SLL;
    StackLinkedList S;
};
