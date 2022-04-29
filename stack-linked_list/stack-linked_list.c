#include "stack-linked_list.h"

StackLL* StackLL_create(size_t data_size);
void StackLL_destroy(StackLL* S);

static StackLLNode* stack_node_create(size_t data_size);
static void stack_node_destroy(StackLLNode* S);

bool StackLL_push(StackLL* S, void* data);
bool StackLL_pop(StackLL* S);

StackLL* StackLL_create(size_t data_size)
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

void StackLL_destroy(StackLL* S)
{
    StackLLNode* node = S->top;
    while(node) {
        if(node->next) {
            StackLL_pop(S);
            node = S->top;   
        }
        else {
            StackLL_pop(S);
            break;
        }
    }
    free(S);
    S = NULL;
}

static StackLLNode* stack_node_create(size_t data_size)
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

static void stack_node_destroy(StackLLNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

bool StackLL_push(StackLL* S, void* data)
{
    StackLLNode* node = stack_node_create(S->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, S->data_size);
    node->next = S->top;
    S->top = node;
    S->size = S->size + 1;
    return true;
}

bool StackLL_pop(StackLL* S)
{
    if(!S->top) {
        return false;
    }
    StackLLNode* node = S->top;
    S->top = S->top->next;
    stack_node_destroy(node);
    S->size = S->size - 1;
    return true;
}
