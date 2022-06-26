# include <stdio.h>

struct complex {
    double real, imaginary;
};

struct complex c1, c2, c3;

struct complex make_complex(double real, double imaginary) {
    struct complex result;
    result.real = real;
    result.imaginary = imaginary;

    return result;
}

struct complex add_complex(struct complex c1, struct complex c2) {
    struct complex result = {c1.real + c2.real, c1.imaginary + c2.imaginary};
    return result;
}
