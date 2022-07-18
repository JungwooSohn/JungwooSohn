#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* func(int n){
    // TODO
    int i = 0;
    int *new_arr = (int*) malloc(sizeof(int) * n);

    if (new_arr == NULL) {
        exit(EXIT_FAILURE);
    }

    for (; i < n; i++) {
        scanf("%d", &new_arr[i]);
    }

    return new_arr;
}

void BubbleSort(int* arr, int n){
    // TODO
    int i = n - 1, j = 0, temp = 0;

    for (; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void PrintTheArr(int arr[], int cnt){
    for(int i = 0; i < cnt; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int num_cnt;
    scanf("%d", &num_cnt);

    int* num = func(num_cnt);
    PrintTheArr(num, num_cnt);
    BubbleSort(num, num_cnt);
    PrintTheArr(num, num_cnt);
    return 0;
}