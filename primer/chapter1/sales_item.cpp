#include <iostream>
#include "Sales_item.h"

int main(void) {
    Sales_item item1, item2;
    int count = 1;
    std::cin >> item2;
    while (std::cin >> item1) {
        if (item1.isbn() == item2.isbn()) {
            count++;
        } else {
            std::cout << "Number of " << item2.isbn() << " is " << count << std::endl;
            count = 1;
            item2 = item1;
        }
    }
    
    std::cout << "Number of " << item2.isbn() << " is " << count << std::endl;

    return 0;
}