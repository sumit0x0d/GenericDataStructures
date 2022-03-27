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
    STRING,
    STRUCT
};

#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackLinkedListNode {
    void *data;
    struct StackLinkedListNode *next;
} StackLinkedListNode;

typedef struct StackLinkedList {
    StackLinkedListNode *top;
    int data_type;
    size_t data_type_size;
    size_t size;
} StackLinkedList;

StackLinkedList stack_linked_list_create(int data_type, size_t data_type_size);
void stack_linked_list_distroy(StackLinkedList *S);

StackLinkedListNode *stack_linked_list_peek(StackLinkedList *S);
size_t stack_linked_list_size(StackLinkedList *S);

bool stack_linked_list_push(StackLinkedList *S, void *data);
bool stack_linked_list_pop(StackLinkedList *S);

#endif
