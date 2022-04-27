#include "stack-linked_list.h"

struct StackLLNode {
    void* data;
    struct StackLLNode* next;
};

struct StackLL {
    StackLLNode* top;
    size_t data_size;
    size_t size;
};

StackLL* stack_linked_list_create(size_t data_size);
void stack_linked_list_destroy(StackLL* S);

void* stack_linked_list_peek(StackLL* S);
size_t stack_linked_list_size(StackLL* S);

static StackLLNode* node_create(size_t data_size);
static void node_destroy(StackLLNode* S);

bool stack_linked_list_push(StackLL* S, void* data);
bool stack_linked_list_pop(StackLL* S);

StackLL* stack_linked_list_create(size_t data_size)
{
    StackLL* S = malloc(sizeof (StackLL));
    if(!S) {
        return NULL;
    }
    S->top = NULL;
    S->data_size = data_size;
    S->size = 0;
    return S;
}

void stack_linked_list_destroy(StackLL* S)
{
    StackLLNode* node = S->top;
    while(node) {
        if(node->next) {
            stack_linked_list_pop(S);
            node = S->top;   
        }
        else {
            stack_linked_list_pop(S);
            break;
        }
    }
    free(S);
    S = NULL;
}

void* stack_linked_list_peek(StackLL* S)
{
    if(!S->top) {
        return NULL;
    }
    return S->top->data;
}

size_t stack_linked_list_size(StackLL* S)
{
    return S->size;
}

static StackLLNode* node_create(size_t data_size)
{
    StackLLNode* node = malloc(sizeof (StackLLNode));
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

static void node_destroy(StackLLNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

bool stack_linked_list_push(StackLL* S, void* data)
{
    StackLLNode* node = node_create(S->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, S->data_size);
    node->next = S->top;
    S->top = node;
    S->size = S->size + 1;
    return true;
}

bool stack_linked_list_pop(StackLL* S)
{
    if(!S->top) {
        return false;
    }
    StackLLNode* node = S->top;
    S->top = S->top->next;
    node_destroy(node);
    S->size = S->size - 1;
    return true;
}
