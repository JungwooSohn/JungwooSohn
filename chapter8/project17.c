#include <stdio.h>

int main() {
    
    int n, row, col;

    printf("This program creates a magic squatr of a specified size.\nThe size must be an odd number between 1 and 99.\nEnter size of magic square: ");

    scanf("%d", &n);

    int square[99][99] = {0,};
    row = 0;
    col = n / 2;

    for(int i = 1; i <= n * n; i++) {
        if (square[row][col] == 0) {
            square[row][col] = i;
        } else {
            row += 2;
            row = (row + n) % n;
            col--;
            col = (col + n) % n;
            square[row][col] = i;
        }
        row--;
        row = (row + n) % n;
        col++;
        col = (col + n) % n;
    }

    for(int i = 0; i < n; ++i) {
        for(int k = 0; k < n; ++k) {
            printf("%4d", square[i][k]);
        }
        printf("\n");
    }

    return 0;
}