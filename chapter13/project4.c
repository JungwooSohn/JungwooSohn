#include <stdio.h>

int main(int argc, char* argv[]) {
    int i;

    for(i = 0; i < argc - 1; ++i) {
        printf("%s ", argv[argc - i - 1]);
    }

}