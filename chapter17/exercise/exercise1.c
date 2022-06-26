#include <stdio.h>
#include <stdlib.h>



void* my_malloc(size_t n) {
    void* p;
    p = malloc(n);
    if(p == NULL) {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    return p;
}

char* duplicate(char* str) {
    char* p;
    if((p = malloc(sizeof(strlen(str) + 1))) == NULL) {
        return p;
    }
    strcpy(p, str);
    return p;
}