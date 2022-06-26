#include <stdio.h>
#include <assert.h>

void decompose(double x, long* out_int_part, double* out_frac_part);

int main() {
    long x;
    double y;
    double num;
    printf("Enter the number: ");
    scanf("%lf", &num);

    decompose(num, &x, &y);
    printf("Int part: %ld, frac par: %f", x, y);


    return 0;
}

void decompose(double x, long* out_int_part, double* out_frac_part) {

    assert(out_frac_part != NULL);
    assert(out_frac_part != NULL);

    *out_int_part = (long) x;
    *out_frac_part = x - *out_int_part;
}