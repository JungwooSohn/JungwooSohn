#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {

    int n, k, index = 0;

    scanf("%d%d", &n, &k);
    bool *index_bool = (bool*) calloc(n + 2, sizeof(bool));
    int *index_arr = (int*) calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        if (++index > n) {
            index = 1;
        }
        for (int j = 1; j <= k; j++) {
            while (index_bool[index] == true) {
                if (++index > n) {
                    index = 1;
                }
            }
            if (j != k) {
                if (++index > n) {
                    index = 1;
                }
            }
        }
        index_bool[index] = true;
        index_arr[i] = index;
    }
    if (n == 1) {
        printf("<%d>", 1);
        return 0;
    }

    printf("<%d,", index_arr[1]);
    for (int i = 2; i < n; i++) {
        printf(" %d,", index_arr[i]);
    }
    printf(" %d>", index_arr[n]);
    return 0;
}