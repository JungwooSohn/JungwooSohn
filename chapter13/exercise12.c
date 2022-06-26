#include <stdio.h>
#include <string.h>

void get_extension(const char *file_name, char *extension);

int main() {
    
    char file1[] = "text.c";
    char extension[100];

    get_extension(file1, extension);

    printf("%s", extension);

    return 0;
}

void get_extension(const char *file_name, char *extension) {
    const char *p;
    p = file_name + strlen(file_name);
    while(*p-- != '.') {
        if(p == file_name) {
            *extension = '\0';
            return;
        }
    }

    strncpy(extension, p + 2, sizeof(extension));

}