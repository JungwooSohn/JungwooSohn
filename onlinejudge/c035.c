#include <stdio.h>

int main(void) {

    int a, b, temp1, temp2, temp3, gcm;

    scanf("%d%d", &a, &b);
    temp1 = a;
    temp2 = b;

    while (temp2 > 0) {
        temp3 = temp1 % temp2;
        temp1 = temp2;
        temp2 = temp3;
    }

    gcm = (a / temp1) * (b / temp1) * temp1;

    printf("%d %d", temp1, gcm);

    return 0;
}