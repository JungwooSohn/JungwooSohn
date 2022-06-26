#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n, i, k, j = 0, sum = 0;
    char temp[1001];
    scanf("%d", &n);

    char** strbuf = (char**) malloc(sizeof(char*) * (n + 1));

    for (i = 0; i < n + 1; i++) {
        scanf("%s", temp);
        strbuf[i] = (char*) malloc(sizeof(char) * (strlen(temp) + 1));
        strcpy(strbuf[i], temp);
        strcpy(temp, "");
    }

    for (i = 0; i < n; i++) {
        for (k = 0; k < (int) strlen(strbuf[i]) - (int) strlen(strbuf[n]) + 1; k++) {
            if (strbuf[i][k] == strbuf[n][0]) {
                for (j = 0; j < strlen(strbuf[n]); j++) {
                    if (strbuf[i][k + j] != strbuf[n][j]) {
                        j = 0;
                        break;
                    }
                }
            }
            if (j == strlen(strbuf[n])) {
                sum++;
                j = 0;
                break;
            }
        }
    }

    printf("%d", sum);

    for (i = 0; i < n + 1; i++) {
        free(strbuf[i]);
    }
    free(strbuf);

    return 0;
}