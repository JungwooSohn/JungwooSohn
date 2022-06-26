#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 10

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;

struct part *find_part(int number);

void insert(void);
void search(void);
void update(void);
void print(void);

int main() {

    char code;

    for(;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') {
        }

        switch (code) {
            case 'i':
                insert();
                break;
            case 's':
                search();
                break;
            case 'u':
                update();
                break;
            case 'p':
                print();
                break;
            case 'q':
                return 0;
            default: 
                printf("Illegal code\n");
                break;
        }
        printf("\n");
    }

    return 0;
}


struct part *find_part(int number) {
    struct part *p;

    for (p = inventory; p != NULL && number > p->number; p = p->next);

    if(p != NULL && number == p->number) {
        return p;
    }
    return NULL;
}