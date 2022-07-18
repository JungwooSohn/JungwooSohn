#include <stdio.h>

int main(void) {
    int t, num1, num2;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d%d", &num1, &num2);
        printf("%d", num1 + num2);
        if (i != t - 1) {
            putchar('\n');
        }
    }

    return 0;
}