#include "DoubleEndedQueue-LinkedList.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct DoubleEndedQueueLL {
    Node* front;
    Node* back;
    size_t data_size;
    size_t size;
};

DoubleEndedQueueLL* DoubleEndedQueueLL_Create(size_t data_size)
{
    DoubleEndedQueueLL* DEQ = (DoubleEndedQueueLL*)malloc(sizeof (DoubleEndedQueueLL));
    if(!DEQ) {
        return NULL;
    }
    DEQ->front = NULL;
    DEQ->back = NULL;
    DEQ->data_size = data_size;
    DEQ->size = 0;
    return DEQ;
}

void DoubleEndedQueueLL_Destroy(DoubleEndedQueueLL* DEQ)
{
    Node* node = DEQ->front;
    while(node) {
        if(node->next) {
            DoubleEndedQueueLL_PopFront(DEQ);
            node = DEQ->front;
        }
        else {
            DoubleEndedQueueLL_PopFront(DEQ);
            break;
        }
    }
    free(DEQ);
    DEQ = NULL;
}

size_t DoubleEndedQueueLL_Size(DoubleEndedQueueLL* DEQ)
{
    return DEQ->size;
}

bool DoubleEndedQueueLL_Empty(DoubleEndedQueueLL* DEQ)
{
    if(DEQ->size) {
        return false;
    }
    return true;
}

void* DoubleEndedQueueLL_Front(DoubleEndedQueueLL* DEQ)
{
    return DEQ->front->data;
}

void* DoubleEndedQueueLL_Back(DoubleEndedQueueLL* DEQ)
{
    return DEQ->back->data;
}

bool DoubleEndedQueueLL_PushFront(DoubleEndedQueueLL* DEQ, void* data)
{
    Node* node = Node_Create(DEQ->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, DEQ->data_size);
    node->previous = NULL;
    if(DEQ->front) {
        DEQ->front->previous = node;
        node->next = DEQ->front;
    }
    else {
        DEQ->back = node;
        node->next = NULL;
    }
    DEQ->front = node;
    DEQ->size = DEQ->size + 1;
    return true;
}

bool DoubleEndedQueueLL_PushBack(DoubleEndedQueueLL* DEQ, void* data)
{
    Node* node = Node_Create(DEQ->data_size);
    if(!node) {
        return false; 
    }
    memcpy(node->data, data, DEQ->data_size);
    node->next = NULL;
    if(DEQ->size) {
        DEQ->back->next = node;
        node->previous = DEQ->back;
    }
    else {
        DEQ->front = node;
        node->previous = NULL;
    }
    DEQ->back = node;
    DEQ->size = DEQ->size + 1;
    return true;
}

void DoubleEndedQueueLL_PopFront(DoubleEndedQueueLL* DEQ)
{
    Node* node = DEQ->front;
    DEQ->front = DEQ->front->next;
    if(!DEQ->front) {
        DEQ->back = NULL;
    }
    Node_Destroy(node);
    DEQ->size = DEQ->size - 1;
}

void DoubleEndedQueueLL_PopBack(DoubleEndedQueueLL* DEQ)
{
    Node* node = DEQ->back;
    DEQ->back = DEQ->back->previous;
    if(DEQ->back) {
        DEQ->back->next = NULL;
    }
    Node_Destroy(node);
    DEQ->size = DEQ->size - 1;
}

void DoubleEndedQueueLL_Traverse(DoubleEndedQueueLL* DEQ, void (*function)(void* data))
{
    Node* node = DEQ->front;
    while(node) {
        function(node->data);
        node = node->next;
    }
}