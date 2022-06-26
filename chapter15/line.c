#include <stdio.h>
#include <string.h>

#include "line.h"

#define MAX_LINE_LEN 60

char g_line[MAX_LINE_LEN + 1];
int g_line_len = 0;
int g_num_words = 0;

void clear_line(void)
{
    g_line[0] = '\0';
    g_line_len = 0;
    g_num_words = 0;
}

void add_word(const char *word)
{
    if (g_num_words > 0) {
        g_line[g_line_len] = ' ';
        g_line[g_line_len+1] = '\0';
        g_line_len++;
    }
    strcat(g_line, word);
    g_line_len += strlen(word);
    g_num_words++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - g_line_len;
}

void write_line(void)
{
    int extra_spaces = MAX_LINE_LEN - g_line_len;
    int space_to_insert = 0;

    for (int i = 0; i < g_line_len; i++) {
        if (g_line[i] != ' ') {
            putchar(g_line[i]);
        } else {
            space_to_insert = extra_spaces / (g_num_words - 1);
            for (int j = 1; j <= space_to_insert + 1; j++) {
                putchar(' ');
            }
            extra_spaces -= space_to_insert;
            g_num_words--;
        }
    }
    putchar('\n');
}

void flush_line(void)
{
    if (g_line_len > 0)
        puts(g_line);
}