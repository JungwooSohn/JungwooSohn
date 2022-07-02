#include <stdio.h>

int fibo_recursive(int n);

int main(void) {

    for (int i = 1; i <= 10; i++) {
        printf("%d ", fibo_recursive(i));
    }

    return 0;
}

int fibo_recursive(int n) {

    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }

    return fibo_recursive(n - 1) + fibo_recursive(n - 2);
}