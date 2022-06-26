#include <stdio.h>

#define MAX_DIGITS (10)

const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                             {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};

char digits[4][MAX_DIGITS * 4];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);


int main() {

    char ch;
    int counts = 0;
    clear_digits_array();


    printf("Enter a number: ");
    while ((ch = getchar()) != '\n') {
        if(ch >= '0' && ch <= '9' && counts < 10) {
            process_digit(ch - '0', counts++ * 4);
        }
    }

    print_digits_array();
    return 0;
}


void clear_digits_array(void) {
    int i, k;
    for(i = 0; i < 4; ++i) {
        for(k = 0; k < MAX_DIGITS * 4; ++k) {
            digits[i][k] = ' ';
        }
    }
}


void process_digit(int digit, int position) { 
    if (segments[digit][0]) {
        digits[0][position + 1] = '_';
    }
    if (segments[digit][1]) {
        digits[1][position + 2] = '|';    
    }
    if (segments[digit][2]) {
        digits[2][position + 2] = '|';
    }
    if (segments[digit][3]) {
        digits[2][position + 1] = '_';
    }
    if (segments[digit][4]) {
        digits[2][position] = '|';
    }
    if (segments[digit][5]) {
        digits[1][position] = '|';
    }
    if (segments[digit][6]) {
        digits[1][position + 1] = '_';
    }
}

void print_digits_array(void) {
    int i, k;

    for(i = 0; i < 4; ++i) {
        for(k = 0; k < MAX_DIGITS * 4; ++k) {
            putchar(digits[i][k]);
        }
        putchar('\n');
    }
}