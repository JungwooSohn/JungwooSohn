#include <stdio.h>
#include <string.h>


int* push(int x, int* stack);
int* pop(int* stack, int* start);
void size(int* stack, int* start);
void empty(int* stack, int* start);
void top(int* stack, int* start);

int main() {

    int stack[100] = {0,};
    int n;
    int x;
    int* index = stack;
    int* start = stack;
    char mission[10];

    scanf("%d", &n);

    for(;n > 0; --n) {
        scanf("%s", mission);
        if(strcmp(mission, "push") == 0) {
            scanf("%d", &x);
            index = push(x, index);
        } else if(strcmp(mission, "pop") == 0) {
            index = pop(index, start);
        } else if(strcmp(mission, "size") == 0) {
            size(index, start);
        } else if(strcmp(mission, "empty") == 0) {
            empty(index, start);
        } else if(strcmp(mission, "top") == 0) {
            top(index, start);
        } 
    }

    return 0;
}

int* push(int x, int* stack) {
    *stack++ = x;
    return stack;
}

int* pop(int* stack, int* start) {
    if(stack != start) {
        printf("%d\n", *--stack);
    } else {
        printf("%d\n", -1);
    }
    return stack;
}

void size(int* stack, int* start) {
    int i = 0;
    while((stack - i) != start) {
        ++i;
    }
    printf("%d\n", i);
}

void empty(int* stack, int* start) {
    if(stack == start) {
        printf("%d\n", 1);
    } else {
        printf("%d\n", 0);
    }
}

void top(int* stack, int* start) {
    if(stack != start) {
        printf("%d\n", *(stack - 1));
    } else {
        printf("%d\n", -1);
    }
}


