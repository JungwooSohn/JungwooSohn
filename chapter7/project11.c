#include <stdio.h>

int main(void) {
    
    char ch1, ch2;

    printf("Enter a first and last name: ");
    ch1 = getchar();

    while (ch1 == ' ') {
        ch1 = getchar();
    }
    
    

    do {
        ch2 = getchar();
    } while (ch2 != ' ');
    while (ch2 == ' ') {
        ch2 = getchar();
    }


    while (ch2 != ' ' && ch2 != '\n') {
        putchar(ch2);
        ch2 = getchar();
    }
    putchar(',');
    putchar(' ');
    putchar(ch1);



    return 0;
}