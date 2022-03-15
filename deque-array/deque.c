#include "deque.h"

struct Deque *deque_construct(size_t capacity)
{
    struct Deque *D = malloc(sizeof (struct Deque));
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

void deque_distroy(struct Deque *D)
{

}

void deque_push_front(struct Deque *D, int data)
{
    
}

void deque_push_back(struct Deque *D, int data)
{
    if(D->back != D->size-1) {
        D->back = D->back + 1;
        D->array[D->back] = data;
    }
}

void deque_pop_front(struct Deque *D)
{
    if(D->front != D->back) {
        D->front = D->front + 1;
    }
}

void deque_pop_back(struct Deque *D)
{
    
}
