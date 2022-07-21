#include "Trie.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Trie {
    Node* root;
    size_t size;
};

Trie *trie_Create();

char* trie_Search(Trie *T, char* string);
int trie_Insert(Trie *T, char* string);
int trie_Remove(Trie *T, char* string);

Trie *trie_Create()
{
    Trie* trie = (Trie*)malloc(sizeof (Trie));
    if(!trie) {
        return NULL;
    }
    trie->root = NULL;
    trie->size = 0;
    return trie;
}

// Node* search(Trie *T, char* string)
// {
//     Node* node = T->root;
//     return node;
// }

int trie_Insert(Trie *T, char* string)
{
    if(!T->root) {
        T->root = Node_Create();
        if(!T->root) {
            return false;
        }
    }
    Node* node = T->root; 
    while(*string != '\0') {
        if(node->children[(size_t)*string] == NULL) {
            node->children[(size_t)*string] = Node_Create();
        }
        node = node->children[(size_t)*string];
        string++;
    }
    // size_t length = strlen(string);
    // for(size_t i = 0; i < length; i++) {
    //     if(node->children[(int)string[i]] == 0)
    //         node->children[(size_t)string[i]] = node_Create(string[i]);
    // }
    if(node->terminal) {
        return false;
    }
    else {
        node->terminal = 1;
    }
    T->size = T->size + 1;
    return true;
}

// void node_Destroy(Trie *T, char character)
// {
//     Node* node = T->root;
//     free(node);
// }
