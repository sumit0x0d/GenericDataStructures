#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Trie Trie;

Trie *trieCreate();
char* trieSearch(Trie *trie, char* string);
int trieInsert(Trie *trie, char* string);
int trieRemove(Trie *trie, char* string);

#endif
