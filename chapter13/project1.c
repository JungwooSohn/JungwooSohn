#include <string.h>
#include <stdio.h>

#define MAX_LETTER (20)


int main() {

    char smallest_word[MAX_LETTER + 1] = {'f',};
    char largest_word[MAX_LETTER + 1] = {'\0',};
    char temp_word[MAX_LETTER + 1];




    
    do {
        printf("Enter word: ");
        scanf("%s", temp_word);
        if(strcmp(temp_word, smallest_word) < 0) {
            strncpy(smallest_word, temp_word, sizeof(smallest_word) - 1);
        } else if (strcmp(temp_word, largest_word) > 0) {
            strncpy(largest_word, temp_word, sizeof(largest_word) - 1);
        }
    } while (strlen(temp_word) != 4);

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);


    return 0;
}