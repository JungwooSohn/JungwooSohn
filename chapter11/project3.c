#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denomiator);


int main() {

    int nom, denom, reduced_nom, reduced_denom;

    printf("Enter a fraction: ");
    scanf("%d /%d", &nom, &denom);

    reduce(nom, denom, &reduced_nom, &reduced_denom);

    printf("In lowest terms: %d/%d", reduced_nom, reduced_denom);


    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denomiator) {
    int temp1 = numerator;
    int temp2 = denominator;
    int temp3;
    while (temp2 > 0) {
        temp3 = temp1 % temp2;
        temp1 = temp2;
        temp2 = temp3;
    }

    *reduced_numerator = numerator / temp1;
    *reduced_denomiator = denominator / temp1;

}