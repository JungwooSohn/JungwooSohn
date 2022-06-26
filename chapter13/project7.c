#include <stdio.h>

int main() {

    int num1, num2;

    char* second[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char* first[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    char* ten[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &num1, &num2);

    printf("You entered the number ");

    if(num1 == 1) {
        printf("%s", ten[num2]);
    } else {
        printf("%s", second[num1 - 2]);
        if(num2 != 0) {
            printf("-%s", first[num2 - 1]);
        }
    }


    printf(".\n");


    return 0;
}