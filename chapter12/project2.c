#include <stdio.h>
#include <ctype.h>


int main() {
    char msg[100];
    int i = 0, middle, top;

    printf("Enter a message: ");

    while((msg[i] = getchar()) != '\n') {
        if(isalpha(msg[i])) {
            msg[i] = toupper(msg[i]);
            i++;
        }
    }

    i--;
    top = i;
    middle = i / 2;
    while(i >= middle) {
        if(msg[i] != msg[top - i]) {
            printf("Not a palindrome");
            return 0;
        }
        i--;
    }

    printf("Palindrome");
    return 0;
}