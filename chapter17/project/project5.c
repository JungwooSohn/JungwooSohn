#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_line(char** str, int n, int index);
int compare_str(const void* p, const void* q);


#define MAX_WORD (20)
#define MAX_CHAR (20)

int main(void) {
    int i = 0, k;
    char* word_list[MAX_WORD];

    while (i < MAX_WORD) {

        printf("Enter word: ");
        read_line(word_list, MAX_CHAR, i);

        if (*(word_list[i++]) == '\0') {
            free(word_list[--i]);
            break;
        }
    }

    qsort(word_list, i, sizeof(char *), compare_str);

    

    for(k = 0; k < i; k++) {
        printf("%s ", word_list[k]);
    }
    
    return 0;
}

void read_line(char** str, int n, int index) {
    int i = 0;
    char temp[MAX_CHAR + 1];

    while(i < n && (temp[i] = getchar()) != '\n') {
        i++;
    }

    temp[i] = '\0';

    str[index] = (char*) malloc(sizeof(char) * (MAX_CHAR + 1));
    strcpy(str[index], temp);
}

int compare_str(const void* p, const void* q) {
    return strcmp(*(char**)p, *(char**)q);
}
