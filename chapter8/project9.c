#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {

    char map[10][10];
    srand((unsigned) time(NULL));
    int direction;
    int row = 0, col = 0;

    for(int i = 0; i < 10; ++i) {
        for(int k = 0; k < 10; ++k) {
            map[i][k] = '.';
        }
    }

    for(int i = 0; i < 26; i++) {
        map[row][col] = 'A' + i;
        direction = rand() % 4;
        switch (direction)
        {
        case 0:
            col++;
            break;
        case 1:
            row--;
            break;
        case 2:
            col--;
            break;
        case 3:
            row++;
            break;
        default:
            break;
        }

        if (map[row][col] != '.') {
            i--;
            switch (direction)
            {
            case 0:
                col--;
                break;
            case 1:
                row++;
                break;
            case 2:
                col++;
                break;
            case 3:
                row--;
                break;
            default:
                break;
            }
            if (map[row + 1][col] != '.' && map[row][col + 1] != '.' && map[row - 1][col] != '.' && map[row][col - 1] != '.') {
            i = 26;
            }
            continue;
        }

        if (row < 0) {
            row++;
            i--;
            continue;
        }
        if (col < 0) {
            col++;
            i--;
            continue;
        }        


    }

    for(int i = 0; i <10; ++i) {
        for(int k = 0; k < 10; ++k) {
            putchar(map[i][k]);
        }
        putchar('\n');
    }




    return 0;
}