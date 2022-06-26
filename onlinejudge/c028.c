#include <stdio.h>

int main(void) {
    int n, fee = 3800;
    scanf("%d", &n);


    n -= 2000;

    while ((n -= 132) >= 0) {
        fee += 100;
    }

    printf("%d", fee);


    return 0;
}