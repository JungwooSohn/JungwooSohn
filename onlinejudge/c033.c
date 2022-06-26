#include <stdio.h>

int main() {

    int i; 
    int count = 0;
    unsigned char a;
    scanf("%hhu", &a);

    for(i = 0; i < 7; i++) {
        if(a & 1 << i) {
            count++;
        }
    }

    if(count % 2 != 0) {
        a += 128;
    }

    printf("%hhu", a);

}