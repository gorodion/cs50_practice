#include <stdio.h>
#include <stdlib.h>
#include "list.h"


Node *createNode(int number) {
    Node *new = malloc(sizeof(Node));
    new->number = number;
    new->next = NULL;
    return new;
}

List *makeList(int *arr, int start, int end) {
    List *list = malloc(sizeof(List));
    list->head = NULL;
    
    Node *now = list->head;
    for (int i = start; i <= end; i++) {
        Node *new = createNode(arr[i]);
        
        if (now == NULL) {
            list->head = new;
            now = new;
        } else {
            now->next = new;
            now = now->next;
        }
    }
    
    return list;
}

void freeList(List *list) {
    listClear(list);
    free(list);
}

void listPrint(List *list) {
    if (list->head == NULL) {
        printf("List is empty");
    }

    for (Node *now = list->head; now != NULL; now=now->next) {
        printf("%i ", now->number);
    }
    printf("\n");
}

void listAppend(List *list, int number) {
    Node *new = createNode(number);

    if (list->head == NULL) {
        list->head = new;
        return;
    }

    Node *prev = list->head;
    Node *now = prev->next;
    while (now != NULL) {
        prev = now;
        now = now->next;
    }
    prev->next = new;
}


void listAppendleft(List *list, int number) {
    Node *new = createNode(number);

    if (list->head == NULL) {
        list->head = new;
        return;
    }

    new->next = list->head;
    list->head = new;
}

void listRemove(List *list, int number) {
    if (list->head == NULL) {
        return;
    }

    Node *prev = list->head;
    Node *now = prev->next;

    if (prev->number == number) {
        free(prev);
        list->head = now;
        return;
    }

    while (now != NULL) {
        if (now->number == number) {
            Node *next = now->next;
            free(now);
            prev->next = next;
            return;
        }
        prev = now;
        now = now->next;
    }
}

void listPop(List *list) {
    if (list->head == NULL) {
        return;
    }

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }

    Node *prev = list->head;
    Node *now = prev->next;

    while (now->next != NULL) {
        prev = now;
        now = now->next;
    }
    
    free(now);
    prev->next = NULL;
}

void listPopleft(List *list) {
    if (list->head == NULL) {
        return;
    }

    Node *next = list->head->next;
    free(list->head);
    list->head = next;
}

void listInsert(List *list, int number, int index) {
    if (index == 0) {
        listAppendleft(list, number);
        return;
    }

    Node *new = createNode(number);

    if (list->head == NULL) {
        list->head = new;
        return;
    }

    Node *prev = list->head;
    Node *now = prev->next;
    int counter = 1;
    while (now != NULL) {
        if (counter == index) {
            prev->next = new;
            new->next = now;
            return;
        }
        prev = now;
        now = now->next;
        counter++;
    }
    prev->next = new;
}

void listReverse(List *list) {
    if (list->head == NULL || list->head->next == NULL) {
        return;
    }

    Node *prev = NULL;
    Node *now = list->head;
    Node *next = now->next;

    while (next != NULL) {
        now->next = prev;
        
        prev = now;
        now = next;
        next = now->next;
    }
    now->next = prev;
    list->head = now;
}

void listAddSorted(List *list, int number) {
    Node *new = createNode(number);

    if (list->head == NULL) {
        list->head = new;
        return;
    }

    if (number <= list->head->number) {
        new->next = list->head;
        list->head = new;
        return;
    }

    Node *prev = list->head;
    Node *now = prev->next;
    while (now != NULL) {
        if (number <= now->number) {
            prev->next = new;
            new->next = now;
            return;
        }
        prev = now;
        now = now->next;
    }
    prev->next = new;
}

void listClear(List *list) {
    if (list->head == NULL) {
        return;
    }

    Node *now = list->head;
    Node *tmp;

    while (now != NULL) {
        tmp = now->next;
        free(now);
        now = tmp;
    }
}


