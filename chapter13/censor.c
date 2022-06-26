#include <stdio.h>
#include <string.h>

int main() {


    return 0;
}

void censor(char str[]) {
    char* p = str;
    while(p + 2 != '\0') {
        if(*p == 'f' && *(p + 1) == 'o' && *(p + 2) == 'o') {
            *(p - 1) = *(p -2) = *(p - 3) = 'x';
        }
        p++;
    }
}