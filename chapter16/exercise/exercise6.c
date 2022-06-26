#include <stdio.h>

struct time {
    int hours, minutes, seconds;
};

struct time split_time(long total_seconds) {
    struct time result;

    result.hours = total_seconds / (3600);
    total_seconds %= 3600;
    result.minutes = total_seconds / 60;
    total_seconds %= 60;
    result.seconds = total_seconds;

    return result;
}