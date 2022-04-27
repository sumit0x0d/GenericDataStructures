#ifndef DEQUE_LINKED_LIST_H
#define DEQUE_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DequeLLNode DequeLLNode;
typedef struct DequeLL DequeLL;

DequeLL* deque_linked_list_create(size_t data_size);
void deque_linked_list_destroy(DequeLL* D);

void* deque_linked_list_front(DequeLL* D);
void* deque_linked_list_back(DequeLL* D);
size_t deque_linked_list_size(DequeLL* D);

bool deque_linked_list_push_front(DequeLL* D, void* data);
bool deque_linked_list_push_back(DequeLL* D, void* data);
bool deque_linked_list_pop_front(DequeLL* D);
bool deque_linked_list_pop_back(DequeLL* D);

#endif
