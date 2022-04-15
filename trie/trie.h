#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode TrieNode;
typedef struct Trie Trie;

Trie *trie_create();
TrieNode* trie_search(Trie *trie, char *string);
bool trie_insert(Trie *trie, char *string);
bool trie_remove(Trie *trie, char *string);

#endif
