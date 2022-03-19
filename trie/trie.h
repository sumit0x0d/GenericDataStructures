#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct TrieNode {
    bool terminal;
    struct TrieNode *children[128];
};

struct Trie {
    struct TrieNode *root;
    size_t size;
};

struct Trie trie_construct();
struct TrieNode *trie_search(struct Trie *trie, char *string);
bool trie_insert(struct Trie *trie, char *string);
bool trie_remove(struct Trie *trie, char *string);

#endif
