#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum move {
    firsttoSecond = 0,
    firsttoThird,
    secondtoThird,
    secondtoFirst,
} Move;

typedef struct stack {
    int size;
    int index;
    int* arr;
} Stack;

int cmpfunc(const void* p, const void* q);
Stack* createStack(int size);
void push(Stack* pstack, int value);
int pop(Stack* pstack);
int top(Stack* pstack);
bool isempty(Stack *stack);

int main(void) {

    int n = 0, buffer = 0, moveindex = 0;

    Move queue[12345] = {0,};

    scanf("%d", &n);

    Stack* stack1 = createStack(n);
    Stack* stack2 = createStack(n);
    Stack* sortedstack = createStack(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &buffer);
        push(stack1, buffer);
        push(sortedstack, buffer);
    }

    qsort(sortedstack->arr, n, sizeof(int), cmpfunc);
    while (true) {
        while(!isempty(stack1)) {
            buffer = pop(stack1);
            if (buffer == top(sortedstack)) {
                queue[moveindex++] = firsttoThird;
                if (moveindex >= 20000) {
                    exit(EXIT_FAILURE);
                }
                pop(sortedstack);
                // push(stack3, buffer);
            } else {
                queue[moveindex++] = firsttoSecond;
                if (moveindex >= 20000) {
                    exit(EXIT_FAILURE);
                }
                push(stack2, buffer);
            }
        }

        if (isempty(stack1) && isempty(stack2)) {
            break;
        }

        while(!isempty(stack2)) {
            buffer = pop(stack2);
            if (buffer == top(sortedstack)) {
                queue[moveindex++] = secondtoThird;
                if (moveindex >= 20000) {
                    exit(EXIT_FAILURE);
                }
                pop(sortedstack);
            } else {
                queue[moveindex++] = secondtoFirst;
                if (moveindex >= 20000) {
                    exit(EXIT_FAILURE);
                }
                push(stack1, buffer);
            }
        }

        if (isempty(stack1) && isempty(stack2)) {
            break;
        }
    }

    printf("%d", moveindex);

    for (int i = 0; i < moveindex; i++) {
        switch(queue[i]) {
            case 0:
                printf("\n1 2");
                break;
            case 1:
                printf("\n1 3");
                break;
            case 2:
                printf("\n2 3");
                break;
            case 3:
                printf("\n2 1");
                break;
        }
    }

    free(stack1);
    free(stack2);
    free(sortedstack);

    return 0;
}


Stack* createStack(int size) {
    Stack* newstack = (Stack*) malloc(sizeof(Stack));
    if (newstack == NULL) {
        exit(EXIT_FAILURE);
    }

    newstack->size = size;
    newstack->index = -1;
    newstack->arr = (int*) malloc(sizeof(int) * size);

    if (newstack == NULL) {
        exit(EXIT_FAILURE);
    }

    return newstack;
}

int cmpfunc(const void* p, const void* q) {
    return *(int*)p - *(int*)q;
}

void push(Stack* pstack, int value) {
    if (++pstack->index >= pstack->size) {
        exit(EXIT_FAILURE);
    }
    pstack->arr[pstack->index] = value;
}

int pop(Stack* pstack) {
    if(pstack->index < 0) {
        exit(EXIT_FAILURE);
    }
    return pstack->arr[pstack->index--];
}

int top(Stack* pstack) {
    if(pstack->index < 0) {
        exit(EXIT_FAILURE);
    }
    return pstack->arr[pstack->index];
}

bool isempty(Stack *stack) {
    if (stack->index == -1) {
        return true;
    }
    return false;
}
