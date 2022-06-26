#include <stdio.h>
#include <stdlib.h>

int comparefuca(const void *a, const void *b);
int comparefunc(const void *a, const void *b);

int main(void) {
    int price[] = {900, 750, 200};
    int money;
    int **prob = (int**) malloc(sizeof(int*) * 100);
    int a = 0, b = 2, c = 0, i = 0, k;

    for (i = 0; i < 100; i++) {
        prob[i] = (int*) calloc(3, sizeof(int));
    }
    
    scanf("%d", &money);
    i = 0;
    for (b = 2; money - price[1] * b >= 0; b += 2) {
        for (a = 1; money - price[1] * b - price[0] * a >= 0; a++) {
            for (c = 1;(c < a || c < b) && ((money - (750 * b) - (900 * a) - (200 * c)) >= 0); c++) {
                if ((money - (750 * b) - (900 * a) - (200 * c)) == 0) {
                    prob[i][0] = a;
                    prob[i][1] = b;
                    prob[i][2] = c;
                    i++;
                }
            }
        }

    }

    if (prob[0][0] == 0) {
        printf("%s", "none");
    } else {
        qsort(prob, i, sizeof(int*), comparefuca);
        /*
        qsort(prob, i, sizeof(int*), comparefunc);
        */
        for (k = 0; k < i; k++) {
            printf("%d %d %d", prob[k][0], prob[k][1], prob[k][2]);
            if (k != i - 1) {
                putchar('\n');
            } 
        }
    }


    return 0;
}

int comparefuca(const void *a, const void *b) {
    return (*(int**) a)[0] - (*(int**) b)[0]; 
}

int comparefunc(const void *a, const void *b) {
    return ((*(int**) b)[0] + (*(int**) b)[1] + (*(int**) b)[2]) - ((*(int**) a)[0] + (*(int**) a)[1] + (*(int**) a)[2]); 
}