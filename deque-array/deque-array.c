#include "deque-array.h"

DequeArray *deque_array_construct(size_t capacity)
{
    DequeArray *D = malloc(sizeof (DequeArray));
    if(!D) return;

    D->array = malloc(sizeof (sizeof (int) * capacity));
    if(!D->array) {
        free(D);
        D = NULL;
        return NULL;
    };

    D->size = 0;
    D->capacity = capacity;

    return D;
}

void deque_array_distroy(DequeArray *D)
{

}

bool deque_array_push_front(DequeArray *D, int data)
{
    
}

bool deque_array_push_back(DequeArray *D, int data)
{
    if(D->back != D->size-1) {
        D->back = D->back + 1;
        D->array[D->back] = data;
    }
}

bool deque_array_pop_front(DequeArray *D)
{
    if(D->front != D->back) {
        D->front = D->front + 1;
    }
}

bool deque_array_pop_back(DequeArray *D)
{
    
}
