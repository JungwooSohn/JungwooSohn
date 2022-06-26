#include <stdbool.h>    /* C99에서만 가능 */
#include <stdio.h>
#include <stdlib.h>


#define STACK_SIZE (100)

/* 외부변수 */
char g_contents[STACK_SIZE];
int g_top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char item);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main() {
    char ch;

    printf("Enter parentheses and/or braces: ");
    for(;;) {
        ch = getchar();
        switch (ch)
        {
        case '(': case '{': case '[':
            push(ch);
            break;
        case ')':
            if (pop() != '(') {
                printf("Parentheses/braces aren't nested properly");
                return 0;
            }
            break;
        case '}':
            if (pop() != '{') {
                printf("Parentheses/braces aren't nested properly");
                return 0;
            }
            break;
        case ']':
            if (pop() != '[') {
                printf("Parentheses/braces aren't nested properly");
                return 0;
            }
            break;
        case '\n':
            if(is_empty) {
                printf("Parentheses/braces are nested properly");
                return 0;
            }
            break;
        default:
            break;
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

void push(char item)
{
    if (is_full()) {
        stack_overflow();
    } else {
        g_contents[g_top++] = item;
    }
}

char pop(void)
{
    if (is_empty()) {
        stack_underflow();
    } else {
        return g_contents[--g_top];
    }
}

void stack_overflow(void) {
    printf("Stack overflow");
    exit(0);
}

void stack_underflow(void) {
    printf("Parentheses/braces aren't nested properly");
    exit(0);
}
