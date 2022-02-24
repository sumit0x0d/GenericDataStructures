#include "trie.h"

#include <stdlib.h>

void *search(struct Trie *trie, void *data, size_t data_type_size);
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

void insert(struct Trie *trie, void *data, size_t data_type_size)
{
    struct TrieNode *node = malloc(sizeof (struct TrieNode));
    if(!node) return;


}