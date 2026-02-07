#include <stdio.h>
#include "bin_tree.h"

const int N = 9;

int main() {
    int arr[] = {3, 8, 10, 15, 20, 30, 50, 80, 105};

    Node* root = makeBinTree(arr, 0, N-1);

    printf("Binary tree:\n");
    printTree(root, 0);

    Node *node;
    printf("Search for 10\n");
    node = treeSearch(root, 10);
    if (node == NULL) {
        printf("Not found\n");
    }
    else {
        printf("Found\n");
    }

    printf("Search for 18\n");
    node = treeSearch(root, 18);
    if (node == NULL) {
        printf("Not found\n");
    }
    else {
        printf("Found\n");
    }
    return 0;
}