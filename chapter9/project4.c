#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>


void read_word(int counts[]);
bool equal_array(int counts1[], int counts2[]);

int main() {
    int counts1[26] = {0, };
    int counts2[26] = {0, };


    printf("Enter first word: ");

    read_word(counts1);

    printf("Enter second word: ");

    read_word(counts2);

    if (equal_array(counts1, counts2)) {
        printf("The words are anagrams.");
    } else {
        printf("The words are not anagrams.");
    }

    return 0;
}

void read_word(int counts[]) {
    char ch;
    while ((ch = getchar()) != '\n'){
        if (isalpha(ch)) {
            counts[tolower(ch) - 'a']++;
        }
    }
}

bool equal_array(int counts1[], int counts2[]) {
    int i;
    for(i = 0; i < 26; ++i) {
        if (counts1[i] != counts2[i]) {
            break;
        }
    }

    if (i != 26) {
        return false;
    } else {
        return true;
    }
}