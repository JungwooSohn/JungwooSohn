#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (void) {




    int aplha[26] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

    int i, j, k = 0;
    char name1[20], name2[20], name3[40] = {'\0',};
    int namenum1[40] = {0,}, namenum2[40] = {0,};

    scanf("%s", name1);
    scanf("%s", name2);

    for (i = 0, j = 0; i < strlen(name1) && j < strlen(name2); i++, j++) {
        if (i < strlen(name1) - 1) {
            name3[k++] = name1[i];
        }
        if (i < strlen(name2) - 1) {
            name3[k++] = name2[j];
        }
    }

    name3[k] = '\0';

    for (i = 0;i < strlen(name3); i++) {
        namenum1[i] = aplha[name3[i] - 'A'];
    }
    j = strlen(name3);
    k = 0;

    for(;;) {
        if (j <= 2) {
            printf("%d", namenum2[0]);
            break;
        }
        for (i = 0; i < j - 1; i += 2) {
            namenum2[k++] = (namenum1[i] + namenum1[i + 1]) % 10;
        }
        if (j / 2 != 0) {
            namenum2[k] = namenum1[j - 1];
        }

        j = k + 1;
        k = 0;

        if (j <= 2) {
            printf("%d", namenum2[0]);
            break;
        }
        for (i = 0; i < j - 1; i += 2) {
            namenum1[k++] = (namenum2[i] + namenum2[i + 1]) % 10;
        }
        if (j / 2 != 0) {
            namenum1[k] = namenum2[j - 1];
        }

        j = k + 1;
        k = 0;
    }

    return 0;
}

