#include <stdio.h>

int main() {

    char msg[80];
    int shift;
    int i = 0;
    printf("Enter message to be encrypted: ");
    while((msg[i++] = getchar()) != '\n');


    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    printf("Encrypted message: ");

    for (int k = 0; k < i - 1; ++k) {
        if(msg[k] >= 'A' && msg[k] <= 'Z') {
            putchar(((msg[k] - 'A') + shift) % 26 + 'A') ;
        } else if(msg[k] >= 'a' && msg[k] <= 'z') {
            putchar(((msg[k] - 'a') + shift) % 26 + 'a') ;
        } else {
            putchar(msg[k]);
        }
    }

    return 0;
}