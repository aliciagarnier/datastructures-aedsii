#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 11

typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;


// simplesmente declarando a struct do no

typedef struct HashTable {
    Node *table[TABLE_SIZE];
} HashTable;

// possui um ponteiro para esse vetor dos nos

int hash_function(int key) {
    return key % TABLE_SIZE;
}

void init_table(HashTable *ht) {
    memset(ht->table, 0, sizeof(Node *) * TABLE_SIZE);
}

void insert(HashTable *ht, int key, int value) {
    int hash_value = hash_function(key); // fornecendo o indice para mim usando a funcao de hash 
    Node *node = ht->table[hash_value];
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = node;
    ht->table[hash_value] = new_node;
}

int search(HashTable *ht, int key) {
    int hash_value = hash_function(key);
    Node *node = ht->table[hash_value];
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

int main() {
    HashTable ht;
    init_table(&ht);
    insert(&ht, 1, 10);
    insert(&ht, 2, 20);
    insert(&ht, 3, 30);
    printf("%d\n", search(&ht, 1));
    printf("%d\n", search(&ht, 2));
    printf("%d\n", search(&ht, 3));
    return 0;
}
