#include "singly_linked_list.h"

#include <stdlib.h>
#include <time.h>

int main()
{
    int random;
    struct LinkedList linked_list = linked_list_construct();
    for(size_t i = 0; i < 10; i++) {
        random = rand() % 1000;
        linked_list.sorted_insert(&linked_list, random);
    }
}
