#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "construction.h"

void printsp(struct Pepper *p) {
    printf("%s has a Scoville score of %d\n", p->name, p->scoville);
}

struct Pepper * new_pepper(char* n, int s) {
    struct Pepper * np;
    np = malloc( sizeof(struct Pepper) );
    strncpy(np->name, n, sizeof(np->name) - 1);
    np->scoville = s;
    return np;
}

void change_pepper(struct Pepper* p, char* n, int s) {
    strncpy(p->name, n, sizeof(p->name) - 1);
    p->scoville = s;
}

void print_list(struct Pepper * node) {
    printsp(node);
    if (node->next) {
        struct Pepper *next_node = node->next;
        while(next_node) {
            printsp(next_node);
            next_node = next_node->next;
        }
    }
    printf("\n");
}

struct Pepper* insert_front(struct Pepper* node, char* n, int s) {
    struct Pepper* first = new_pepper(n, s);
    first->next = node;
    return first;
}

struct Pepper * free_list(struct Pepper * p) {
    struct Pepper *cur = p;
    while (cur) {
       struct Pepper *n = cur->next;
       free(cur);
       cur = n;
   }
   printf("List freed");
   return cur;
}

struct Pepper * remove_node(struct Pepper *front, char* n, int s) {

    struct Pepper* cur = front;

    if (!strcmp(cur->name, n)) {
        cur = front->next;
        free(front);
        return cur;
    }

    while(cur->next != NULL) {
        struct Pepper *skip = cur->next;
        if(!strcmp(skip->name, n)) {
            cur->next = skip->next;
            free(skip);
            return front;
        } else cur = cur->next;
    }
    return front;
}
