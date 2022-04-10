#include "deque-array.h"

typedef struct DequeArray {
    void *array;
    size_t data_size;
    size_t front;
    size_t back;
    size_t capacity;
    size_t size;
} DequeArray;

DequeArray *deque_array_create(size_t data_size, size_t capacity);
bool deque_array_change_capacity(DequeArray *D, size_t capacity);
void deque_array_destroy(DequeArray *D);

void *deque_array_front(DequeArray *D);
void *deque_array_back(DequeArray *D);
size_t deque_array_size(DequeArray *D);

bool deque_array_push_front(DequeArray *D, void *data);
bool deque_array_push_back(DequeArray *D, void *data);
bool deque_array_pop_front(DequeArray *D);
bool deque_array_pop_back(DequeArray *D);

DequeArray *deque_array_create(size_t data_size, size_t capacity)
{
    DequeArray *D = malloc(sizeof (DequeArray));
    if(!D) return NULL;

    D->array = D->array = malloc(data_size * capacity);
    if(!D->array) return NULL;

    D->data_size = data_size;
    D->front = 0;
    D->back = 0;
    D->capacity = capacity;
    D->size = 0;

    return D;
}

bool deque_array_change_capacity(DequeArray *D, size_t capacity)
{
    if(!capacity) return false;

    void *array = realloc(D->array, D->data_size * capacity);
    if(!array) return false;

    D->array = array;

    D->capacity = capacity;

    return true;
}

void deque_array_destroy(DequeArray *D)
{
    free(D->array);
    D->array = NULL;
    
    D->front = 0;
    D->back = 0;
    D->size = 0;
}

void *deque_array_front(DequeArray *D)
{
    if(!D->array) return NULL;

    return (char *)D->array + (D->data_size * D->front);
}

void *deque_array_back(DequeArray *D)
{
    if(!D->array) return NULL;

    return (char *)D->array + (D->data_size * D->back);
}

size_t deque_array_size(DequeArray *D)
{
    return D->size;
}

// bool deque_array_push_front(DequeArray *D, void *data)
// {
    
// }

bool deque_array_push_back(DequeArray *D, void *data)
{
    if(D->back == D->capacity) return false;

    memcpy((char *)D->array + (D->data_size * D->back), data, D->data_size);

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
