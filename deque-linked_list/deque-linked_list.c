#include "deque-linked_list.h"

DequeLinkedList deque_linked_list_construct();
void deque_linked_list_destruct(DequeLinkedList *D);

DequeLinkedListNode *deque_linked_list_front(DequeLinkedList *D);
DequeLinkedListNode *deque_linked_list_back(DequeLinkedList *D);
size_t deque_linked_list_size(DequeLinkedList *D);

static DequeLinkedListNode *node_construct(size_t data_type_size);
static void node_destruct(DequeLinkedListNode *D);

bool deque_linked_list_push_front(DequeLinkedList *D, void *data, int data_type, size_t data_type_size);
bool deque_linked_list_push_back(DequeLinkedList *D, void *data, int data_type, size_t data_type_size);
bool deque_linked_list_pop_front(DequeLinkedList *D);
bool deque_linked_list_pop_back(DequeLinkedList *D);

DequeLinkedList deque_linked_list_construct()
{
    DequeLinkedList D;

    D.front = NULL;
    D.back = NULL;
    D.size = 0;

    return D;
}

// void deque_linked_list_destruct(DequeLinkedList *D)
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

DequeLinkedListNode *node_construct(size_t data_type_size)
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

void node_destruct(DequeLinkedListNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool deque_linked_list_push_front(DequeLinkedList *D, void *data, int data_type, size_t data_type_size)
{
    DequeLinkedListNode *node = node_construct(data_type_size);
    if(!node) return false;

    memcpy(node->data, data, data_type_size);

    node->data_type = data_type;

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

bool deque_linked_list_push_back(DequeLinkedList *D, void *data, int data_type, size_t data_type_size)
{
    DequeLinkedListNode *node = node_construct(data_type_size);
    if(!node) return false; 

    memcpy(node->data, data, data_type_size);

    node->data_type = data_type;

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

    node_destruct(node);

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

    node_destruct(node);

    D->size = D->size - 1;

    return true;
}
