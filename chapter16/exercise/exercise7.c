#include <stdio.h>

struct fraction {
    int numerator, denominator;
};

struct fraction reduce_fract(struct fraction f) {
    int a = f.numerator, b = f.denominator, c;

    while (b > 0) {
        c = a % b;
        a = b;
        b = c;
    }

    f.numerator /= a;
    f.denominator /= a;

    return f;
}


struct fraction add_fract(struct fraction f1, struct fraction f2) {
    struct fraction result;

    if (f1.denominator == f2.denominator) {
        result.numerator = f1.numerator + f2.numerator;
        result.denominator = f1.denominator;
        return result;
    } else {
        result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
        result.denominator = f1.denominator * f2.denominator;
        return reduce_fract(result);
    }
}

struct fraction sub_fract(struct fraction f1, struct fraction f2) {
    struct fraction result;

    if (f1.denominator == f2.denominator) {
        result.numerator = f1.numerator - f2.numerator;
        result.denominator = f1.denominator;
        return result;
    } else {
        result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
        result.denominator = f1.denominator * f2.denominator;
        return reduce_fract(result);
    }
}



struct fraction mul_fract(struct fraction f1, struct fraction f2) {
    struct fraction result;

    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;

    return reduce_fract(result);
}

struct fraction div_fract(struct fraction f1, struct fraction f2) {
    struct fraction result;

    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;

    return reduce_fract(result);
}



