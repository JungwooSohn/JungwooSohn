#include <stdio.h>

#define LEN (10)

int sum_two_dimensional_array(const int a[][LEN], int n);

int main() {

    const int arr[10][LEN] = {1,2,4,5,6,7,8,9,10,1,2,3};

    printf("%d", sum_two_dimensional_array(arr, 10 * LEN));

    return 0;
}


int sum_two_dimensional_array(const int a[][LEN], int n) {
    int sum = 0;
    const int *p;

    for(p = a[0]; p < a[0] + n; p++) {
        sum += *p;
    }

    return sum;
}

