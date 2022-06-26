#include <stdio.h>

int main() {

    char msg[99] = {'\0'};
    char *p = msg;

    printf("Enter a message: ");
    while((*p++ = getchar()) != '\n') {
        if(p == msg + 98) {
            break;
        }
    }

    p--;

    printf("Reversal is: ");
    while(p >= msg) {
        putchar(*--p);
    }


    return 0;
}