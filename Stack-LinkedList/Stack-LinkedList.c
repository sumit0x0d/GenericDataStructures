#include "Stack-LinkedList.h"

StackLL* StackLL_create(size_t data_size);
void StackLL_destroy(StackLL* S);

static StackLLNode* StackLLnode_create(size_t data_size);
static void StackLLnode_destroy(StackLLNode* S);

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
    StackLLNode* pointer = S->top;
    while(pointer) {
        if(pointer->next) {
            StackLL_pop(S);
            pointer = S->top;   
        }
        else {
            StackLL_pop(S);
            break;
        }
    }
    free(S);
    S = NULL;
}

static StackLLNode* StackLLnode_create(size_t data_size)
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

static void StackLLnode_destroy(StackLLNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

bool StackLL_push(StackLL* S, void* data)
{
    StackLLNode* node = StackLLnode_create(S->data_size);
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
    StackLLNode* pointer = S->top;
    S->top = S->top->next;
    StackLLnode_destroy(pointer);
    S->size = S->size - 1;
    return true;
}
