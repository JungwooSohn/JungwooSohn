#include <stdio.h>

int arr[1000000];

int main(void) {

    int n, i, count = 0;
    scanf("%d", &n);


    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] > arr[j]) count++;
        }
        printf("%d ", count);
    }


    count = 0;
    for (int j = 0; j < n; j++) {
        if (arr[i] > arr[j]) count++;
    }
    printf("%d", count);
    return 0;
}

