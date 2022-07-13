#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef double Element;

typedef struct {
    Element *stack;
    int size;
    int top;
} Stack;

Stack* CreateStack(int size);
void Push(Stack* pStack, Element item);
Element Pop(Stack* pStack);

int main(void) {

    int n = 0, buffer;
    int alpha[26] = {0,};
    int len;

    double temp, temp2;
    char statement[101] = {'\0',};

    scanf("%d", &n);
    scanf("%s", statement);
    for (int i = 0; i < n; i++) {
        scanf("%d", &buffer);
        alpha[i] = buffer;
    }

    Stack* numstack = CreateStack(100);
    len = strlen(statement);

    for (int i = 0; i < len; i++) {
        if (isalpha(statement[i])) {
            Push(numstack, alpha[statement[i] - 'A']);
        } else {
            switch(statement[i]) {
                case '+':
                    temp = Pop(numstack);
                    temp2 = Pop(numstack);
                    Push(numstack, temp2 + temp);
                    break;
                case '-':
                    temp = Pop(numstack);
                    temp2 = Pop(numstack);
                    Push(numstack, temp2 - temp);
                    break;
                case '*':
                    temp = Pop(numstack);
                    temp2 = Pop(numstack);
                    Push(numstack, temp2 * temp);
                    break;
                case '/':
                    temp = Pop(numstack);
                    temp2 = Pop(numstack);
                    Push(numstack, temp2 / temp);
                    break;
                default:
                    break;
            }
        }
    }

    printf("%.2lf", Pop(numstack));

    free(numstack);

    return 0;
}


Stack* CreateStack(int size) {
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    if(pStack == NULL)
        return NULL;
    pStack->stack = (Element *)malloc(size * sizeof(Element));
    if(pStack->stack == NULL){
        free(pStack);
        return NULL;
    }
    pStack->size = size;
    pStack->top = -1;
    return pStack;
}

void Push(Stack* pStack, Element item) {
    // 스택이 가득찼는 지 확인
    if(pStack->top == pStack->size - 1)
        return;
    pStack->stack[++pStack->top] = item;
}


Element Pop(Stack* pStack) {
    // 스택이 비어있는 지 확인
    if(pStack->top < 0)
        return 0;
    return pStack->stack[pStack->top--];
}
