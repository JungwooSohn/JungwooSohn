#include <stdio.h>
#include <stdlib.h>


int main(void) {

    int height, i, j;

    scanf("%d", &height);

    char** sandglass = (char**) calloc(height, sizeof(char*));

    for (i = 0; i < height; i++) {
        sandglass[i] = (char*) calloc(height, sizeof(char));
    }

    for (i = 1; i <= height / 2 + 1; i++) {
        for (j = 1; j <= height - i + 1; j++) {
            sandglass[i - 1][j - 1] = ' ';
        }
    }

    for (i = height / 2 + 1; i <= height; i++) {
        for (j = 1; j <= i; j++) {
            sandglass[i - 1][j - 1] = ' ';
        }
    }

    for (i = 1, j = 1; j <= height; j++) {
        sandglass[i - 1][j - 1] = '*';
    }

    for (i = height, j = 1; j <= height; j++) {
        sandglass[i - 1][j - 1] = '*';
    }

    for (i = 1, j = 1; i <= height; i++, j++) {
        sandglass[i - 1][j - 1] = '*';
    }

    for (i = 1, j = height; i <= height; i++, j--) {
        sandglass[i - 1][j - 1] = '*';
    }

    for (i = height / 2 + 1; i <= height; i++) {
        for (j = i; j >= (height / 2 + 1) * 2 - i; j--) {
            sandglass[i - 1][j - 1] = '*';
        }
    }


    for (i = 0; i < height; i++) {
        for (j = 0; j < height; j++) {
            if (sandglass[i][j] != '\0') {
                putchar(sandglass[i][j]);
            }
        }
        if (i != height - 1) {
            putchar('\n');
        }
    }

    return 0;
}