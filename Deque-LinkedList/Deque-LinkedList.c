#include "Deque-LinkedList.h"

static DequeLLNode* node_create(size_t data_size);
static void node_destroy(DequeLLNode* D);

DequeLL* DequeLL_create(size_t data_size)
{
    DequeLL* D = malloc(sizeof (DequeLL));
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
    DequeLLNode* node = D->front;
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

void* DequeLL_front(DequeLL* Q)
{
    return Q->front->data;
}

void* DequeLL_back(DequeLL* Q)
{
    return Q->back->data;
}

static DequeLLNode* node_create(size_t data_size)
{
    DequeLLNode* node = malloc(sizeof (DequeLLNode));
    if(!node) {
        return NULL;
    }
    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        node = NULL;  
        return NULL;
    }
    return node;
}

static void node_destroy(DequeLLNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

int DequeLL_push_front(DequeLL* D, void* data)
{
    DequeLLNode* node = node_create(D->data_size);
    if(!node) {
        return 0;
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
    return 1;
}

int DequeLL_push_back(DequeLL* D, void* data)
{
    DequeLLNode* node = node_create(D->data_size);
    if(!node) {
        return 0; 
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
    return 1;
}

void DequeLL_pop_front(DequeLL* D)
{
    DequeLLNode* node = D->front;
    D->front = D->front->next;
    if(!D->front) {
        D->back = NULL;
    }
    node_destroy(node);
    D->size = D->size - 1;
}

void DequeLL_pop_back(DequeLL* D)
{
    DequeLLNode* node = D->back;
    D->back = D->back->previous;
    if(D->back) {
        D->back->next = NULL;
    }
    node_destroy(node);
    D->size = D->size - 1;
}
