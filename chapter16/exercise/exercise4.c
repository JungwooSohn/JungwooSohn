#include <stdio.h>

typedef struct {
    double real, imaginary;
} Complex;

Complex c1, c2, c3;

Complex make_complex(double real, double imaginary) {
    Complex result = {real, imaginary};
    return result;
}

Complex add_complex(Complex c1, Complex c2) {
    Complex result = {c1.real + c2.real, c1.imaginary + c2.imaginary};
    return result;
}