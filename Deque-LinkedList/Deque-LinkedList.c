#include "Deque-LinkedList.h"

DequeLL* DequeLL_create(size_t data_size);
void DequeLL_destroy(DequeLL* D);

static DequeLLNode* DequeLLnode_create(size_t data_size);
static void DequeLLnode_destroy(DequeLLNode* D);

bool DequeLL_push_front(DequeLL* D, void* data);
bool DequeLL_push_back(DequeLL* D, void* data);
bool DequeLL_pop_front(DequeLL* D);
bool DequeLL_pop_back(DequeLL* D);

void* DequeLL_front(DequeLL* Q);
void* DequeLL_back(DequeLL* Q);

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
    DequeLLNode* pointer = D->front;
    while(pointer) {
        if(pointer->next) {
            DequeLL_pop_front(D);
            pointer = D->front;
        }
        else {
            DequeLL_pop_front(D);
            break;
        }
    }
    free(D);
    D = NULL;
}

static DequeLLNode* DequeLLnode_create(size_t data_size)
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

static void DequeLLnode_destroy(DequeLLNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

bool DequeLL_push_front(DequeLL* D, void* data)
{
    DequeLLNode* node = DequeLLnode_create(D->data_size);
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
    DequeLLNode* node = DequeLLnode_create(D->data_size);
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

bool DequeLL_pop_front(DequeLL* D)
{
    if(!D->front) {
        return false;
    }
    DequeLLNode* pointer = D->front;
    D->front = D->front->next;
    if(!D->front) {
        D->back = NULL;
    }
    DequeLLnode_destroy(pointer);
    D->size = D->size - 1;
    return true;
}

bool DequeLL_pop_back(DequeLL* D)
{
    if(!D->front) {
        return false;
    }
    DequeLLNode* pointer = D->back;
    D->back = D->back->previous;
    if(D->back) {
        D->back->next = NULL;
    }
    DequeLLnode_destroy(pointer);
    D->size = D->size - 1;
    return true;
}

void* DequeLL_front(DequeLL* Q)
{
    if(!Q->front) {
        return NULL;
    }
    return Q->front->data;
}

void* DequeLL_back(DequeLL* Q)
{
    if(!Q->back) {
        return NULL;
    }
    return Q->back->data;
}
