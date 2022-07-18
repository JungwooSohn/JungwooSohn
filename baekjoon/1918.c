#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef int Element;

typedef struct {
    Element *stack;
    int size;
    int top;
} Stack;

Stack* CreateStack(int size);
void Push(Stack* pStack, Element item);
Element Pop(Stack* pStack);
Element Top(Stack* pStack);
int isempty(Stack* pStack);
int getfrequency(int oper);

int main(void) {

    int ch;
    char result[101] = {'\0'};
    int tempoperator;
    int i = 0;

    Stack* operatorstack = CreateStack(100);

    while((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            result[i++] = ch;
        } else {
            switch(ch) {
                case '(':
                    Push(operatorstack, ch);
                    break;
                case ')':
                    while ((tempoperator = Pop(operatorstack)) != '(') {
                        result[i++] = tempoperator;
                    }
                    break;
                case '+': case '-': case '*': case '/':
                    while (!isempty(operatorstack) && getfrequency(ch) <= getfrequency(Top(operatorstack))) {
                        result[i++] = Pop(operatorstack);
                    }
                    Push(operatorstack, ch);
                    break;

            }
        }
    }

    while(!isempty(operatorstack)) {
        result[i++] = Pop(operatorstack);
    }

    printf("%s", result);

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

Element Top(Stack* pStack) {
    if(pStack->top < 0)
    return 0;
    return pStack->stack[pStack->top];
}

int isempty(Stack* pStack) {
    if (pStack->top < 0) {
        return 1;
    } else {
        return 0;
    }
}


int getfrequency(int oper) {
    switch (oper) {
        case '(':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 3;
    }
}