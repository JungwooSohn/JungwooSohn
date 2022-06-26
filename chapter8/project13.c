#include <stdio.h>

void main() {

    char last_name[20];
    char name, first_name;
    int i = 0;
    printf("Enter a first and last name: ");

    scanf(" %c", &first_name);
    while((name = getchar()) != ' ');

    while (last_name[i - 1] != '\n') {
        scanf("%c", &last_name[i++]);
    }
    
    for(int k = 0; k < i - 1; ++k) {
        printf("%c", last_name[k]);
    }

    printf(", %c", first_name);


}