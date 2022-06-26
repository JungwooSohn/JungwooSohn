#include <stdio.h>
#include <string.h>


int main(void) {

    int carry = 0, i, j, k = 0;

    char num1[101], num2[101], result[102];

    scanf("%s%s", num1, num2);

    for (i = strlen(num1) - 1, j = strlen(num2) - 1; i >= 0 && j >= 0; i--, j--) {
        result[k++] = (num1[i] - '0' + num2[j] - '0' + carry) % 10;
        carry = (num1[i] - '0' + num2[j] - '0' + carry) / 10;
    }

    if (i < 0) {
        for (;j >= 0; j--) {
            result[k++] = (num2[j] - '0' + carry) % 10;
            carry = (num2[j] - '0' + carry) / 10;
        }
    }

    if (j < 0) {
        for (;i >= 0; i--) {
            result[k++] = (num1[i] - '0' + carry) % 10;
            carry = (num1[i] - '0' + carry) / 10;
        }
    }
    k--;
    for (; k >= 0; k--) {
        putchar(result[k] + '0');
    }


    return 0;
}