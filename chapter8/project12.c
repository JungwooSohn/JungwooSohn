#include <ctype.h>
#include <stdio.h>

int main() {

    int scramble[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int sum = 0;
    char ch;

    printf("Entre a word: ");
    while((ch = getchar()) != '\n') {
        sum += scramble[toupper(ch) - 'A'];
    }

    printf("Scrabble value : %d", sum);


    return 0;
}