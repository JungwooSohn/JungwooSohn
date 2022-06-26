#include <stdio.h>

#define N (10)

int main(void) {

    int a[N];
    int i;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= N; ++i) {
        printf("%d ", a[N - i]);
    }
    printf("\n");
    return 0;
}