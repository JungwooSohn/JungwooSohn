#include <stdio.h>

struct date {
    int year, month, day;
};


int main(void) {

    struct date date1, date2;
    struct date first;
    

    scanf("%d /%d /%d%d /%d /%d", &date1.year, &date1.month, &date1.day, &date2.year, &date2.month, &date2.day);

    if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) {
        printf("%.4d/%.2d/%.2d*", date1.year, date1.month, date1.day);
    } else { 

        if (date1.year < date2.year || (date1.year == date2.year && date1.month < date2.month) || (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day)) {
            first = date1;
        } else {
            first = date2;
        }

        printf("%.4d/%.2d/%.2d", first.year, first.month, first.day);
    }
    return 0;
}