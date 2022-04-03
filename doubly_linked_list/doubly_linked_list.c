#include "doubly_linked_list.h"

DoublyLinkedList doubly_linked_list_create(size_t data_size, int (*compare_data)(void *data, void *node_data));
void doubly_linked_list_destroy(DoublyLinkedList *);

DoublyLinkedListNode *doubly_linked_list_front(DoublyLinkedList *DLL);
DoublyLinkedListNode *doubly_linked_list_back(DoublyLinkedList *DLL);
size_t doubly_linked_list_size(DoublyLinkedList *DLL);

static DoublyLinkedListNode *node_create(size_t data_size);
static void node_destroy(DoublyLinkedListNode *node);

DoublyLinkedListNode *doubly_linked_list_search(DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_push_front(DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_push_back(DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_insert(DoublyLinkedList *DLL, size_t index, void *data);
bool doubly_linked_list_sorted_insert(DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_pop_front(DoublyLinkedList *DLL);
bool doubly_linked_list_pop_back(DoublyLinkedList *DLL);
bool doubly_linked_list_remove(DoublyLinkedList *DLL, void *data);
bool doubly_linked_list_erase(DoublyLinkedList *DLL, size_t index);
bool doubly_linked_list_update(DoublyLinkedList *SLL, size_t index, void *data);
bool doubly_linked_list_linear(DoublyLinkedList *DLL);
bool doubly_linked_list_circular(DoublyLinkedList *DLL);

DoublyLinkedList doubly_linked_list_create(size_t data_size, int (*compare_data)(void *data, void *node_data))
{
    DoublyLinkedList DLL;

    DLL.head = NULL;
    DLL.tail = NULL;
    DLL.data_size = data_size;
    DLL.size = 0;

    DLL.compare_data = compare_data;

    return DLL;
}

DoublyLinkedListNode *doubly_linked_list_front(DoublyLinkedList *DLL)
{
    return DLL->head;
}

DoublyLinkedListNode *doubly_linked_list_back(DoublyLinkedList *DLL)
{
    return DLL->tail;
}

size_t doubly_linked_list_size(DoublyLinkedList *DLL)
{
    return DLL->size;
}

static DoublyLinkedListNode *node_create(size_t data_size)
{
    DoublyLinkedListNode *node = malloc(sizeof (DoublyLinkedListNode));
    if(!node) return NULL;

    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    return node;
}

static void node_destroy(DoublyLinkedListNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}


DoublyLinkedListNode *doubly_linked_list_search(DoublyLinkedList *DLL, void *data)
{
    if(!DLL->size) return NULL;

    DoublyLinkedListNode *node = malloc(sizeof (DoublyLinkedListNode));
    while(node) {
        if(!DLL->compare_data(data, node->data))
            return node;
        node = node->next;
    }

    return NULL;
}

bool doubly_linked_list_push_front(DoublyLinkedList *DLL, void *data)
{
    DoublyLinkedListNode *node = node_create(DLL->data_size);
    if(!node) return false;

    memcpy(node->data, data, DLL->data_size);

    node->previous = NULL;
    if(DLL->size) {
        DLL->head->previous = node;
        node->next = DLL->head;
    }
    else {
        DLL->tail = node;
        node->next = NULL;
    }

    DLL->head = node;

    DLL->size = DLL->size + 1;

    return true;
}

bool doubly_linked_list_push_back(DoublyLinkedList *DLL, void *data)
{
    DoublyLinkedListNode *node = node_create(DLL->data_size);
    if(!node) return false;

    memcpy(node->data, data, DLL->data_size);

    node->next = NULL;
    if(DLL->size) {
        DLL->tail->next = node;
        node->previous = DLL->tail;
    }
    else {
        DLL->head = node;
        node->previous = NULL;
    }

    DLL->tail = node;

    DLL->size = DLL->size + 1;

    return true;
}

bool doubly_linked_list_insert(DoublyLinkedList *DLL, size_t index, void *data)
{
    if(index > DLL->size) return false;
    DoublyLinkedListNode *node = DLL->head;
    DoublyLinkedListNode *node_new = node_create(DLL->data_size);
    if(!node_new) return false;

    memcpy(node_new->data, data, DLL->data_size);

    if(!index)
        doubly_linked_list_push_front(DLL, data);
    else if(index == DLL->size)
        doubly_linked_list_push_back(DLL, data);
    else {
        for(size_t i = 0; i < index-1; ++i)
            node = node->next;
        node_new->previous = node;
        node_new->next = node->next;
        node->next->previous = node_new;
        node->next = node_new;
    }

    DLL->size = DLL->size + 1;

    return true;
}

// bool doubly_linked_list_sorted_insert(DoublyLinkedList *DLL, void *data)
// {

// }

bool doubly_linked_list_pop_front(DoublyLinkedList *DLL)
{
    if(!DLL->size) return false;

    DoublyLinkedListNode *node = DLL->head;

    DLL->head = DLL->head->next;
    if(!DLL->head)
        DLL->tail = NULL;

    node_destroy(node);

    DLL->size = DLL->size - 1;

    return true;
}

bool doubly_linked_list_pop_back(DoublyLinkedList *DLL)
{
    if(!DLL->size) return false;

    DoublyLinkedListNode *node = DLL->tail;

    DLL->tail = DLL->tail->previous;
    if(DLL->tail)
        DLL->tail->next = NULL;

    node_destroy(node);

    DLL->size = DLL->size - 1;

    return true;
}

bool doubly_linked_list_erase(DoublyLinkedList *DLL, size_t index)
{
    if(index == 0 || index > DLL->size)
        return false;
    if(index == 1)
        doubly_linked_list_pop_front(DLL);
    DoublyLinkedListNode *node = DLL->head;
    for(size_t i = 0; i < index-1; ++i) {
        node->previous = node;
        node = node->next;
    }
    node->previous->next = node->next;
    free(node);

    return true;
}

bool doubly_linked_list_remove(DoublyLinkedList *DLL, void *data)
{
    DoublyLinkedListNode *node = DLL->head;
    size_t count = 0;
    while(node) {
        if(!DLL->compare_data(data, node->data))
            break;
        count++;
        node = node->next;
    }

    erase(DLL, count);

    return true;
}
