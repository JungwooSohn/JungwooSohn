#include <stdio.h>
#include <ctype.h>

int main() {
    int length = 0, i;
    char alphabet[26] ={0,};
    char ch;


    printf("Enter first word: ");

    while ((ch = getchar()) != '\n'){
        if (isalpha(ch)) {
            alphabet[tolower(ch) - 'a']++;
        }
    }

    printf("Enter second word: ");
    while ((ch = getchar()) != '\n'){
        if (isalpha(ch)) {
            alphabet[tolower(ch) - 'a']--;
        }
    }

    for(i = 0; i < 26; ++i) {
        if (alphabet[i] != 0) {
            break;
        }
    }

    if (i != 26) {
        printf("The words are not anagrams.");
    } else {
        printf("The words are anagrams.");
    }

    return 0;
}