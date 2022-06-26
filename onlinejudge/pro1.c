#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char str[100];
    int length, index;
    struct node *next;
};


void insert_node(struct node **list, char *str, int length, int index);
int read_line(struct node **list);
void print_str(struct node **list, int index);
int find_word(struct node **list);



int main(void) {
    int index, i;
    struct node *first = NULL;

    index = read_line(&first);

    for (i = 0; i < index; i++) {
        print_str(&first, i);
        putchar('\n');
    }

    printf("%d", find_word(&first));    



    return 0;
}

int read_line(struct node **list) {
    int ch = 0;
    int n, length = 0, index = 0;
    char strbuf[100];
    // first line
    while (ch != '\n') {
        while ((ch = getchar()) != ' ' && ch != '\n') {
            strbuf[length++] = ch;
        }
        strbuf[length] = '\0';
        insert_node(list, strbuf, length, index);
        length = 0;
        index++;
        strcpy(strbuf, "");
    }
    //second line
    while ((ch = getchar()) != '\n' && ch != EOF) {
        strbuf[length++] = ch;
    }
    strbuf[length] = '\0';
    insert_node(list, strbuf, length, index);
    
    return index;
}

void insert_node(struct node **list, char *str, int length, int index) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->index = index;
    new_node->length = length;
    new_node->next = NULL;
    strcpy(new_node->str, str);

    if (*list == NULL) {
        *list = new_node;
    } else {
        new_node->next = *list;
        *list = new_node;
    }

}

void print_str(struct node **list, int index) {
    if (*list == NULL) {
        return;
    }
    struct node *prev;
    for (prev = *list; prev != NULL; prev = prev->next) {
        if (prev->index == index) {
            printf("%s", prev->str);
            break;
        }
    }
}

int find_word(struct node **list) {
    struct node *prev;
    int result = 0;
    prev = *list;
    prev = prev->next;

    for (; prev != NULL; prev = prev->next) {
        if (prev->length == (*list)->length) {
            if (strcmp(prev->str, (*list)->str) == 0) {
                result++;
            }
        }
    }
    return result;
}