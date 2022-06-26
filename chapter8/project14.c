#include <stdio.h>

int main() {
    int length = 0, word = 0, temp2 = 0, i = 0;
    char sentence1[100], sentence2[100];
    char terminating_char;

    printf("Enter a sentence: ");
    

    while((sentence1[length++] = getchar()) != '\n') {
    }
    length--;
    terminating_char = sentence1[--length];

    //go backthrough
    while(length >= 0) {
        sentence2[word] = ' ';
        i++;
        word++;
        while (sentence1[--length] != ' ' && length >= 0) {
            word++;
        }
        temp2 = length;
        for(; i < word; i++) {
            sentence2[i] = sentence1[++temp2];
        }

    }

    for(int k = 0; k < word; k++) {
        printf("%c", sentence2[k]);
    }

    printf("%c", terminating_char);


    return 0;






}