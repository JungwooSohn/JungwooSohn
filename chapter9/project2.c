#include <stdio.h>

double compute_tax(double income);

int main() {
    double income;
    printf("Enter income: ");
    scanf("%lf", &income);
    printf("%f", compute_tax(income));

    return 0;
}

double compute_tax(double income) {
    double tax = 0;
    if(income <= 750) {
        tax = income / 100;
    } else if (income <= 2250) {
        tax = 7.50f + (income - 750) * 2 / 100;
    } else if (income <= 3750) {
        tax = 37.50f + (income - 2250) * 3 / 100;
    } else if (income <= 5250) {
        tax = 82.50f + (income - 3750) * 4 / 100;
    } else if (income <= 7000) {
        tax = 142.50f + (income - 5250) * 5 / 100;
    } else {
        tax = 230.00f + (income - 7000) * 6 / 100;
    }
    return tax;
}