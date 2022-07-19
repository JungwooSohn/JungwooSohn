#include <iostream>
#include <memory.h>
#include <cmath>

using namespace std;



void maketree(int arr[], int k, int cur_index);

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int k;
    cin >> k;

    int tree[(int) pow(2, k)];
    memset(tree, 0, sizeof(tree));
    maketree(tree, k, 1);

    for (int i = 0; i < k; i++) {
        for (int k = pow(2, i); k <= pow(2, i + 1) - 1; k++) {
            if (k != pow(2, i)) {
                cout << ' ';
            }
            cout << tree[k];
        }
        cout << endl;
    }

    return 0;
}

void maketree(int arr[], int k, int cur_index) {
    static int temp;
    if (cur_index * 2 <= pow(2, k) - 1) {
        maketree(arr, k, cur_index * 2);
    }
    cin >> temp;
    arr[cur_index] = temp;
    if (cur_index * 2 + 1 <= pow(2, k) - 1) {
        maketree(arr, k, cur_index * 2 + 1);
    }


}

