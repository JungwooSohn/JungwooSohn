#include <stdio.h>

int main(void) {
    const int book[] = {25000, 30000, 18000, 28000, 23000, 26000, 19000};

    int price = 0, num, money = 0;

    while((num = getchar()) != EOF && num != '\n') {
        price += book[num - '0' - 1];
    }

    while (price - 50000 >= 0) {
        price -= 50000;
        money++;
    }

    while (price - 10000 >= 0) {
        price -= 10000;
        money++;
    }

    while (price - 5000 >= 0) {
        price -= 5000;
        money++;
    }

    while (price - 1000 >= 0) {
        price -= 1000;
        money++;
    }

    printf("%d", money);

    return 0;
}