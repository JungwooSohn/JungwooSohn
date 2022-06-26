#include <stdio.h>
#include <stdlib.h>

int sum(int (*f)(int), int start, int end);
int square(int x);

int main(void) {

    printf("%d", sum(square, 0, 3));
    
    return 0;
}

int sum(int (*f)(int), int start, int end) {
    int sum = 0;

    while (start <= end) {
        sum += (*f)(start++);
    }

    return sum;
}


int square(int x) {
    return x * x;
}