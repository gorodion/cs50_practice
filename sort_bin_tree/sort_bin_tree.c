#include <stdio.h>
#include <stdlib.h>
#include "../merge/merge.h"
#include "../bin_tree/bin_tree.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <numbers>\n", argv[0]);
        return 1;
    }

    int size = argc - 1;
    int *arr = malloc(size * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Convert command line arguments to integers
    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using merge sort
    mergeSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Create binary tree from sorted array
    Node* root = makeBinTree(arr, 0, size - 1);

    printf("Binary tree:\n");
    printTree(root, 0);

    // Test tree search
    int search_value;
    if (size > 0) {
        search_value = arr[0]; // First element
        printf("Search for %d\n", search_value);
        Node *node = treeSearch(root, search_value);
        if (node == NULL) {
            printf("Not found\n");
        } else {
            printf("Found\n");
        }
    }

    // Clean up
    free(arr);
    
    return 0;
}