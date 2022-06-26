#include <stdio.h>

int main(void) {

    char ch;
    double num_length = 0, num_count = 1;
    double average_length;
    printf("Enter a sentence: ");
    while((ch = getchar()) != '\n') {
        if (ch != ' ') {
            ++num_length;
        } else {
            ++num_count;
        }
    }

    average_length = num_length / num_count;

    printf("Average word length: %.1lf", average_length);

    return 0;
}