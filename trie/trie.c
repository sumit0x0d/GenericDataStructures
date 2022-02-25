#include "trie.h"


struct TrieNode *search(struct Trie *trie, void *data, size_t data_type_size);
void insert(struct Trie *trie, void *data, size_t data_type_size);
void remove(struct Trie *trie, void *data, size_t data_type_size);

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

struct TrieNode *node_construct(void *data, size_t data_type_size)
{
    struct TrieNode *node = malloc(sizeof (struct TrieNode));
    if(!node) return;

    node->data = malloc(data_type_size);
    memcpy(node->data, data, data_type_size);

    node->data_type_size = data_type_size;
    node->children[256] = NULL;
    node->terminal = false;

    return node;
}

void insert(struct Trie *trie, void *data, size_t data_type_size)
{
    struct TrieNode *node = node_construct(data, data_type_size);
    ++trie->size;
}
