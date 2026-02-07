#include <stdio.h>
#include <stdlib.h>
#include "bin_tree.h"

Node *createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void printTree(Node *root, int space) {
    if (root == NULL) {
        return;
    }

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    printTree(root->left, space);
}

Node *makeBinTree(int *arr, int start, int end) {
    if (end < start) {
        return NULL;
    }
    if (start == end) {
        return createNode(arr[start]);
    }

    int mid = (start + end) / 2;

    Node *newNode = createNode(arr[mid]);
    newNode->left = makeBinTree(arr, start, mid-1);
    newNode->right = makeBinTree(arr, mid+1, end);
    return newNode;
}

Node *treeSearch(Node *root, int number) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == number) {
        return root;
    }
    else if (root->data > number) {
        return treeSearch(root->left, number);
    }
    else if (root->data < number) {
        return treeSearch(root->right, number);
    }
    return NULL;
}

void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
