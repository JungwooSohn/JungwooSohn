#include <stdio.h>


int evaluate_position(char board[8][8]);

int main() {


    printf("%d", sum_two_dimensional_array());

    return 0;
}




int evaluate_position(char board[8][8]) {

    int white = 0, black = 0;
    int *p;

    for (p = board[0]; p < board[0] + 8*8; p++) {   
        switch(*p) {
            case 'Q':
                white += 9;
                break;
            case 'q':
                black += 9;
                break;
            case 'R':
                white += 5;
                break;
            case 'r':
                black += 5;
                break;
            case 'B':
                white += 3;
                break;
            case 'b':
                black += 3;
                break;
            case 'N':
                white += 3;
                break;
            case 'n':
                black += 3;
                break;
            case 'P':
                white++;
                break;
            case 'p':
                black++;
                break;
            default:
                break;
        }
        
    }

    return white - black;
}