#include <stdio.h>


int main() {
    char c, terminating_char;
    char sentence[30][20] = {'\0',};
    int i;
    int k;


    printf("Enter a sentence: ");
    for(i = 0; i < 30; i++) {
        for(k = 0; k < 20; ++k) {
            c = getchar();
            if(c == '\n') {
                goto read_end;
            } else if(c == ' ') {
                break;
            } else {
                sentence[i][k] = c;
            }
        }
    }

    read_end:
        terminating_char = sentence[i][--k];
        sentence[i][k] = '\0';
        for(;i >= 0; --i) {
            k = 0;
            while(sentence[i][k] != '\0') {
                putchar(sentence[i][k++]);
            }
            if(i != 0) {
                putchar(' ');
            }
        }
        putchar(terminating_char);


    return 0;
}