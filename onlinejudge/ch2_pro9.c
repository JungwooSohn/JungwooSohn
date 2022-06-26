#include <stdio.h>

int main(void) {
    int c;
    c = getchar();

    putchar(c - 'a' + 'A');
    return 0;
}