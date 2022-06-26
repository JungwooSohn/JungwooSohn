#include <stdio.h>
#include <stdbool.h>


int main() {
    int length = 0, temp;
    char sentence1[100], sentence2[100];
    char terminating_char;
    char *p = sentence1;
    bool last = false;


    printf("Enter a sentence: ");
    

    while((*p++ = getchar()) != '\n') {
    }

    p--;
    terminating_char = *--p;
    p--;

    while(p >= sentence1) {
        //find word
        while(*p != ' ') {
            if(p == sentence1 - 1) {
                last = true;
                break;
            }
            p--;
            length++;
        }
        temp = length;
        //print word
        while(length > 0){
            putchar(*++p);
            length--;
        }
        //return to next word
        while(temp-- >= 0) {
            p--;
        }
        if(!(last)) {
            putchar(' ');
        }
    }

    printf("%c\n", terminating_char);


    return 0;
}