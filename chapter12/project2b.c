#include <stdio.h>
#include <ctype.h>


int main() {
    char msg[100];
    char *p = msg, *q = msg;


    printf("Enter a message: ");

    while((*p = getchar()) != '\n') {
        if(isalpha(*p)) {
            *p = toupper(*p);
            p++;
        }
    }
    p--;


    while(p - q >= 0) {
        if(*p != *q) {
            printf("Not a palindrome");
            return 0;
        }
        p--;
        q++;
    }

    printf("Palindrome");
    return 0;
}