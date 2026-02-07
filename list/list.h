#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int number;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

Node *createNode(int number);
List *makeList(int *arr, int start, int end);
void freeList(List *list);
void listPrint(List *list);
void listAppend(List *list, int number);
void listAppendleft(List *list, int number);
void listRemove(List *list, int number);
void listPop(List *list);
void listPopleft(List *list);
void listInsert(List *list, int number, int index);
void listReverse(List *list);
void listAddSorted(List *list, int number);
void listClear(List *list);

#endif
