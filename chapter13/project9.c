#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute_vowel_count(const char *sentence);

int main() {

    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    printf("\nYour sentence contains %d vowels", compute_vowel_count(sentence));

    return 0;
}

int compute_vowel_count(const char *sentence) {
    int count = 0;

    while(*sentence) {
        switch (toupper(*sentence++))
        {
        case 'A': case 'E': case 'I': case 'O': case 'U':
            count++;
            /* code */
            break;
        default:
            break;
        }
    }

    return count;
}