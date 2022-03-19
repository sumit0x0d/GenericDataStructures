#include "trie.h"

struct TrieNode *trie_search(struct Trie *T, char *string);
bool trie_insert(struct Trie *T, char *string);
bool trie_remove(struct Trie *T, char *string);

struct Trie trie_construct()
{
    struct Trie trie;

    trie.root = NULL;
    trie.size = 0;

    return trie;
}

// struct TrieNode *search(struct Trie *T, char *string)
// {
//     struct TrieNode *node = T->root;
//     return node;
// }

struct TrieNode *node_construct()
{
    struct TrieNode *node = malloc(sizeof (struct TrieNode));
    if(!node) return NULL;

    node->terminal = false;

    for(int i = 0; i < 128; i++)
        node->children[i] = NULL;
    // memset(node->children, '\0', sizeof (struct TrieNode) * 128);

    return node;
}

bool trie_insert(struct Trie *T, char *string)
{
    if(!T->root) {
        T->root = node_construct();
        if(!T->root) return false;
    }

    struct TrieNode *node = T->root; 

    // node->character = 'a';
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

// void node_destruct(struct Trie *T, char character)
// {
//     struct TrieNode *node = T->root;
//     free(node);
// }
