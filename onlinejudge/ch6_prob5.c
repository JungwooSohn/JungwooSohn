#include <stdio.h>

int main(void) {

    int buf[100];
    int n, i, max, second_max;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &buf[i]);
    }

    max = buf[0];
    second_max = buf[1];

    for (i = 1; i < n; i++) {
        if (buf[i] > max) {
            second_max = max;
            max = buf[i];
        } else if (buf[i] > second_max) {
            second_max = buf[i];
        }
    }

    printf("%d\n%d", max, second_max);

    return 0;
}