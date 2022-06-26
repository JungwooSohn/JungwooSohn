#include <stdio.h>

int check(int x, int y, int n);
int gcd(int m, int n);
int day_of_year (int month, int day, int year);

int main() {
    printf("%d", day_of_year(12, 25, 2003));

    return 0;
}

int check(int x, int y, int n) {
    if(x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1) {
        return 1;
    } else {
        return 0;
    }
}

int gcd(int m, int n) {
    int temp = 0;
    for (;;) {
        if (m % n == 0) {
            return n;
        } else {
            temp = m % n;
            m = n;
            n = temp;
        }
    }
}

int day_of_year (int month, int day, int year) {
    int sum = 0;
    int day_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if((year % 4 == 0) - (year % 100 == 0) + (year % 400 == 0)) {
        day_of_month[2] = 29;
    } else {
        day_of_month[2] = 28;
    }

    for(int i = 1; i < month; ++i) {
        sum += day_of_month[i];
    }
    

    sum += day;

    return sum;
}

int num_digits(int n) {
    int len = 0;
    do {
        n /= 10;
        len++;
    } while(n > 0);

    return len;
}

int digit(int n, int k) {
    for(; k > 1; k--) {
        k /= 10;
    }
    return k % 10;
}
