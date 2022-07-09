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

DequeLL* DequeLL_create(size_t data_size)
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

void DequeLL_destroy(DequeLL* D)
{
    Node* node = D->front;
    while(node) {
        if(node->next) {
            DequeLL_pop_front(D);
            node = D->front;
        }
        else {
            DequeLL_pop_front(D);
            break;
        }
    }
    free(D);
    D = NULL;
}

size_t DequeLL_size(DequeLL* D)
{
    return D->size;
}

bool DequeLL_empty(DequeLL* D)
{
    if(D->size) {
        return false;
    }
    return true;
}

void* DequeLL_front(DequeLL* Q)
{
    return Q->front->data;
}

void* DequeLL_back(DequeLL* Q)
{
    return Q->back->data;
}

bool DequeLL_push_front(DequeLL* D, void* data)
{
    Node* node = Node_create(D->data_size);
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

bool DequeLL_push_back(DequeLL* D, void* data)
{
    Node* node = Node_create(D->data_size);
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

void DequeLL_pop_front(DequeLL* D)
{
    Node* node = D->front;
    D->front = D->front->next;
    if(!D->front) {
        D->back = NULL;
    }
    Node_destroy(node);
    D->size = D->size - 1;
}

void DequeLL_pop_back(DequeLL* D)
{
    Node* node = D->back;
    D->back = D->back->previous;
    if(D->back) {
        D->back->next = NULL;
    }
    Node_destroy(node);
    D->size = D->size - 1;
}
