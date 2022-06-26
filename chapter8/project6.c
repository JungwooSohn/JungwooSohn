#include <stdio.h>

int main(void) {

    char msg[100];
    char ch;
    int i = 0;

    printf("Enter message: ");

    while((ch = getchar()) != '\n') {
        msg[i++] = ch;
    }

    for(int k = 0; k < i; ++k) {
        if (msg[k] >= 'a' && msg[k] <= 'z') {
            msg[k] -= 32;
        }
        switch (msg[k]) {
            case 'A':
                msg[k] = '4';
                break;
            case 'B':
                msg[k] = '8';
                break;
            case 'E':
                msg[k] = '3';
                break;
            case 'I':
                msg[k] = '1';
                break;
            case 'O':
                msg[k] = '0';
                break;
            case 'S':
                msg[k] = '5';
                break;
            default:
                break;
        }
        putchar(msg[k]);
    }
    printf("!!!!!!!!!!");

    return 0;
}