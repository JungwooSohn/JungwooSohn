#include <stdio.h>
#include <stdbool.h>

struct color {
    int red;
    int green;
    int blue;
};

int restrict_color(int color) {
    if (color > 255) {
        color = 255;
    } else if (color < 0) {
        color = 0;
    }
    return color;
}

int upper_color(int color) {
    if (color > 0 && color < 3) {
        return 3;
    }
    return color;
}


struct color make_color(int red, int green, int blue) {
    struct color result;
    result.red = restrict_color(red);
    result.green = restrict_color(green);
    result.blue = restrict_color(blue);

    return result;
}

int getRed(struct color c) {
    return c.red;
}

bool equal_color(struct color c1, struct color c2) {
    if(c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue) {
        return true;
    } 
    return false;
}

struct color brigter(struct color c) {
    if(c.blue == 0 && c.green == 0 && c.red == 0) {
        c.blue =  c.green = c.red = 3;
        return c;
    }

    c.blue = upper_color(c.blue);
    c.green = upper_color(c.green);
    c.red = upper_color(c.red);


    
    
    c.blue /= 0.7;
    c.green /= 0.7;
    c.red /= 0.7;

    c.red = restrict_color(c.red);
    c.green = restrict_color(c.green);
    c.blue = restrict_color(c.blue);


    return c;
}


struct color darker(struct color c) {
    c.blue *= 0.7;
    c.green *= 0.7;
    c.red *= 0.7;
    return c;
}