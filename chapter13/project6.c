/* Checks planet names */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_PLANETS (9)

int main(int argc, char* argv[])
{
    char* planets[] = {"Mercury", "Venus", "Earth", 
                       "Mars", "Jupiter", "Saturn", 
                       "Uranus", "Neptune", "Pluto"};

    int i;
    int j;

    for (i = 1; i < argc; ++i) {
        for (j = 0; j < NUM_PLANETS; ++j)
            if (strcmp(argv[i], planets[j]) == 0) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        if (j == NUM_PLANETS) {
            printf("%s is not a planet\n", argv[i]);
        }
    }

    return 0;
}


bool stringequal(char* str1, char* str2) {
    int i;
    for(i = 0; toupper(str1[i]) == toupper(str2[i]); ++i) {
        if(str1[i] == '\0' || str2[i] == '\0') {
            return true;
        }
    }

    return false;
}