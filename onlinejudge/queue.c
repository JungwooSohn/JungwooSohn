#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue {
    int value;
    struct queue *next;
};

void push(struct queue **list, int x);
void pop(struct queue **list);
void size(struct queue **list);
void empty(struct queue **list);
void front(struct queue **list);
void back(struct queue **list);

int main(void) {

    int n, i, x, flag = 0;;
    char instruction[20];
    scanf("%d", &n);

    struct queue *first = NULL;

    for (i = 0; i < n; i++) {
        scanf("%s", instruction);

        if (strcmp(instruction, "push") == 0) {
            scanf("%d", &x);
            push(&first, x);
        } else if (strcmp(instruction, "pop") == 0) {
            if (flag != 0) {
                putchar('\n');
            }
            pop(&first);
            flag++;
        } else if (strcmp(instruction, "size") == 0) {
            if (flag != 0) {
                putchar('\n');
            }
            size(&first);
            flag++;
        } else if (strcmp(instruction, "empty") == 0) {
            if (flag != 0) {
                putchar('\n');
            }
            empty(&first);
            flag++;
        } else if (strcmp(instruction, "front") == 0) {
            if (flag != 0) {
                putchar('\n');
            }
            front(&first);
            flag++;
        } else if (strcmp(instruction, "back") == 0) {
            if (flag != 0) {
                putchar('\n');
            }
            back(&first);
            flag++;
        }
    }

    return 0;
}

void push(struct queue **list, int x) {
    struct queue *new = (struct queue*) malloc(sizeof(struct queue)); 

    new->value = x;

    if (*list == NULL) {
        new->next = NULL;
        *list = new;
        return;
    } else {
        new->next = *list;
        (*list) = new;
        return;
    }
}

void pop(struct queue **list) {
    struct queue *prev, *cur, *cur2;

    if (*list == NULL) {
        printf("%d", -1);
        return;
    }

    for (prev = *list, cur = NULL, cur2 = NULL; prev != NULL; cur2 = cur, cur = prev, prev = prev->next) {
    }

    printf("%d", cur->value);

    if (cur2 == NULL) {
        *list = NULL;
        return;
    }

    cur2->next = NULL;
    
    free(cur);
}

void size(struct queue **list) {
    if (*list == NULL) {
        printf("%d", 0);
        return;
    }

    struct queue *prev;
    int i = 0;

    for (prev = *list; prev != NULL; prev = prev->next) {
        i++;
    }

    printf("%d", i);
}

void empty(struct queue **list) {
    if (*list == NULL) {
        printf("%d", 1);
    } else {
        printf("%d", 0);
    }
}

void front(struct queue **list) {
    struct queue *prev, *cur;

    if (*list == NULL) {
        printf("%d", -1);
        return;
    }

    for (prev = *list, cur = NULL; prev != NULL; cur = prev, prev = prev->next) {
    }

    printf("%d", cur->value);
}

void back(struct queue **list) {
    if (*list == NULL) {
        printf("%d", -1);
        return;
    }

    printf("%d", (*list)->value);
}