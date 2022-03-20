#include "doubly_linked_list.h"

DoublyLinkedList doubly_linked_list_construct(size_t data_type_size)
{
    DoublyLinkedList DLL;

    DLL.head = NULL;
    DLL.tail = NULL;
    DLL.data_type_size = data_type_size;
    DLL.size = 0;

    return DLL;
}

DoublyLinkedListNode *search(DoublyLinkedList *DLL, int data)
{
    if(!DLL->size) return NULL;

    DoublyLinkedListNode *node = malloc(sizeof (DoublyLinkedListNode));
    while(node) {
        if(data == node->data)
            return node;
        node = node->next;
    }

    return NULL;
}

DoublyLinkedListNode *node_construct(size_t data_type_size)
{
    DoublyLinkedListNode *node = malloc(sizeof (DoublyLinkedListNode));
    if(!node) return;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    return node;
}

bool push_front(DoublyLinkedList *DLL, void *data)
{
    DoublyLinkedListNode *node = node_construct(DLL->data_type_size);
    if(!node) return false;

    memcpy(node->data, data, DLL->data_type_size);

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

bool push_back(DoublyLinkedList *DLL, void *data)
{
    DoublyLinkedListNode *node = node_construct(DLL->data_type_size);
    if(!node) return false;

    memcpy(node->data, data, DLL->data_type_size);

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

void insert(DoublyLinkedList *DLL, size_t index, int data)
{
    if(index > DLL->size) return false;
    DoublyLinkedListNode *node = DLL->head;
    DoublyLinkedListNode *node_new = node_construct(DLL->data_type_size);
    if(!node_new) return false;

    memcpy(node_new->data, data, DLL->data_type_size);

    if(!index)
        push_front(DLL, data);
    else if(index == DLL->size)
        push_back(DLL, data);
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

void sorted_insert(DoublyLinkedList *DLL, int data)
{

}

void node_destruct(DoublyLinkedListNode *node, size_t data_type_size)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool pop_front(DoublyLinkedList *DLL)
{
    if(!DLL->size) return;

    DoublyLinkedListNode *node = DLL->head;

    DLL->head = DLL->head->next;
    if(!DLL->head)
        DLL->tail = NULL;

    node_destruct(node, DLL->data_type_size);

    DLL->size = DLL->size - 1;
}

bool pop_back(DoublyLinkedList *DLL)
{
    if(!DLL->size) return;

    DoublyLinkedListNode *node = DLL->tail;

    DLL->tail = DLL->tail->previous;
    if(DLL->tail)
        DLL->tail->next = NULL;

    node_destruct(node, DLL->data_type_size);

    DLL->size = DLL->size - 1;
}

bool erase(DoublyLinkedList *DLL, size_t index)
{
    if(index == 0 || index > DLL->size)
        return;
    if(index == 1)
        pop_front(DLL);
    DoublyLinkedListNode *node = DLL->head;
    for(size_t i = 0; i < index-1; ++i) {
        node->previous = node;
        node = node->next;
    }
    node->previous->next = node->next;
    free(node);
}

bool remove(DoublyLinkedList *DLL, int data)
{
    DoublyLinkedListNode *node = DLL->head;
    size_t count = 0;
    while(node) {
        count++;
        node = node->next;
    }
    if(node->data == data)
        erase(DLL, count);
}
