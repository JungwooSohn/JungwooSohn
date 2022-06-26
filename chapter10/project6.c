#include <stdbool.h>    /* C99에서만 가능 */
#include <stdlib.h>
#include <stdio.h>


#define STACK_SIZE (100)

/* 외부변수 */
int g_contents[STACK_SIZE];
int g_top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int item);
int pop(void);
void stack_overflow();
void stack_underflow();


int main() {

    char ch;
    int temp = 1;
    
    for(;;) {
        printf("Enter an RPN expression: ");
        for(;;) {
            scanf(" %c", &ch);
            if (ch >= '0' && ch <= '9') {
                push(ch - '0');
            } else if(ch == '+') {
                push(pop() + pop());
            } else if(ch == '-') {
                temp = pop();
                push(pop() - temp);
            } else if(ch == '*') {
                push(pop() * pop());
            } else if(ch == '/') {
                temp = pop();
                push(pop() / temp);
            } else if(ch == '=') {
                printf("Value of expression: %d\n", pop());
                break;
            } else {
                return 0;
            }
        }

    }
    

    return 0;
}

void make_empty(void)
{
    g_top = 0;
}

bool is_empty(void)
{
    return g_top == 0;
}

bool is_full(void)
{
    return g_top == STACK_SIZE;
}

void push(int item)
{
    if (is_full()) {
        stack_overflow();
    } else {
        g_contents[g_top++] = item;
    }
}

int pop(void)
{
    if (is_empty()) {
        stack_underflow();
    } else {
        return g_contents[--g_top];
    }
}

void stack_overflow() {
    printf("Expression is too complex");
    exit(EXIT_FAILURE);
}

void stack_underflow() {
    printf("Not enough operands in expression");
    exit(EXIT_FAILURE);
}