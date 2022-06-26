#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>



int roll_dice(void);
bool play_game(void);

int main() {
    int win = 0, lose = 0;
    char ch = '0';
    srand((unsigned) time(NULL));

    for(;;) {
        if(play_game()) {
            printf("You win!\n");
            win++;
        } else {
            printf("You lose!\n");
            lose++;
        }
        printf("\nPlay again? ");
        if((ch = getchar()) == '\n') {
            ch = getchar();
        }

        if(toupper(ch) != 'Y') {
            printf("Wins: %d  Losses: %d", win, lose);
            break;
        }
    }

    return 0;
}

int roll_dice(void) {
    return rand() % 6 + 1 + rand() % 6 + 1;
}

bool play_game(void) {
    //first
    int first_sum = roll_dice();

    printf("You rolled: %d\n", first_sum);
    switch (first_sum) {
        case 7: case 11:
            return true;
        
        case 2: case 3: case 12:
            return false;
        default:
            printf("Your point is %d\n", first_sum);
            break;
    }

    for(;;) {
        int second_sum = roll_dice();
        printf("You rolled: %d\n", second_sum);
        if (second_sum == 7) {
            return false;
        }
        if (first_sum == second_sum) {
            return true;
        } 
    }
    
    






}
