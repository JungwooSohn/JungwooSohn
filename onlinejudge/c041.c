#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strcompare(const void* str1, const void* str2);

int main(void) {
    int n, i;
    char strbuf[1001];

    scanf("%d", &n);

    char **strptr = (char**) malloc(sizeof(char*) * n);

    for (i = 0; i < n; i++) {
        scanf("%s", strbuf);
        strptr[i] = (char*) malloc(sizeof(char) * (strlen(strbuf) + 1));
        strcpy(strptr[i], strbuf);
        strcpy(strbuf, "");
    }

    qsort(strptr, n, sizeof(char*), strcompare);

    for (i = 0; i < n; i++) {
        printf("%s", strptr[i]);
        if (i != n - 1) {
            putchar('\n');
        }
    }

    return 0;
}

int strcompare(const void* str1, const void* str2) {
    return strlen(*(char**) str1) - strlen(*(char**) str2);
}