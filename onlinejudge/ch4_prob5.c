#include <stdio.h>

int main(void) {
    int n, a;
    scanf("%d", &n);

    a = n % 1000;

    if (a >= 500) {
        n += 1000 - a;
    } else {
        n -= a;
    }

    printf("%d", n);

    return 0;
}