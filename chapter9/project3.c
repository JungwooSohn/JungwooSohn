#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main() {

    char map[10][10];

    generate_random_walk(map);
    print_array(map);

    return 0;
}

void generate_random_walk(char walk[10][10]) {
    int row = 0, col = 0, i, k, direction;

    srand((unsigned) time(NULL));

    for (i = 0; i < 10; ++i) {
        for (k = 0; k < 10; ++k) {
            walk[i][k] = '.';
        }
    }

    for(int i = 0; i < 26; i++) {
        walk[row][col] = 'A' + i;
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

        if (walk[row][col] != '.') {
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
            if (walk[row + 1][col] != '.' && walk[row][col + 1] != '.' && walk[row - 1][col] != '.' && walk[row][col - 1] != '.') {
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

}



void print_array(char walk[10][10]) {
    for(int i = 0; i <10; ++i) {
        for(int k = 0; k < 10; ++k) {
            putchar(walk[i][k]);
        }
        putchar('\n');
    }
}
