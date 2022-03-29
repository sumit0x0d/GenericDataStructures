#include "deque-linked_list.h"

DequeLinkedList deque_linked_list_create(size_t data_type_size);
void deque_linked_list_destroy(DequeLinkedList *D);

DequeLinkedListNode *deque_linked_list_front(DequeLinkedList *D);
DequeLinkedListNode *deque_linked_list_back(DequeLinkedList *D);
size_t deque_linked_list_size(DequeLinkedList *D);

static DequeLinkedListNode *node_create(size_t data_type_size);
static void node_destroy(DequeLinkedListNode *D);

bool deque_linked_list_push_front(DequeLinkedList *D, void *data);
bool deque_linked_list_push_back(DequeLinkedList *D, void *data);
bool deque_linked_list_pop_front(DequeLinkedList *D);
bool deque_linked_list_pop_back(DequeLinkedList *D);

DequeLinkedList deque_linked_list_create(size_t data_type_size)
{
    DequeLinkedList D;

    D.front = NULL;
    D.back = NULL;
    D.data_type_size = data_type_size;
    D.size = 0;

    return D;
}

// void deque_linked_list_destroy(DequeLinkedList *D)
// {

// }

DequeLinkedListNode *deque_linked_list_front(DequeLinkedList *D)
{
    return D->front;
}

DequeLinkedListNode *deque_linked_list_back(DequeLinkedList *D)
{
    return D->back;
}

size_t deque_linked_list_size(DequeLinkedList *D)
{
    return D->size;
}

DequeLinkedListNode *node_create(size_t data_type_size)
{
    DequeLinkedListNode *node = malloc(sizeof (DequeLinkedListNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    return node;
}

void node_destroy(DequeLinkedListNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool deque_linked_list_push_front(DequeLinkedList *D, void *data)
{
    DequeLinkedListNode *node = node_create(D->data_type_size);
    if(!node) return false;

    memcpy(node->data, data, D->data_type_size);

    node->previous = NULL;
    if(D->size) {
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

bool deque_linked_list_push_back(DequeLinkedList *D, void *data)
{
    DequeLinkedListNode *node = node_create(D->data_type_size);
    if(!node) return false; 

    memcpy(node->data, data, D->data_type_size);

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

bool deque_linked_list_pop_front(DequeLinkedList *D)
{
    if(!D->size) return false;

    DequeLinkedListNode *node = D->front;

    D->front = D->front->next;
    if(!D->front)
        D->back = NULL;

    node_destroy(node);

    D->size = D->size - 1;

    return true;
}

bool deque_linked_list_pop_back(DequeLinkedList *D)
{
    if(!D->size) return false;

    DequeLinkedListNode *node = D->back;

    D->back = D->back->previous;
    if(D->back)
        D->back->next = NULL;

    node_destroy(node);

    D->size = D->size - 1;

    return true;
}
