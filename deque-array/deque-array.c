#include "deque-array.h"

DequeArray deque_array_create(size_t element_size, size_t capacity);
void deque_array_destroy(DequeArray *D);

void *deque_array_front(DequeArray *D);
void *deque_array_back(DequeArray *D);
size_t deque_array_size(DequeArray *D);

bool deque_array_push_front(DequeArray *D, void *data);
bool deque_array_push_back(DequeArray *D, void *data);
bool deque_array_pop_front(DequeArray *D);
bool deque_array_pop_back(DequeArray *D);


DequeArray deque_array_create(size_t element_size, size_t capacity)
{
    DequeArray D;

    D.array = NULL;
    D.element_size = element_size;
    D.front = 0;
    D.back = 0;
    D.size = 0;
    D.capacity = capacity;

    return D;
}

// void deque_array_destroy(DequeArray *D)
// {

// }

// void *deque_array_front(DequeArray *D)
// {

// }

// void *deque_array_back(DequeArray *D)
// {

// }

// size_t deque_array_size(DequeArray *D)
// {

// }

// bool deque_array_push_front(DequeArray *D, void *data)
// {
    
// }

bool deque_array_push_back(DequeArray *D, void *data)
{
    if(!D->array) {
        D->array = malloc(D->element_size * D->capacity);
        if(!D->array) return false;
    }

    if(D->back == D->capacity) return false;

    memcpy((char *)D->array + (D->element_size * D->back), data, D->element_size);
    
    D->back = D->back + 1;
    D->size = D->size + 1;

    return true;
}

// bool deque_array_pop_front(DequeArray *D)
// {
//     if(D->front != D->back) {
//         D->front = D->front + 1;
//     }
// }

// bool deque_array_pop_back(DequeArray *D)
// {
    
// }
