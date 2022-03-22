#include "stack-linked_list.h"

StackLinkedList stack_linked_list_construct();
void stack_linked_list_destruct(StackLinkedList *S);

inline StackLinkedListNode *stack_linked_list_peek(StackLinkedList *s);
inline size_t stack_linked_list_size(StackLinkedList *S);

StackLinkedListNode *node_construct(size_t data_type_size);
void node_destruct(StackLinkedListNode *S);

bool stack_linked_list_push(StackLinkedList *S, void *data, size_t data_type_size);
bool stack_linked_list_pop(StackLinkedList *S);

StackLinkedList stack_linked_list_construct()
{
    StackLinkedList S;

    S.top = NULL;
    S.size = 0;

    return S;
}

void stack_linked_list_destruct(StackLinkedList *S)
{
    StackLinkedListNode *node = S->top;

    while(node)
        if(node->next) {
            stack_linked_list_pop(S);
            node = S->top;   
        }
        else {
            stack_linked_list_pop(S);
            break;
        }

    return;
}

inline StackLinkedListNode *stack_linked_list_peek(StackLinkedList *S)
{
    return S->top;
}

inline size_t stack_linked_list_size(StackLinkedList *S)
{
    return S->size;
}

StackLinkedListNode *node_construct(size_t data_type_size)
{
    StackLinkedListNode *node = malloc(sizeof (StackLinkedListNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    return node;
}

void node_destruct(StackLinkedListNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool stack_linked_list_push(StackLinkedList *S, void *data, size_t data_type_size)
{
    StackLinkedListNode *node = node_construct(data_type_size);
    if(!node) return false;

    memcpy(node->data, data, data_type_size);

    node->next = S->top;
    S->top = node;

    S->size = S->size + 1;

    return true;
}

bool stack_linked_list_pop(StackLinkedList *S)
{
    if(!S->size) return false;

    StackLinkedListNode *node = S->top;

    S->top = S->top->next;

    node_destruct(node);

    S->size = S->size - 1;

    return true;
}
