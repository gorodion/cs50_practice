#ifndef BIN_TREE_H
#define BIN_TREE_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node *createNode(int data);
void printTree(Node *root, int space);
Node *makeBinTree(int *arr, int start, int end);
Node *treeSearch(Node *root, int number);
void freeTree(Node *root);

#endif