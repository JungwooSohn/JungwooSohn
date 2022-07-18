#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int n, k, i, j, count = 0;

    scanf("%d%d", &n, &k);

    int *arr = (int*) calloc(n + 1, sizeof(int));
    i = 2;
    while (i <= n) {
        for (j = i; j <= n; j += i) {
            if (arr[j] == 0) {
                arr[j]++;
                if (++count == k) {
                    i = n + 1;
                    break;
                }
            }
                
        }
        while (1) {
            if (arr[++i] == 0) {
                break;
            }
        }
    }

    printf("%d", j);

    free(arr);

    return 0;
}