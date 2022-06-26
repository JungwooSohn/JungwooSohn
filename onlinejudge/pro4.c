#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_line(char** op, int* a, int* b);

int main(void) {
    int a, b, i, answer;

    char opnum[4];
    char *p = opnum;

    const char *oper[] = {"add", "sub", "mul", "div"};

    read_line(&p, &a, &b);

    for (i = 0; i < 4; i++) {
        if (strcmp(opnum, oper[i]) == 0) {
            break;
        }
    }



    switch(i) {
        case 0:
            answer = a + b;
            break;
        case 1:
            answer = a - b;
            break;
        case 2:
            answer = a * b;
            break;
        case 3:
            if (b == 0) {
                printf("Error");
                return 0;
            }
            answer = a / b;
            break;
        default:
            printf("Error");
            return 0;
    }

    printf("%d", answer);

    return 0;
}


void read_line(char** op, int* a, int* b) {
    int i, blank_count = 0;
    char str[100];
    char *p = str, *q, *r;
    char num1[5], num2[5];

    if (gets(str) == NULL) {
        printf("Error");
        exit(EXIT_SUCCESS);
    }

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            blank_count++;
        }
    }

    if (blank_count != 2) {
        printf("Error");
        exit(EXIT_SUCCESS);
    }

    for (q = p; *q != ' '; q++) {
    }
    
    for (r = p, i = 0; r != q; r++) {
        (*op)[i++] = *r;
    }

    p = q + 1;
    i = 0;
    for (q = p; *q != ' '; q++) {
    }
    
    for (r = p, i = 0; r != q; r++) {
        num1[i++] = *r;
    }

    p = q + 1;
    i = 0;

    for (q = p; *q != '\0'; q++) {
    }
    
    for (r = p, i = 0; r != q; r++) {
        num2[i++] = *r;
    }

    
    if ((*a = atoi(num1)) == 0) {
        if (num1[0] != '0') {
            printf("Error");
            exit(EXIT_SUCCESS);
        }
    }
    if ((*b = atoi(num2)) == 0) {
        if (num2[0] != '0') {
            printf("Error");
            exit(EXIT_SUCCESS);
        }
    } 
}