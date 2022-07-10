#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct LinkedList LinkedList;

LinkedList* LinkedList_create(size_t data_size, int (*compare)(void* data1, void* data2));
void LinkedList_destroy(LinkedList* LL);
size_t LinkedList_size(LinkedList* LL);
bool LinkedList_empty(LinkedList* LL);
void* LinkedList_head(LinkedList* LL);
void* LinkedList_tail(LinkedList* LL);
void* LinkedList_at(LinkedList* LL, size_t index);
void* LinkedList_search(LinkedList* LL, void* data);
bool LinkedList_push_front(LinkedList* LL, void* data);
bool LinkedList_push_back(LinkedList* LL, void* data);
bool LinkedList_insert(LinkedList* LL, size_t index, void* data);
bool LinkedList_sorted_insert(LinkedList* LL, void* data);
void LinkedList_pop_front(LinkedList* LL);
void LinkedList_pop_back(LinkedList* LL);
void LinkedList_remove(LinkedList* LL, void* data);
void LinkedList_erase(LinkedList* LL, size_t index);
bool LinkedList_update(LinkedList* LL, size_t index, void* data);

#endif
