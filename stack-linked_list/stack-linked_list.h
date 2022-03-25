#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#ifndef DATA_TYPE
#define DATA_TYPE

enum {
    BOOL,
    CHAR,
    UNSIGNED_CHAR,
    SHORT,
    UNSIGNED_SHORT,
    INT,
    UNSIGNED_INT,
    FLOAT,
    LONG,
    UNSIGNED_LONG,
    DOUBLE,
    LONG_LONG,
    UNSIGNED_LONG_LONG,
    LONG_DOUBLE,
    STRUCT,
    UNION
};

#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackLinkedListNode {
    void *data;
    int data_type;
    struct StackLinkedListNode *next;
} StackLinkedListNode;

typedef struct StackLinkedList {
    StackLinkedListNode *top;
    size_t size;
} StackLinkedList;

StackLinkedList stack_linked_list_construct();
void stack_linked_list_destruct(StackLinkedList *S);

StackLinkedListNode *stack_linked_list_peek(StackLinkedList *S);
size_t stack_linked_list_size(StackLinkedList *S);

bool stack_linked_list_push(StackLinkedList *S, void *data, int data_type, size_t data_type_size);
bool stack_linked_list_pop(StackLinkedList *S);

#endif
