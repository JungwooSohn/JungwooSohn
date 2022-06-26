#include <stdio.h>

int main() {

    unsigned int i = 2, j = 1, k = 0;

    printf("%d", ~i & j ^ k);
}