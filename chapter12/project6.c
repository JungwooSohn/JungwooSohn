/* �������� �˰����� �̿��� ������ �迭�� �������ش� */

#include <stdio.h>

#define N (10)

void quicksort_recursive(int arr[], int *low, int *high);
int* split(int arr[], int* low, int* high);

int main(void)
{
    int arr[N] = {0, };
    int i = 0;

    printf("������ ���� %d���� �Է��ϼ���: ", N);
    for (i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    quicksort_recursive(arr, arr, &arr[N-1]);

    printf("���� ����: ");
    for (i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void quicksort_recursive(int arr[], int *low, int *high)
{
    int *middle = 0;

    if (low >= high) {
        return;
    }

    middle = split(arr, low, high);
    quicksort_recursive(arr, low, middle - 1);
    quicksort_recursive(arr, middle + 1, high);

}

int* split(int arr[], int* low, int* high)
{
    int part_element = *low;

    for (;;) {
        while (low < high && part_element <= *high) {
            --high;
        }

        if (low >= high) {
            break;
        }

        *low++ = *high;

        while (low < high && *low <= part_element) {
            ++low;
        }

        if (low >= high) {
            break;
        }

        *high-- = *low;
    }

    *high = part_element;

    return high;
}