#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n, i, frequency = 0, k;
    char buffer[1001], c;
    scanf("%d", &n);


    char **strbuf = (char**) malloc(sizeof(char*) * n);

    for (i = 0; i < n; i++) {
        scanf("%s", buffer);
        strbuf[i] = (char*) malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(strbuf[i], buffer);
        strcpy(buffer, "");
    }

    if ((c = getchar()) == '\n') {
        c = getchar();
    }

    for (i = 0; i < n; i++) {
        for (k = 0; k < strlen(strbuf[i]); k++) {
            if (tolower(strbuf[i][k]) == c) {
                frequency++;
            }
        }
    }

    printf("%d", frequency);

    for (i = 0; i < n; i++) {
        free(strbuf[i]);
    }

    free(strbuf);

    return 0;
}