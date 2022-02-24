#include "deque-array.h"

void deque_print(struct Deque *deque)
{
    printf("Deque: ");
    size_t i = deque->front;
    while(i < deque->back-1) {
        printf("%d ", deque->array[i]);
        i++;
    }
    printf("%d\n", deque->array[i]);
    printf("Deque Size: %zu\n", deque->size);
    printf("deque Capacity: %zu\n", deque->capacity);
}

struct Deque *deque_construct(size_t capacity)
{
    struct Deque *deque = malloc(sizeof(struct Deque));
    assert(deque);
    deque->array = malloc(sizeof(sizeof(int) * capacity));
    assert(deque->array);
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
