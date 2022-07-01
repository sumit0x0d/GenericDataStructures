#include "Trie.h"

struct TrieNode {
    int terminal;
    struct TrieNode* children[128];
};

struct Trie {
    TrieNode* root;
    size_t size;
};

Trie *trie_create();

TrieNode* trie_search(Trie *T, char* string);
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

// TrieNode* search(Trie *T, char* string)
// {
//     TrieNode* node = T->root;
//     return node;
// }

static TrieNode* node_create()
{
    TrieNode* node = malloc(sizeof (TrieNode));
    if(!node) {
        return NULL;
    }
    node->terminal = 0;
    for(int i = 0; i < 128; i++) {
        node->children[i] = NULL;
    }
    // memset(node->children, '\0', sizeof (TrieNode) * 128);
    return node;
}

int trie_insert(Trie *T, char* string)
{
    if(!T->root) {
        T->root = node_create();
        if(!T->root) {
            return false;
        }
    }
    TrieNode* node = T->root; 
    while(*string != '\0') {
        if(node->children[(size_t)*string] == NULL) {
            node->children[(size_t)*string] = node_create();
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
//     TrieNode* node = T->root;
//     free(node);
// }
