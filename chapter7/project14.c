#include <stdio.h>
#include <math.h>

int main(void) {
    
    int x;
    double y = 1.0, x_divide_y;

    printf("Enter a postive number: ");
    scanf("%d", &x);
    while (fabs(y - (y + x / y) / 2) >= .00001 * y) {
        y = (y + x / y) / 2;
    }
    


    printf("Square root: %f\n", fabs(y));
    return 0;
}