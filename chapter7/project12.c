#include <stdio.h>

int main(void) {
    
    char ch;
    float num1 = 0.0f, num2 = 0.0f;

    printf("Enter an expressions: ");
    
    scanf("%f", &num1);
    while((ch = getchar()) != '\n') {
        switch(ch) {
            case '+':
                scanf("%f", &num2);
                num1 = num1 + num2;
                break;
            case '-':
                scanf("%f", &num2);
                num1 = num1 - num2;
                break;
            case '*':
                scanf("%f", &num2);
                num1 = num1 * num2;
                break;
            case '/':
                scanf("%f", &num2);
                num1 = num1 / num2;
                break;
            default:   
                break;
         }
    }
    printf("%f", num1);
    return 0;
}