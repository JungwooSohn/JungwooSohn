#include <stdio.h>

int compute_poly(int x);

int main() {

    int x;

    printf("Enter the value of x: ");
    scanf("%d", &x);

    printf("Answer: %d", compute_poly(x));

    return 0;
}


int compute_poly(int x) {
    return ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
}
/*
((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;*/