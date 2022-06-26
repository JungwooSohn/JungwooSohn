#include <stdio.h>
#include <stdlib.h>

int comparefunc(const void *, const void *);

struct class_time {
    int start_hour, start_minute, end_hour, end_minute;
};


int main(void) {
    struct class_time school[8];
    int n, i;

    for (i = 0; i < 8; i++) {
        scanf("%d%d%d%d", &school[i].start_hour, &school[i].start_minute, &school[i].end_hour, &school[i].end_minute);
    }

    scanf("%d", &n);

    qsort(school, 8, sizeof(struct class_time), comparefunc);

    printf("%.2d-%.2d:%.2d-%.2d", school[n - 1].start_hour, school[n - 1].start_minute, school[n - 1].end_hour, school[n - 1].end_minute);


    return 0;
}

int comparefunc(const void *class1, const void *class2) {
    return ((struct class_time *) class1)->start_hour * 60 + ((struct class_time *) class1)->start_minute - ((struct class_time *) class2)->start_hour * 60 - ((struct class_time *) class2)->start_minute;
}

