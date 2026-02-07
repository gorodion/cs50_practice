#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[])
{
    int size = argc - 1;
    
    // Create an array of integers from command line arguments
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 1]);
    }
    
    // Create a list from the array
    List *list = makeList(arr, 0, size - 1);
    free(arr);

    listPrint(list);

    printf("Reverse list\n");
    listReverse(list);
    listPrint(list);

    printf("Try to append 135\n");
    listAppend(list, 135);
    listPrint(list);

    printf("Try to appendleft 531\n");
    listAppendleft(list, 531);
    listPrint(list);

    printf("Try to remove 135\n");
    listRemove(list, 135);
    listPrint(list);

    printf("Try to remove 531\n");
    listRemove(list, 531);
    listPrint(list);

    printf("Try to remove 15\n");
    listRemove(list, 15);
    listPrint(list);

    printf("Try to insert 15 at 0\n");
    listInsert(list, 15, 0);
    listPrint(list);

    printf("Try to insert 147 at 2\n");
    listInsert(list, 147, 2);
    listPrint(list);

    printf("Try to insert 34 at 4\n");
    listInsert(list, 34, 4);
    listPrint(list);

    printf("Try to insert 500 at 10\n");
    listInsert(list, 500, 10);
    listPrint(list);

    printf("Try to pop\n");
    listPop(list);
    listPrint(list);

    printf("Try to popleft\n");
    listPopleft(list);
    listPrint(list);

    printf("Create sorted list\n");
    List *sorted_list = malloc(sizeof(List));
    sorted_list->head = NULL;
    for (Node *now = list->head; now != NULL; now=now->next) {
        listAddSorted(sorted_list, now->number);
    }

    printf("Add 0 to sorted list\n");
    listAddSorted(sorted_list, 0);
    printf("Sorted list\n");
    listPrint(sorted_list);


    printf("Clearing lists\n");
    freeList(list);
    freeList(sorted_list);
    return 0;

}
