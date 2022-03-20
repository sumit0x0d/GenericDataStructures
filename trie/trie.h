#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    bool terminal;
    TrieNode *children[128];
} TrieNode;

typedef struct Trie {
    TrieNode *root;
    size_t size;
} Trie;

Trie trie_construct();
TrieNode *trie_search(Trie *trie, char *string);
bool trie_insert(Trie *trie, char *string);
bool trie_remove(Trie *trie, char *string);

#endif
