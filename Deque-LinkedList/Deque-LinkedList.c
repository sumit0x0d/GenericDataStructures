#include "Deque-LinkedList.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct DequeLL {
    Node* front;
    Node* back;
    size_t data_size;
    size_t size;
};

DequeLL* DequeLLCreate(size_t data_size)
{
    DequeLL* D = (DequeLL*)malloc(sizeof (DequeLL));
    if(!D) {
        return NULL;
    }
    D->front = NULL;
    D->back = NULL;
    D->data_size = data_size;
    D->size = 0;
    return D;
}

void DequeLLDestroy(DequeLL* D)
{
    Node* node = D->front;
    while(node) {
        if(node->next) {
            DequeLLPopFront(D);
            node = D->front;
        }
        else {
            DequeLLPopFront(D);
            break;
        }
    }
    free(D);
    D = NULL;
}

size_t DequeLLSize(DequeLL* D)
{
    return D->size;
}

bool DequeLLEmpty(DequeLL* D)
{
    if(D->size) {
        return false;
    }
    return true;
}

void* DequeLLFront(DequeLL* Q)
{
    return Q->front->data;
}

void* DequeLLBack(DequeLL* Q)
{
    return Q->back->data;
}

bool DequeLLPushFront(DequeLL* D, void* data)
{
    Node* node = NodeCreate(D->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, D->data_size);
    node->previous = NULL;
    if(D->front) {
        D->front->previous = node;
        node->next = D->front;
    }
    else {
        D->back = node;
        node->next = NULL;
    }
    D->front = node;
    D->size = D->size + 1;
    return true;
}

bool DequeLLPushBack(DequeLL* D, void* data)
{
    Node* node = NodeCreate(D->data_size);
    if(!node) {
        return false; 
    }
    memcpy(node->data, data, D->data_size);
    node->next = NULL;
    if(D->size) {
        D->back->next = node;
        node->previous = D->back;
    }
    else {
        D->front = node;
        node->previous = NULL;
    }
    D->back = node;
    D->size = D->size + 1;
    return true;
}

void DequeLLPopFront(DequeLL* D)
{
    Node* node = D->front;
    D->front = D->front->next;
    if(!D->front) {
        D->back = NULL;
    }
    NodeDestroy(node);
    D->size = D->size - 1;
}

void DequeLLPopBack(DequeLL* D)
{
    Node* node = D->back;
    D->back = D->back->previous;
    if(D->back) {
        D->back->next = NULL;
    }
    NodeDestroy(node);
    D->size = D->size - 1;
}

void DequeLLTraverse(DequeLL* D, void (*function)(void* data))
{
    Node* node = D->front;
    while(node) {
        function(node->data);
        node = node->next;
    }
}