#include "bin_search.h"

int left_bin_search(int *x, int number, int start, int end) {
    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    if (number <= x[mid]) {
        return left_bin_search(x, number, start, mid);
    }
    else {
        return left_bin_search(x, number, mid+1, end);
    }
}

int find_split_point(int *x, int start, int end) {
    if (start == end) {
        return start;
    }
    int mid = (start + end) / 2;
    if (x[mid] <= x[end]) {
        return find_split_point(x, start, mid);
    } else {
        return find_split_point(x, mid+1, end);
    }
}

int search_number(int *x, int size, int number) {
    int split_point = find_split_point(x, 0, size-1);
    if (split_point == 0) {
        int index = left_bin_search(x, number, 0, size-1);
        if (x[index] != number) {
            return -1;
        }
        return index;
    } else {
        int idx1 = left_bin_search(x, number, 0, split_point-1);
        int idx2 = left_bin_search(x, number, split_point, size-1);
        if (x[idx1] == number) {
            return idx1;
        }
        if (x[idx2] == number) {
            return idx2;
        }
        return -1;
    }
}


