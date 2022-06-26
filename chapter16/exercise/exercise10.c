#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct point {
    int x, y;
};

struct rectangle {
    struct point upper_left, lower_right;
};

int compute_area(struct rectangle r) {
    return abs(r.upper_left.x - r.lower_right.x) * abs(r.upper_left.y - r.lower_right.y);
}

struct point compute_center(struct rectangle r) {
    struct point result;
    result.x = (r.upper_left.x + r.lower_right.x) / 2;
    result.y = (r.upper_left.y + r.lower_right.y) / 2;
    return result;
}

struct rectangle move_rectangle(struct rectangle r, int x, int y) {
    r.upper_left.x += x;
    r.lower_right.x += x;
    r.upper_left.y += y;
    r.lower_right.y += y;

    return r;
}

bool on_rectangle(struct rectangle r, struct point p) {
    if(p.x <= r.lower_right.x && p.x >= r.upper_left.x && p.y >= r.lower_right.y && p.x <= r.upper_left.y) {
        return true;
    }
    return false;
}