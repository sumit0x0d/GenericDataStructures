#include "hash_table.h"

int main()
{
    HashTable *hash_table = hash_table_construct(10);
    hash_table_insert(hash_table, 125);
    hash_table_insert(hash_table, 122);
    hash_table_insert(hash_table, 88);
    hash_table_insert(hash_table, 15);
    hash_table_print(hash_table);
}
