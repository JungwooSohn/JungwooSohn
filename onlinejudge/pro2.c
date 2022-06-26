#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *str1, const void *str2);

int main(void) {
    int i, m, len = 0, j, word = 0;
    char *dic[60];

    char buffer[100] = {'\0',};
    char *pt = buffer;

    scanf("%d", &m);
    getchar();
    gets(buffer);


    for (i = 0;;) {
        if (buffer[i] == '\0') {
            break;
        }
        while (buffer[i++] != ' ') {
            len++;
            if (buffer[i] == '\0') {
                break;
            }
        }

        dic[word] = (char*) malloc(sizeof(char) * (len + 1));

        for (j = 0; j < len; j++) {
            dic[word][j] = *pt++;
        }
        dic[word++][j] = '\0';
        len = 0;
        pt++;
    }

    qsort(dic, word, sizeof(char*), cmpfunc);
    printf("%s", dic[m - 1]);
    
    return 0;
}


int cmpfunc(const void *str1, const void *str2) {
    return strcmp(*(char**) str1, *(char**) str2);
}