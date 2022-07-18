#include <iostream>
#include <string.h>

class string {
    char *str;
    int len;

    public: 
        string(char c, int n);  // 문자 c가 n개 있는 문자열로 정의
        string(const char *s);
        string(const string &s);
        ~string();

        void add_string(const string &s);
        void copy_string(const string &s);
        int str_len();
};

string::string(char c, int n) {
    str = new char[n + 1];
    len = n;
    for (int i = 0; i < n; i++) {
        str[i] = c;
    }
    str[n] = '\0';
}

string::string(const char *s) {
    len = strlen(s);
    str = new char[len + 1];

    strcpy(str, s);
}

string::string(const string &s) {
    len = s.len;
    str = new char[len + 1];

    strcpy(str, s.str);
}

string::~string() {
    if (str) delete[] str;
}

void string::add_string(const string &s) {
    len += s.len;
    realloc(str, sizeof(char) * (len + 1));
    strcat(str, s.str);
}

void string::copy_string(const string &s) {
    len = s.len;
    if (str) delete[] str;
    str = new char[len + 1];
    strcpy(str, s.str);
}

int string::str_len() {
    return len;
}