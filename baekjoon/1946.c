#include <stdio.h>
#include <stdlib.h>

typedef struct ranking {
    int first_test, second_test;
} Ranking;

int compareFunc(const void *p, const void *q);

int main(void) {

    int test_case_num, i, j, k;

    scanf("%d", &test_case_num);

    int count_arr[test_case_num];

    for (i = 0; i < test_case_num; i++) {
        int n, count = 1, second_min;
        scanf("%d", &n);
        Ranking member[n];

        for (j = 0; j < n; j++) {
            scanf("%d%d", &member[j].first_test, &member[j].second_test);
        }
        
        qsort(member, n, sizeof(Ranking), compareFunc);
        second_min = member[0].second_test;
        for (j = 1; j < n; j++) {
            if (member[j].second_test > second_min) {

            } else {
                count++;
                second_min = member[j].second_test;
            }
        }

        count_arr[i] = count;
    }

    printf("%d", count_arr[0]);

    for (i = 1; i < test_case_num; i++) {
        printf("\n%d", count_arr[i]);
    }
    return 0;
}

int compareFunc(const void *p, const void *q) {
    return (*(Ranking*)p).first_test - (*(Ranking*)q).first_test;
}