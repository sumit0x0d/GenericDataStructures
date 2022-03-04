#include "trie.h"

struct TrieNode *search(struct Trie *tree, char *string);
void insert(struct Trie *tree, char *string);
void remove(struct Trie *tree, char *string);

struct Trie trie_construct()
{
    struct Trie trie;

    trie.root = NULL;
    trie.size = 0;
    
    trie.search = search;
    trie.insert = insert;
    trie.remove = remove;

    return trie;
}

struct TrieNode *search(struct Trie *tree, char *string)
{
    struct TrieNode *node = tree->root;
    return node;
}

struct TrieNode *node_construct(unsigned char character)
{
    struct TrieNode *node = malloc(sizeof (struct TrieNode));
    if(!node) return NULL;

    node->character = character;

    node->terminal = false;
    memset(node->children, 0, sizeof (node->children) * 128);

    return node;
}

void insert(struct Trie *tree, char *string)
{
    struct TrieNode *node = tree->root;
    unsigned char character = *string;

    while(character != '\0') {
        // if(node->children[character] == 0)
            node->children[character] = node_construct(character);
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

    ++tree->size;
}

void node_distruct(struct Trie *tree, char character)
{
    struct TrieNode *node = tree->root;
    free(node);
}
