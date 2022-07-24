#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct LinkedList LinkedList;

LinkedList* LinkedList_Create(size_t data_size, int (*compare)(void* data1, void* data2));
void LinkedList_Destroy(LinkedList* LL);
size_t LinkedList_Size(LinkedList* LL);
bool LinkedList_Empty(LinkedList* LL);
void* LinkedList_Head(LinkedList* LL);
void* LinkedList_Tail(LinkedList* LL);
void* LinkedList_At(LinkedList* LL, size_t index);
void* LinkedList_Search(LinkedList* LL, void* data);
bool LinkedList_PushFront(LinkedList* LL, void* data);
bool LinkedList_PushBack(LinkedList* LL, void* data);
bool LinkedList_Insert(LinkedList* LL, size_t index, void* data);
bool LinkedList_SortedInsert(LinkedList* LL, void* data);
void LinkedList_PopFront(LinkedList* LL);
void LinkedList_PopBack(LinkedList* LL);
void LinkedList_Remove(LinkedList* LL, void* data);
void LinkedList_Erase(LinkedList* LL, size_t index);
bool LinkedList_Update(LinkedList* LL, size_t index, void* data);
void LinkedList_Traverse(LinkedList* LL, void (*function)(void *));

#endif
