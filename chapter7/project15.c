#include <stdio.h>

int main() {

    int num;
    int value = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    for(int i = num ; i > 0; --i) {
        value *= i;
    }

    printf("Factorial of %d: %d", num, value);

    return 0;
}