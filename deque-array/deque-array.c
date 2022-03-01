#include "deque-array.h"

struct Deque *deque_construct(size_t capacity)
{
    struct Deque *deque = malloc(sizeof(struct Deque));
    if(!deque) return;

    deque->array = malloc(sizeof(sizeof(int) * capacity));
    if(!deque->array) {
        free(deque);
        deque = NULL;
        return NULL;
    };

    deque->size = 0;
    deque->capacity = capacity;

    return deque;
}

void deque_distroy(struct Deque *deque)
{

}

void deque_push_front(struct Deque *deque, int data)
{
    
}

void deque_push_back(struct Deque *deque, int data)
{
    if(deque->back != deque->size-1) {
        deque->back++;
        deque->array[deque->back] = data;
    }
}

void deque_pop_front(struct Deque *deque)
{
    if(deque->front != deque->back) {
        deque->front++;
    }
}

void deque_pop_back(struct Deque *deque)
{
    
}
