#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n, i, j, k, sum1 = 0, sum2 = 0;
    char buf[30];
    scanf("%d", &n);
    
    char** wordlist = (char**) malloc(sizeof(char*) * n);

    for (i = 0; i < n; i++) {
        scanf("%s", buf);
        wordlist[i] = (char*) malloc(sizeof(char) * (strlen(buf) + 1));
        strcpy(wordlist[i], buf);
    }

    int *numlist = (int*) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        numlist[i] = strlen(wordlist[i]);
    }

    int *prob = (int*) calloc(n - 1, sizeof(int));
    int first = 0;
    for (i = 0; i < n - 1; i++) {
        sum1 = 0;
        sum2 = 0;
        first = 0;
        for (j = 0; j <= i; j++) {
            if (first != 0) {
                sum1++;
            }
            sum1 += numlist[j];
            first++;
        }

        first = 0;
        for (j = i + 1; j < n; j++) {
            if (first != 0) {
                sum2++;
            }
            sum2 += numlist[j];
            first++;
        }

        prob[i] = abs(sum1 - sum2);
    }
    int maxindex = 0;
    int max = prob[0];
    for (i = 0; i < n - 1; i++) {
        if (prob[i] <= max) {
            maxindex = i;
            max = prob[i];
        }
    }

    for (i = 0; i <= maxindex; i++) {
        printf("%s", wordlist[i]);
        if (i != maxindex) {
            putchar(' ');
        }
    }

    printf("\n");

    for (i = maxindex + 1; i < n; i++) {
        printf("%s", wordlist[i]);
        if (i != n - 1) {
            putchar(' ');
        }
    }
    return 0;
} 