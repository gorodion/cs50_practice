#include <stdio.h>
#include "bin_search.h"

const int N = 8;

int main()
{
    int x[] = {47, 70, 83, 99, 2, 10, 33, 45};

    printf("Array: \n");
    for (int i = 0; i < N; i++) {
        printf("%i ", x[i]);
    }
    printf("\n");

    int index;

    printf("Search for 10\n");
    index = search_number(x, N, 10);
    if (index == -1) {
        printf("Element not found\n");
    } else {
        printf("Index of the element is %i\n", index);
    }


    printf("Search for 22\n");
    index = search_number(x, N, 22);
    if (index == -1) {
        printf("Element not found\n");
    } else {
        printf("Index of the element is %i\n", index);
    }

    printf("Search for 47\n");
    index = search_number(x, N, 47);
    if (index == -1) {
        printf("Element not found\n");
    } else {
        printf("Index of the element is %i\n", index);
    }
    return 0;
}