#include <stdio.h>

int main(void) {

    int row, col;
    int matrix[5][5] = {0, };
    int student_total_score;
    int quiz_total_score;
    int high_score;
    int low_score;

    for (row = 0; row < 5; row++) {
        printf("Enter the grade of %d student: ", row + 1);
        for(col = 0; col < 5; col++) {
            scanf("%d", &matrix[row][col]);
        }
    }
    
    

// compute the total grade for each student
    for(row = 0; row < 5; row++) {
        for(col = 0; col < 5; col++){
            student_total_score += matrix[row][col];
        }
    }
    
    printf("Students Total Average\n");

    for(int row = 0; row < 5; row++) {
        printf("%4d", row + 1);
        student_total_score = 0;
        for (col = 0; col < 5; col++) {
            student_total_score += matrix[row][col];
        }
        printf("%8d%7d\n", student_total_score, student_total_score / 5);
    }

    printf("Quizs Average High Low\n");

//compute the total grade of each quiz
    for(col = 0; col < 5; col++) {
        quiz_total_score = 0;
        high_score = matrix[0][col];
        low_score = matrix[0][col];

        printf("%3d", col + 1);
        for(row = 0; row < 5; row++){
            quiz_total_score += matrix[row][col];
            high_score = matrix[row][col] >= high_score ? matrix[row][col] : high_score;
            low_score = matrix[row][col] <= low_score ? matrix[row][col] : low_score;
        }
        printf("%7d%6d%5d\n", quiz_total_score / 5, high_score, low_score);
    }






    return 0;
}