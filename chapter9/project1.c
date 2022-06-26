#include <stdio.h>

#define N (10)

void selection_sort(int arr[], int size);

int main() {
    int a[N];
    int i = 0;

    printf("Enter series of %d numbers: ", N);

    for(;i < N; ++i) {
        scanf("%d", &a[i]);
    }

    selection_sort(a, N);

    for(i = 0;i < N; ++i) {
        printf("%d ", a[i]);
    }

    return 0;
}

void selection_sort(int arr[], int size) {
    if (size == 1) {
        return;
    }
    int i = 1, max = arr[0], index = 0;
    for(;i < size; ++i) {
        if (arr[i] > arr[index]) {
            index = i;
        }
    }

    max = arr[index];
    arr[index] = arr[size - 1];
    arr[size - 1] = max;
    selection_sort(arr, size - 1);
}
