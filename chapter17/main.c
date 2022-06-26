#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point {
    int x, y;
} *p;

struct node {
    int value;
    struct node *next;
};


int main() {

    void (*pf)(int);

    struct node *first = NULL;
    struct node *new_node;

    new_node = malloc(sizeof(struct node));

    new_node->value = 10;

    new_node->next = first;

    first = new_node;

    return 0;
}

char *concat(const char* s1, const char* s2) {
    char *result;

    result = malloc(strlen(s1) + strlen(s2) + 1);
    if(result == NULL) {
        exit(EXIT_FAILURE);
    }

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}

struct node *add_to_list(struct node *list, int n) {
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if(new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = n;
    new_node->next = list;
    return new_node;
}