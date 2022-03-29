#include "stack-linked_list.h"

StackLinkedList stack_linked_list_create(size_t data_type_size);
void stack_linked_list_destroy(StackLinkedList *S);

StackLinkedListNode *stack_linked_list_peek(StackLinkedList *s);
size_t stack_linked_list_size(StackLinkedList *S);

static StackLinkedListNode *node_create(size_t data_type_size);
static void node_destroy(StackLinkedListNode *S);

bool stack_linked_list_push(StackLinkedList *S, void *data);
bool stack_linked_list_pop(StackLinkedList *S);

StackLinkedList stack_linked_list_create(size_t data_type_size)
{
    StackLinkedList S;

    S.top = NULL;
    S.data_type_size = data_type_size;
    S.size = 0;

    return S;
}

void stack_linked_list_destroy(StackLinkedList *S)
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

StackLinkedListNode *stack_linked_list_peek(StackLinkedList *S)
{
    return S->top;
}

size_t stack_linked_list_size(StackLinkedList *S)
{
    return S->size;
}

static StackLinkedListNode *node_create(size_t data_type_size)
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

static void node_destroy(StackLinkedListNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool stack_linked_list_push(StackLinkedList *S, void *data)
{
    StackLinkedListNode *node = node_create(S->data_type_size);
    if(!node) return false;

    memcpy(node->data, data, S->data_type_size);

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

    node_destroy(node);

    S->size = S->size - 1;

    return true;
}
