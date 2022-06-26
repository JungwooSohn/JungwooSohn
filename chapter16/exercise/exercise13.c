#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct point {
    int x, y;
};

struct shape {
    enum {RECTANGLE, CIRCLE} shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

int main() {


    return 0;
}

double compute_area(struct shape s) {
    double area;
    if(s.shape_kind == RECTANGLE) {
        area = s.u.rectangle.height * s.u.rectangle.width;
    } else {
        area = s.u.circle.radius * s.u.circle.radius * 3.14;
    }
    return area;
}

struct shape move_shape(struct shape s, int x, int y) {
    s.center.x += x;
    s.center.y += y;
    return s;
}

struct shape scale_shape(struct shape s, double c) {
    if(s.shape_kind == RECTANGLE) {
        s.u.rectangle.height *= c;
        s.u.rectangle.width *= c;
    } else {
        s.u.circle.radius *= c;
    }
}