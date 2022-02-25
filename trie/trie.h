#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct TrieNode {
    void *data;
    size_t data_type_size;
    bool terminal;
    struct TrieNode *children[256];
};

struct Trie {
    struct TrieNode *root;
    size_t size;
    struct TrieNode *(*search)(struct Trie *trie, void *data, size_t data_type_size);
    void (*insert)(struct Trie *trie, void *data, size_t data_type_size);
    void (*remove)(struct Trie *trie, void *data, size_t data_type_size);
};

struct Trie trie_construct();

#endif
