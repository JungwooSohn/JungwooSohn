#include <stdio.h>

#define N (10)


int main() {

    double ident[N][N];
    double *p = ident[0];

    for(;p < ident[0] + N * N; p++) {
        if((p - ident[0]) % (N + 1) == 0) {
            *p = 1;
        } else {
            *p = 0;
        }
    }


    return 0;
}
