#ifndef HASHSET_H
#define HASHSET_H

#include "../list/list.h"

#define HASHSET_SIZE 100

typedef struct HashSet {
    List *arr[HASHSET_SIZE];
} HashSet;

HashSet *createHashSet();
void freeHashSet(HashSet *set);
int hash(int key);
void hashsetAdd(HashSet *set, int value);
int hashsetContains(HashSet *set, int value);
void hashsetRemove(HashSet *set, int value);
void hashsetPrint(HashSet *set);

#endif