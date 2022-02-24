#ifndef DEQUE_LINKED_LIST_H
#define DEQUE_LINKED_LIST_H


#include <stdio.h>
#include <stdlib.h>

struct LinkedListNode {
    int data;
    struct LinkedListNode *next;
};

struct Deque {
    struct LinkedListNode *front;
    struct LinkedListNode *back;
    size_t size;
};

void deque_print(struct Deque deque);
struct Deque *deque_construct();
void deque_push_front(struct Deque *deque, int data);
void deque_push_back(struct Deque *deque, int data);
void deque_pop_front(struct Deque *deque);
void deque_pop_back(struct Deque *deque);

#endif
