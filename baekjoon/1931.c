#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct meeting {
    int start_time, end_time;
} Meeting;

int comparefunc2(const void *p, const void *q);

int main(void) {

    int n, end_hour, count = 1, idx = 0;
    scanf("%d", &n);


    Meeting arr2[n];

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &arr2[i].start_time, &arr2[i].end_time);
    }


    qsort(arr2, n, sizeof(Meeting), comparefunc2);
    
    end_hour = arr2[0].end_time;

    while (true) {
        if (arr2[++idx].start_time >= end_hour) {
            end_hour = arr2[idx].end_time;
            count++;
        }

        if (idx >= n - 1) {
            break;
        }
    }

    printf("%d", count);

    return 0;
}



int comparefunc2(const void *p, const void *q) {
    if ((*(Meeting*)p).end_time > (*(Meeting*)q).end_time) {
        return 1;
    }

    if ((*(Meeting*)p).end_time == (*(Meeting*)q).end_time) {
        if ((*(Meeting*)p).start_time > (*(Meeting*)q).start_time) {
            return 1;
        }

        if ((*(Meeting*)p).start_time == (*(Meeting*)q).start_time) {
            return 0;
        }

        if ((*(Meeting*)p).start_time < (*(Meeting*)q).start_time) {
            return -1;
        }
    }

    if ((*(Meeting*)p).end_time < (*(Meeting*)q).end_time) {
        return -1;
    }
}

