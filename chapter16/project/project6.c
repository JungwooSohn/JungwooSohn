#include <stdio.h>

struct date {
    int month, day, year;
};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);


int main() {
    struct date date1, date2;
    int flag;

    printf("Enter first date (mm/dd/yyyy): ");
    scanf("%d /%d /%d", &date1.month, &date1.day, &date1.year);
    printf("Enter second date (mm/dd/yyyy): ");
    scanf("%d /%d /%d", &date2.month, &date2.day, &date2.year);

    flag = compare_dates(date1, date2);

    if(flag > 0) {
        printf("%d/%d/%d is earlier than %d/%d/%d", date1.month, date1.day, date1.year, date2.month, date2.day, date2.year);
    } else if(flag < 0) {
        printf("%d/%d/%d is earlier than %d/%d/%d", date2.month, date2.day, date2.year, date1.month, date1.day, date1.year);
    } else {
        printf("%d/%d/%d is equal to %d/%d/%d", date1.month, date1.day, date1.year, date2.month, date2.day, date2.year);
    }

    return 0;
}




int day_of_year(struct date d) {
    int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0, i;

    if((d.year % 4 == 0) - (d.year % 100 == 0) + (d.year % 400 == 0)) {
        sum += 1;
    }

    for(i = 0; i < d.month - 1; i++) {
        sum += month[i];
    }

    sum += d.day;
    return sum;
}

int compare_dates(struct date d1, struct date d2) {
    int d1day = day_of_year(d1);
    int d2day = day_of_year(d2);

    if (d1day > d2day) {
        return -1;
    } else if (d1day < d2day) {
        return 1;
    } else {
        return 0;
    }
}