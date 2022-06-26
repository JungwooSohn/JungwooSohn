#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main() {
    
    int n = 1;

    printf("This program creates a magic square of a specified size.\nThe size must be an odd number between 1 and 99.\nEnter size of magic square: ");

    scanf("%d", &n);

    int square[n][n];

    create_magic_square(n, square);
    print_magic_square(n, square);

    return 0;
}

void create_magic_square(int n, int magic_square[n][n]) {
    int row = 0;
    int col = n / 2;


    for(int i = 0; i < n; ++i) {
        for(int k = 0; k < n; ++k) {
            magic_square[i][k] = 0;
        }
    }


    for(int i = 1; i <= n * n; i++) {
        if (magic_square[row][col] == 0) {
            magic_square[row][col] = i;
        } else {
            row += 2;
            row = (row + n) % n;
            col--;
            col = (col + n) % n;
            magic_square[row][col] = i;
        }
        row--;
        row = (row + n) % n;
        col++;
        col = (col + n) % n;
    }
}

void print_magic_square(int n, int magic_square[n][n]) {
    for(int i = 0; i < n; ++i) {
        for(int k = 0; k < n; ++k) {
            printf("%4d", magic_square[i][k]);
        }
        printf("\n");
    }
}



