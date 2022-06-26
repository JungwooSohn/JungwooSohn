#include <stdio.h>

#define N = 10 //error
#define INC(x) x+1
#define SUB (x,y) x-y // error
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))
#define M1(x,y) x##y
#define M2(x,y) #x #y //error

int main(void) {
    int a[N], i, j, k, m; //error

#ifdef N
    i = j; //error i, j not defined
#else
    j = i;
#endif

    i = 10 * INC(j);
    i = SUB(j,k); // not defined
    i = SQR(SQR(j));
    i = CUBE(j);
    i = M1(j, k);
    puts(M2(i, j));

#undef SQR
    i = SQR(j);
#define SQR
    i = SQR(j);


}