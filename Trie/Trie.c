#include "Trie.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Trie {
    Node* root;
    size_t size;
};

Trie *trieCreate();

char* trieSearch(Trie *T, char* string);
int trieInsert(Trie *T, char* string);
int trieRemove(Trie *T, char* string);

Trie *trieCreate()
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

int trieInsert(Trie *T, char* string)
{
    if(!T->root) {
        T->root = NodeCreate();
        if(!T->root) {
            return false;
        }
    }
    Node* node = T->root; 
    while(*string != '\0') {
        if(node->children[(size_t)*string] == NULL) {
            node->children[(size_t)*string] = NodeCreate();
        }
        node = node->children[(size_t)*string];
        string++;
    }
    // size_t length = strlen(string);
    // for(size_t i = 0; i < length; i++) {
    //     if(node->children[(int)string[i]] == 0)
    //         node->children[(size_t)string[i]] = nodeCreate(string[i]);
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

// void nodeDestroy(Trie *T, char character)
// {
//     Node* node = T->root;
//     free(node);
// }
