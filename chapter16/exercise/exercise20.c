#include <stdio.h>

enum {NORTH, SOUTH, WEST, EAST} direction;

int main() {

    int x = 0, y = 0;

    switch (direction) {
    case NORTH: 
        y++;
        break;
    case SOUTH:
        y--;
        break;
    case WEST:
        x--;
        break;
    case EAST:
        x++;
        break;
    default:
        break;
    }
    return 0;
}
