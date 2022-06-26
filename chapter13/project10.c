#include <stdio.h>

void read_line(char* str, int size);
double compute_average_word_length(const char* sentence);

int main(void) {

    char sentence[100];

    printf("Enter a sentence: ");

    read_line(sentence, 100 - 1);

    printf("Average word length: %.1f\n", compute_average_word_length(sentence));
    return 0;
}

void read_line(char* str, int size) {
    int i = 0;
    while((*str = getchar()) != '\n' && i++ < size) {
        str++;
    }
    *str = '\0';
}

double compute_average_word_length(const char* sentence) {
    int sum = 0;
    int word_count = 1;

    while(*sentence) {
        if(*sentence++ ==' ') {
            word_count++;
        } else {
            sum++;
        }
    }

    return (double) sum / word_count;
}