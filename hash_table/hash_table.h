#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct HashTable {
    void *array;
    size_t data_type_size;
    size_t size;
    size_t capacity;
} HashTable;

void hash_table_print(HashTable *HT);
HashTable *ht_construct();
void hash_table_insert(HashTable *HT, void *data, size_t data_type_size);
void hash_table_remove(HashTable *HT);

// void hash_table_print(HashTable *HT)
// {
//     printf("Hash-Table: ");
//     size_t i = 0;
//     while(i < HT->capacity-1) {
//         printf("%d ", HT->array[i]);
//         i++;
//     }
//     printf("%d\n", HT->array[HT->capacity-1]);
//     printf("Hash-Table Size: %zu\n", HT->size);
//     printf("Hash-Table Capacity: %zu\n", HT->capacity);
// }

// HashTable *ht_construct(size_t capacity)
// {
//     HashTable *HT = malloc(sizeof (HashTable));
//     assert(HT);
//     HT->array = malloc(sizeof (int) * capacity);
//     HT->size = 0;
//     HT->capacity = capacity;
    
//     return HT;
// }

// void hash_table_insert(HashTable *HT, int data)
// {
//     hash_mod(HT->capacity, data);
//     if(!HT->array[mod])
//     HT->array[mod] = data;
//     ++HT->size;
// }

// void hash_table_remove(HashTable *HT)
// {

// }

#endif
