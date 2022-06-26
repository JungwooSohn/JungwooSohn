#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i, k, temp;

    scanf("%d", &n);


    char **diamond = (char**) calloc(n, sizeof(char*));

    for (i = 0; i < n; i++) {
        diamond[i] = (char*) calloc(n, sizeof(char));
    }

    for (i = 0; i < n / 2; i++) {
        for (k = 0; k < n / 2 + i; k++) {
            diamond[i][k] = ' ';
        }
    }
    temp = n;
    for (i = n / 2; i < n; i++) {
        for (k = 0; k < temp; k++) {
            diamond[i][k] = ' ';
        }
        temp--;
    }


    i = n / 2;
    for (k = 0; k < n; k++) {
        diamond[i][k] = '*';
        diamond[k][i] = '*';
    }


    for (k = 0, i = n / 2; k <= n / 2; k++, i--) {
        diamond[i][k] = '*';
    }

    for (k = 0, i = n / 2; k <= n / 2; k++, i++) {
        diamond[i][k] = '*';
    }

    for (k = 0, i = n / 2; k <= n / 2; k++, i++) {
        diamond[k][i] = '*';
    }

    for (k = n - 1, i = n / 2; k >= n / 2; k--, i++) {
        diamond[i][k] = '*';
    }


    for(i = 0; i < n; i++) {
        for(k = 0; k < n; k++) {
            if (diamond[i][k] != '\0') {
                putchar(diamond[i][k]);
            }
        }
        if(i != n - 1) {
            putchar('\n');
        }
    }

    for (i = 0; i < n; i++) {
        free (diamond[i]);
    }
    free(diamond);
    return 0;
}