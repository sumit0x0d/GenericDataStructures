#include "trie.h"


struct TrieNode *search(struct Trie *trie, char data);
void insert(struct Trie *trie, char data);
void remove(struct Trie *trie, char data);

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

struct TrieNode *node_construct(char data)
{
    struct TrieNode *node = malloc(sizeof (struct TrieNode));
    if(!node) return;

    node->data = data;

    node->children[256] = NULL;
    node->terminal = false;

    return node;
}

void insert(struct Trie *trie, char data)
{
    struct TrieNode *node = node_construct(data);
    ++trie->size;
}
