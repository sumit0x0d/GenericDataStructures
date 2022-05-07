#ifndef DEQUE_LINKED_LIST_H
#define DEQUE_LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

typedef struct DequeLLNode {
    void* data;
    struct DequeLLNode* previous;
    struct DequeLLNode* next;
} DequeLLNode;

typedef struct DequeLL {
    DequeLLNode* front;
    DequeLLNode* back;
    size_t data_size;
    size_t size;
} DequeLL;

DequeLL* DequeLL_create(size_t data_size);
void DequeLL_destroy(DequeLL* D);

int DequeLL_push_front(DequeLL* D, void* data);
int DequeLL_push_back(DequeLL* D, void* data);
void DequeLL_pop_front(DequeLL* D);
void DequeLL_pop_back(DequeLL* D);

void* DequeLL_front(DequeLL* Q);
void* DequeLL_back(DequeLL* Q);

#endif
