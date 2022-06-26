#include <stdio.h>

#define ERROR(str, index) fprintf(stderr, (str), index)

int main() {

    ERROR("Range error: index = %d\n", 10);

    return 0;
}