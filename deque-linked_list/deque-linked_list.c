#include "deque-linked_list.h"

struct DequeLinkedListNode {
    void* data;
    struct DequeLinkedListNode* previous;
    struct DequeLinkedListNode* next;
};

struct DequeLinkedList {
    DequeLinkedListNode* front;
    DequeLinkedListNode* back;
    size_t data_size;
    size_t size;
};

DequeLinkedList* deque_linked_list_create(size_t data_size);
void deque_linked_list_destroy(DequeLinkedList* D);

void* deque_linked_list_front(DequeLinkedList* D);
void* deque_linked_list_back(DequeLinkedList* D);
size_t deque_linked_list_size(DequeLinkedList* D);

static DequeLinkedListNode* node_create(size_t data_size);
static void node_destroy(DequeLinkedListNode* D);

bool deque_linked_list_push_front(DequeLinkedList* D, void* data);
bool deque_linked_list_push_back(DequeLinkedList* D, void* data);
bool deque_linked_list_pop_front(DequeLinkedList* D);
bool deque_linked_list_pop_back(DequeLinkedList* D);

DequeLinkedList* deque_linked_list_create(size_t data_size)
{
    DequeLinkedList* D = malloc(sizeof (DequeLinkedList));
    if(!D) {
        return NULL;
    }
    D->front = NULL;
    D->back = NULL;
    D->data_size = data_size;
    D->size = 0;
    return D;
}

void deque_linked_list_destroy(DequeLinkedList* D)
{
    DequeLinkedListNode* node = D->front;
    while(node) {
        if(node->next) {
            deque_linked_list_pop_front(D);
            node = D->front;   
        }
        else {
            deque_linked_list_pop_front(D);
            break;
        }
    }
    free(D);
    D = NULL;
}

void* deque_linked_list_front(DequeLinkedList* D)
{
    if(!D->front) {
        return NULL;
    }
    return D->front->data;
}

void* deque_linked_list_back(DequeLinkedList* D)
{
    if(!D->back) {
        return NULL;
    }
    return D->back->data;
}

size_t deque_linked_list_size(DequeLinkedList* D)
{
    return D->size;
}

DequeLinkedListNode* node_create(size_t data_size)
{
    DequeLinkedListNode* node = malloc(sizeof (DequeLinkedListNode));
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

void node_destroy(DequeLinkedListNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

bool deque_linked_list_push_front(DequeLinkedList* D, void* data)
{
    DequeLinkedListNode* node = node_create(D->data_size);
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

bool deque_linked_list_push_back(DequeLinkedList* D, void* data)
{
    DequeLinkedListNode* node = node_create(D->data_size);
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

bool deque_linked_list_pop_front(DequeLinkedList* D)
{
    if(!D->front) {
        return false;
    }
    DequeLinkedListNode* node = D->front;
    D->front = D->front->next;
    if(!D->front) {
        D->back = NULL;
    }
    node_destroy(node);
    D->size = D->size - 1;
    return true;
}

bool deque_linked_list_pop_back(DequeLinkedList* D)
{
    if(!D->front) {
        return false;
    }
    DequeLinkedListNode* node = D->back;
    D->back = D->back->previous;
    if(D->back) {
        D->back->next = NULL;
    }
    node_destroy(node);
    D->size = D->size - 1;
    return true;
}
