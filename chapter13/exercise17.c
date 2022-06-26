#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool test_extension(const char *file_name, const char *extension);

int main() {

    char exam_file[] = "text.txt";
    char exam_extension[] = "txt";

    printf("%d", test_extension(exam_file, exam_extension));

    return 0;
} 


bool test_extension(const char *file_name, const char *extension) {
    int len = strlen(extension);
    extension += len;
    file_name += strlen(file_name); 

    while(len >= 0) {
        if(toupper(*extension--) != toupper(*file_name--)) {
            return false;
        }
        len--;
    }
    
    if (*file_name == '.') {
        return true;
    }
    return false;

}