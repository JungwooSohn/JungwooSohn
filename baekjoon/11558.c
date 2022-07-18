#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, next, count = 0;
        scanf("%d", &n);
        int graph[n + 1];
        bool *is_pointed = (bool*) calloc(n + 1, sizeof(bool));
        bool is_printed = false;

        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[j]);
        }
        next = graph[1];
        while (true) {
            if (is_pointed[next] == false) {
                is_pointed[next] = true;
            } else {
                if (i == 0) {
                    printf("%d", 0);
                } else {
                    printf("\n%d", 0);
                }
                is_printed = true;
                break;
            }

            count++;

            if (next == n) {
                break;
            }
            next = graph[next];
        }
        if (is_printed == false) {
            if (i == 0) {
                printf("%d", count);
            } else {
                printf("\n%d", count);
            }
        }


        free(is_pointed);
    }

    return 0;
}