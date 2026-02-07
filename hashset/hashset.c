#include <stdio.h>
#include <stdlib.h>
#include "hashset.h"

HashSet *createHashSet() {
    HashSet *set = malloc(sizeof(HashSet));
    for (int i = 0; i < HASHSET_SIZE; i++) {
        set->arr[i] = malloc(sizeof(List));
        set->arr[i]->head = NULL;
    }
    return set;
}

void freeHashSet(HashSet *set) {
    for (int i = 0; i < HASHSET_SIZE; i++) {
        freeList(set->arr[i]);
    }
    free(set);
}

int hash(int key) {
    if (key < 0) {
        key = -key;
    }
    return key % HASHSET_SIZE;
}

void hashsetAdd(HashSet *set, int value) {
    int index = hash(value);
    List *list = set->arr[index];
    
    // Check if value already exists
    for (Node *now = list->head; now != NULL; now = now->next) {
        if (now->number == value) {
            return; // Value already in set
        }
    }
    
    // Add value to the list
    listAppend(list, value);
}

int hashsetContains(HashSet *set, int value) {
    int index = hash(value);
    List *list = set->arr[index];
    
    for (Node *now = list->head; now != NULL; now = now->next) {
        if (now->number == value) {
            return 1;
        }
    }
    
    return 0;
}

void hashsetRemove(HashSet *set, int value) {
    int index = hash(value);
    List *list = set->arr[index];
    
    listRemove(list, value);
}

void hashsetPrint(HashSet *set) {
    printf("HashSet:\n");
    for (int i = 0; i < HASHSET_SIZE; i++) {
        List *list = set->arr[i];
        if (list->head != NULL) {
            printf("Bucket %d: ", i);
            listPrint(list);
        }
    }
}