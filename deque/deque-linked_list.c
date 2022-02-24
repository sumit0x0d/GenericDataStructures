#include "deque-linked_list.h"

void deque_print(struct Deque *deque)
{
   if(!deque->size)
        return;
    struct LinkedListNode *node = deque->front;
    printf("Queue: ");
    while(node != deque->back) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("%d\n", deque->back->data);
    printf("Queue Size: %zu\n", deque->size);
}

struct Deque *deque_construct()
{
    struct Deque *deque = malloc(sizeof(struct Deque));
    assert(deque);
    deque->front = NULL;
    deque->back = NULL;
    deque->size = 0;
    return deque;
}

void deque_push_front(struct Deque *deque, int data)
{

}

void deque_push_back(struct Deque *deque, int data)
{
    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    assert(node);
    node->data = data;
    node->next = NULL;
    if(deque->size) {
        deque->back->next = node;
        deque->back = node;
    }
    else {
        deque->front = node;
        deque->back = node;
    }
    deque->size++;
}

void deque_pop_front(struct Deque *deque)
{
    if(!deque->size)
        return;
    struct LinkedListNode *node = deque->front;
    deque->front = deque->front->next;
    if(!deque->front)
        deque->back = NULL;
    free(node);
    deque->size--;
}

void deque_pop_back(struct Deque *deque, int data)
{

}
