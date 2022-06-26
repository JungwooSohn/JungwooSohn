#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);
    while(n % 10 == 0) {
        n /= 10;
    }

    while (n > 0) {
        printf("%d", n % 10);
        n /= 10;
    }
    
    return 0;
}