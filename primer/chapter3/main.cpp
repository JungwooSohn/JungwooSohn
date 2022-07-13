#include <iostream>

using std::cin, std::string;
using std::cout, std::endl;


int main(void) {
    int arr_size;
    cout << "array size: ";
    cin >> arr_size;


    int *arr = new int[arr_size];

    for (int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < arr_size; i++) {
        cout << i << "th element of list : " << arr[i] << endl;
    }

    delete[] arr;

    return 0;
}