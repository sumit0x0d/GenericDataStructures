#include "trie.h"

struct TrieNode *search(struct Trie *tree, char *string);
bool insert(struct Trie *tree, char *string);
bool remove(struct Trie *tree, char *string);

struct Trie trie_construct()
{
    struct Trie trie;

    trie.root = NULL;
    trie.size = 0;

    return trie;
}

struct TrieNode *search(struct Trie *tree, char *string)
{
    struct TrieNode *node = tree->root;
    return node;
}

struct TrieNode *node_construct()
{
    struct TrieNode *node = malloc(sizeof (struct TrieNode));
    if(!node) return NULL;

    node->terminal = false;

    for(int i = 0; i < 128; i++)
        node->children[i] = NULL;
    // memset(node->children, 0, sizeof (node->children) * 128);

    return node;
}

bool insert(struct Trie *tree, char *string)
{
    struct TrieNode *node = tree->root;
    if(!node) {
        node = node_construct();

    }
    // node->character = 'a';
    while(*string != '\0') {
        if(node->children[(size_t)*string] == NULL)
            node->children[(size_t)*string] = node_construct();
        string++;
    }
    // size_t length = strlen(string);
    // for(size_t i = 0; i < length; i++) {
    //     if(node->children[(int)string[i]] == 0)
    //         node->children[(size_t)string[i]] = node_construct(string[i]);
    // }
    if(node->terminal)
        return;
    else
        node->terminal = true;

    // ++tree->size;
}

void node_destruct(struct Trie *tree, char character)
{
    struct TrieNode *node = tree->root;
    free(node);
}
