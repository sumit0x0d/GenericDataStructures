#include "deque.h"

Deque *deque_construct(size_t capacity)
{
    Deque *D = malloc(sizeof (Deque));
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

void deque_distroy(Deque *D)
{

}

void deque_push_front(Deque *D, int data)
{
    
}

void deque_push_back(Deque *D, int data)
{
    if(D->back != D->size-1) {
        D->back = D->back + 1;
        D->array[D->back] = data;
    }
}

void deque_pop_front(Deque *D)
{
    if(D->front != D->back) {
        D->front = D->front + 1;
    }
}

void deque_pop_back(Deque *D)
{
    
}
