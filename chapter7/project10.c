#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    int vowelcount = 0;

    printf("Enter a sentence: ");

    while((ch = getchar()) != '\n') {
        
        switch(toupper(ch)) {
        case 'A': case 'E': case 'I': case 'O': case 'U':
            vowelcount++;
            break;
        default:
            break;
        }
    }

    printf("Your sentence contains %d vowels", vowelcount);

    return 0;
}