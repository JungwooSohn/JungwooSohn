/*
1. 
a true
b false, expanded operators need char type, not char* type
c false, it needs string
d true,
e false needed pointer
f true, 
g true
h false, don't need pointer
i false, not pointer
j true
k true

2.
a false, p return pointer
b true
c true
d false it need pointer

3.
12, abc34, 56

4.

8
tired-or-wi00
*/
int read_line(char str[], int size)
{
    int ch;
    int i = 0;

    while ((ch = getchar())!= ' ') {
    }

    str[i++] = ch;

    while ((ch = getchar()) != '\n') {
        if (i < size) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';

    return i;
}

int read_line(char str[], int size)
{
    int ch;
    int i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < size) {
            str[i++] = ch;
        }

        if(isspace(ch)) {
            break;
        }
    }
    str[i] = '\0';

    return i;
}

int read_line(char str[], int size)
{
    int ch;
    int i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < size) {
            str[i++] = ch;
        } else {
            break;
        }
    }

    str[i++] = '\n';
    str[i] = '\0';

    return i;
}



void capitalize(char str[]) {
    int i;
    int size = strlen(str);
    for(i = 0; i < size; ++i) {
        if(isaplha(str[i])) {
            str[i] = toupper(str[i]);
        }

    }
}

void capitalize(char str[]) {
    int i;
    int size = strlen(str);
    char *p;
    for(p = str; p < str + size; ++p) {
        if(isaplha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int strcmp(char* str1, char* str2)
{
    int i;
    int *p, *q;

    for (p = str1, q = str2; *p == *q; ++p, ++q) {
        if (str1[i] == '\0') {
            return 0;
        }
    }
    return *p - *q;
}