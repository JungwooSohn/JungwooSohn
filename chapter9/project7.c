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
    // n = 0�ϋ� 1�� ��ȯ
    if (n == 0) {
        return 1;
    }
    
    //n / 2�� ���� ��ȯ
    if (n % 2 == 0) {
        result = power(x, n / 2);
        return result * result;
    } else {
        return x * power(x, n-1);
    }



}