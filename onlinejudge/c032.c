#include <stdio.h>

int main(void) {

    int n, k = 0, l;

    scanf("%d", &n);
    l = n;
    k += n % 10 * 1000;
    n /= 10;
    k += n % 10 * 100;
    n /= 10;
    k += n % 10 * 10;
    n /= 10;
    k += n;

    if (k > l) {
        printf("%d", k);
    } else {
        printf("%d", l);
    }

    return 0;
}