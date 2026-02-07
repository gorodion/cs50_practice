#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

const int N = 8;

int main()
{
    int x[] = {83, 10, 99, 47, 33, 45, 2, 70};

    printf("Array before: \n");
    for (int i = 0; i < N; i++) {
        printf("%i ", x[i]);
    }
    printf("\n");

    mergeSort(x, N);

    printf("Array after: \n");
    for (int i = 0; i < N; i++) {
        printf("%i ", x[i]);
    }
    printf("\n");

    return 0;
}