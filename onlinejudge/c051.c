#include <stdio.h>
#include <string.h>

void push(int **sp);
int pop(int **sp, int *bp);
int size(int *sp, int *bp);
int empty(int *sp, int *bp);
int top(int *sp, int *bp);

int main(void) {

    int stack[100] = {0,};
    int *sp = stack;
    const char *instructionlist[5] = {"push", "pop", "size", "empty", "top"};
    char instruction[10];
    int n, i, j, value = -2, first = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", instruction);

        for (j = 0; j < 5; j++) {
            if (strcmp(instruction, instructionlist[j]) == 0) {
                break;
            }
        }

        switch (j)
        {
        case 0:
            push(&sp);
            break;
        case 1: 
            value = pop(&sp, stack);
            break;
        case 2:
            value = size(sp, stack);
            break;
        case 3:
            value = empty(sp, stack);
            break;
        case 4:
            value = top(sp, stack);
            break;
        default:
            break;
        }

        if (value != -2) {
            if (first != 0) {
                putchar('\n');
            }
            printf("%d", value);
            first++;
        }

        value = -2;
    }
    


    return 0;
}

void push(int **sp) {
    int x;
    scanf("%d", &x);
    *((*sp)++) = x;
}

int pop(int **sp, int *bp) {
    if (*sp != bp) {
        return *(--(*sp));
    } else {
        return -1;
    }
}

int size(int *sp, int *bp) {
    return sp - bp;
}

int empty(int *sp, int *bp) {
    if (sp == bp) {
        return 1;
    }
    return 0;
}

int top(int *sp, int *bp) {
    if (sp != bp) {
        return *(sp - 1);
    }
    return -1;
}