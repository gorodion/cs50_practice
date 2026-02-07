#include <stdlib.h>
#include "merge.h"

void mergeSortHelper(int *x, int start, int end, int *temp) {
    if (start == end)
    {
        return;
    }
    int mid = (start + end) / 2;

    mergeSortHelper(x, start, mid, temp);
    mergeSortHelper(x, mid+1, end, temp);

    int i = start;
    int j = mid+1;
    int now = start;
    while (now < end+1) {
        if (i > mid) {
            temp[now] = x[j];
            j++;
        }
        else if (j > end) {
            temp[now] = x[i];
            i++;
        }
        else if (x[i] < x[j]) {
            temp[now] = x[i];
            i++;
        }
        else {
            temp[now] = x[j];
            j++;
        }

        now++;
    }

    for (int k = start; k < end+1; k++) {
        x[k] = temp[k];
    }
}

void mergeSort(int *x, int size) {
    if (size <= 1) {
        return;
    }
    
    int *temp = malloc(size * sizeof(int));
    if (temp == NULL) {
        return;
    }
    
    mergeSortHelper(x, 0, size - 1, temp);
    free(temp);
}


