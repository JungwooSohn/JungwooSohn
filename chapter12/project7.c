/* 배열의 최대 최소 원소를 찾는다 */

#include <stdio.h>

#define ARRAY_SIZE 10

void get_max_min(int arr[], int size, int* out_max, int* out_min);

int main(void)
{
    int int_arr[ARRAY_SIZE] = {0, };
    int i = 0;
    int big = 0;
    int small = 0;
    int* q;

    printf("숫자 %d개를 입력하시오: ", ARRAY_SIZE);
    for (q = int_arr; q < int_arr + ARRAY_SIZE; ++q) {
        scanf("%d", q);
    }

    get_max_min(int_arr, ARRAY_SIZE, &big, &small);

    printf("최대값: %d\n", big);
    printf("최소값: %d\n", small);

    return 0;
}

void get_max_min(int arr[], int size, int* out_max, int* out_min)
{
    int* p;
    *out_max = *out_min = arr[0];
    for (p = arr; p < arr + size; ++p) {
        if (*out_max < *p) {
            *out_max = *p;
        } else if (*p < *out_min) {
            *out_min = *p;
        }
    }
}