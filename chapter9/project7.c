#include <stdio.h>

int power(int x, int n);

int main() {
    int x, n;

    printf("Enter value of x: ");
    scanf("%d", &x);
    printf("Enter value of n: ");
    scanf("%d", &n);

    printf("Value: %d", power(x, n));


    return 0;
}

int power(int x, int n) {
    int result;
    // n = 0일떄 1을 반환
    if (n == 0) {
        return 1;
    }
    
    //n / 2의 값을 반환
    if (n % 2 == 0) {
        result = power(x, n / 2);
        return result * result;
    } else {
        return x * power(x, n-1);
    }



}