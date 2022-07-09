#include "Trie.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Trie {
    Node* root;
    size_t size;
};

Trie *trie_create();

char* trie_search(Trie *T, char* string);
int trie_insert(Trie *T, char* string);
int trie_remove(Trie *T, char* string);

Trie *trie_create()
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

int trie_insert(Trie *T, char* string)
{
    if(!T->root) {
        T->root = Node_create();
        if(!T->root) {
            return false;
        }
    }
    Node* node = T->root; 
    while(*string != '\0') {
        if(node->children[(size_t)*string] == NULL) {
            node->children[(size_t)*string] = Node_create();
        }
        node = node->children[(size_t)*string];
        string++;
    }
    // size_t length = strlen(string);
    // for(size_t i = 0; i < length; i++) {
    //     if(node->children[(int)string[i]] == 0)
    //         node->children[(size_t)string[i]] = node_create(string[i]);
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

// void node_destroy(Trie *T, char character)
// {
//     Node* node = T->root;
//     free(node);
// }
