#include <stdio.h>
#include <math.h>

#define TOTAL (hour * 60 + minute)

int main() {

    const int departure_time[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    const int arrival_time[8] = {616, 712, 811, 900, 968, 1075, 1280, 1398};

    int hour, minute, selector = 0, dif1, dif2;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);

    dif1 = abs(TOTAL - departure_time[selector]);

    for (int i = 1; i < 8; i++) {
        dif2 = abs(TOTAL - departure_time[i]);
        if(dif2 <= dif1) {
            selector = i;
            dif1 = dif2;
        }
    }
    hour = departure_time[selector] / 60;
    printf("Closest departure time is %d:%.2d ", ((hour % 12) == 0) ? (hour % 12 + 12) : hour % 12, departure_time[selector] % 60);

    if(hour / 12 == 1) {
        printf("p.m.");
    } else {
        printf("a.m.");
    }

    hour = arrival_time[selector] / 60;
    printf(", arriving at %d:%.2d ", ((hour % 12) == 0) ? (hour % 12 + 12) : hour % 12, arrival_time[selector] % 60);
    if(hour / 12 == 1) {
        printf("p.m.");
    } else {
        printf("a.m.");
    }

    return 0;
}