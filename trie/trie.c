#include "trie.h"

TrieNode *trie_search(Trie *T, char *string);
bool trie_insert(Trie *T, char *string);
bool trie_remove(Trie *T, char *string);

Trie trie_construct()
{
    Trie trie;

    trie.root = NULL;
    trie.size = 0;

    return trie;
}

// TrieNode *search(Trie *T, char *string)
// {
//     TrieNode *node = T->root;
//     return node;
// }

static TrieNode *node_construct()
{
    TrieNode *node = malloc(sizeof (TrieNode));
    if(!node) return NULL;

    node->terminal = false;

    for(int i = 0; i < 128; i++)
        node->children[i] = NULL;
    // memset(node->children, '\0', sizeof (TrieNode) * 128);

    return node;
}

bool trie_insert(Trie *T, char *string)
{
    if(!T->root) {
        T->root = node_construct();
        if(!T->root) return false;
    }

    TrieNode *node = T->root; 

    while(*string != '\0') {
        if(node->children[(size_t)*string] == NULL)
            node->children[(size_t)*string] = node_construct();
        node = node->children[(size_t)*string];
        string++;
    }
    // size_t length = strlen(string);
    // for(size_t i = 0; i < length; i++) {
    //     if(node->children[(int)string[i]] == 0)
    //         node->children[(size_t)string[i]] = node_construct(string[i]);
    // }
    if(node->terminal)
        return false;
    else
        node->terminal = true;

    T->size = T->size + 1;

    return true;
}

// void node_destruct(Trie *T, char character)
// {
//     TrieNode *node = T->root;
//     free(node);
// }
