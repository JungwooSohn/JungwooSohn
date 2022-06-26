#include <iostream>


int main() {

    int num1, num2;

    std::cin >> num1 >> num2;

    if (num1 > num2) {
        while (num2 < num1) {
            std::cout << num2++ << " ";
        }
        std::cout << num2 << std::endl;
    }

    if (num1 < num2) {
        while (num2 > num1) {
            std::cout << num1++ << " ";
        }
        std::cout << num1 << std::endl;
    }

    return 0;
}