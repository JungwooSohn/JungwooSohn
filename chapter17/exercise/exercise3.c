#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value);

int main() {
    int i;
    int *p = create_array(4, 4);

    for(i = 0; i < 4; i++) {
        printf("%d", *(p + i));
    }


    return 0;
}

 
int *create_array(int n, int initial_value) {
    int* p = malloc(n * sizeof(int));
    int* i;

    if(p == NULL) {
        return NULL;
    }


    for(i = p; i < p + n; i++) {
        *i = initial_value;
    }

    return p;
}