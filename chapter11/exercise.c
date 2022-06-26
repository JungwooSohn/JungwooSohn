#include <stdio.h>

void swap(int* p, int* q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void split_time(long total_sec, int *hr, int *min, int* sec) {
    *hr = total_sec / 3600;
    *min = total_sec / 60 % 60;
    *sec = total_sec % 60;
}
void find_two_largest(int arr[], int n, int *largest, int *second_largest);



int main() {


    int arr[10];
    int largest, second_largest;
    printf("Enter 10 numbers: ");
    for(int i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);
    }

    find_two_largest(arr, 10, &largest, &second_largest);
    printf("largest: %d, second largest: %d", largest, second_largest);


    return 0;
}

void find_two_largest(int arr[], int n, int *largest, int *second_largest) {
    int i;
    
    *largest = arr[0];
    *second_largest = arr[0];
    
    for(i = 0; i < n; ++i) {
        if(arr[i] >= *largest) {
            *second_largest = *largest;
            *largest = arr[i];
        } else if (arr[i] >= *second_largest) {
            *second_largest = arr[i];
        }
    }
}

void split_date(int day_of_year, int year, int *month, int *day) {
    int day_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int temp_day = day_of_year;
    int i = 1;
    if((year % 4 == 0) - (year % 100 == 0) + (year % 400 == 0)) {
        day_of_month[2] = 29;
    } else {
        day_of_month[2] = 28;
    }


    while(1) {
        temp_day -= day_of_month[i];
        if(temp_day <= 0) {
            temp_day += day_of_month[i--];
            break;
        }
    }
    *month = i;
    *day = temp_day;

}

int *find_largest(int a[], int n) {
    int i;
    int max_index = 0;
    for(i = 0; i < n; ++i) {
        if(a[i] >= a[max_index]) {
            max_index = i;
        }
    }

    return &a[max_index];
}