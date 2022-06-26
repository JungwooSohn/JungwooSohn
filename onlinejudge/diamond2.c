#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int height, i, j, k;

    scanf("%d", &height);

    char **diamond = (char**) calloc(height, sizeof(char*));

    for (i = 0; i < height; i++) {
        diamond[i] = (char*) calloc(height, sizeof(char));
    }

    for (i = 1; i <= height / 2 + 1; i++) {
        for (j = 1; j <= height / 2 + 1 + i - 1; j++) {
            diamond[i - 1][j - 1] = ' ';
        }
    }

    for (i = height / 2 + 1; i <= height; i++) {
        for (j = 1; j <= height - i + height / 2 + 1; j++) {
            diamond[i - 1][j - 1] = ' ';
        }
    }

    for (i = 1; i <= height; i++) {
        diamond[i - 1][height / 2 + 1 - 1] = '*';
    }

    for (j = 1; j <= height; j++) {
        diamond[height / 2 + 1 - 1][j - 1] = '*';
    }

    for (i = 1, j = height / 2 + 1; i <= height / 2 + 1; i++, j--) {
        diamond[i - 1][j - 1] = '*';
    }

    for (i = 1, j = height / 2 + 1; i <= height / 2 + 1; i++, j++) {
        diamond[i - 1][j - 1] = '*';
    }

    for (i = height / 2 + 1, j = 1; j <= height / 2 + 1; i++, j++) {
        diamond[i - 1][j - 1] = '*';
    }

    for (i = height / 2 + 1, j = height; j >= height / 2 + 1; i++, j--) {
        diamond[i - 1][j - 1] = '*';
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < height; j++) {
            if (diamond[i][j] != '\0') {
                putchar(diamond[i][j]);
            }
        }
        if (i != height - 1) {
            putchar('\n');
        }
    }

    return 0;
}