#include <stdio.h>
#include <string.h>

int main() {
    char str[20];
    strcpy(str, "tire-bouchonered");
    strcpy(&str[4], "d-or-wi");
    strcat(str, "red?");
    

    return 0;
}

char *strcat (char* destination, const char* source) {
    char *ptr = destination;

    while(*ptr) {
        ++ptr;
    }

    while(*ptr++ = *source++) {
    }

    return destination;
}